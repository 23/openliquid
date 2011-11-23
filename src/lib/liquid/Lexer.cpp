#include <iostream>

#include "Lexer.hpp"
#include "LexerTables.hpp"
#include "Expressions.hpp"

namespace Liquid
{
    bool IsLookAheadTag(LexerContext& context,
                        const char* tagName,
                        int tagNameLength)
    {
        // Save the current position
        LexerPosition start = context.CurrentPosition;

        // Assume that we have a guarantee of the first
        // two characters having been evaluated
        context++;
        context++;

        // Skip whitespaces
        while ((context.Current == ' ') ||
               (context.Current == '\t'))
            context++;

        // Check the tag name
        int tagNameOffset = 0;

        while (tagNameOffset < tagNameLength)
        {
            if (context.Current != tagName[tagNameOffset])
            {
                context.CurrentPosition = start;
                return false;
            }

            context++;
            tagNameOffset++;
        }

        // Skip whitespaces
        while ((context.Current == ' ') ||
               (context.Current == '\t'))
            context++;

        // Check the closing value
        if ((context.Current != '%') ||
            (context.Next != '}'))
        {
            context.CurrentPosition = start;
            return false;
        }

        // Move the context up ahead and mark it
        context++;
        context++;

        context.Mark();

        return true;
    }

    bool Lexer::TryInterpretToken(LexerPosition& start,
                                  LexerPosition& end,
                                  TokenList& tokens,
                                  ParserError& error)
    {
        int tokenType;
        std::string value(start.Data,
                          end.Data - start.Data + 1);

        // Test for special tokens
        if (value == "empty")
            tokenType = TokenEmpty | TokenIdentifier | TokenPath;
        else if ((value == "null") ||
                 (value == "nil"))
            tokenType = TokenNull | TokenIdentifier | TokenPath;
        else if ((value == "true") ||
                 (value == "false"))
            tokenType = TokenBoolean | TokenIdentifier | TokenPath | (value == "true" ? TokenTrue : TokenFalse);
        else if (Expressions::IntegerFragment.FullMatch(value))
            tokenType = TokenInteger;
        else if (Expressions::FloatFragment.FullMatch(value))
            tokenType = TokenFloat;
        else if (Expressions::IdentifierFragment.FullMatch(value))
            tokenType = TokenIdentifier | TokenPath;
        else if (Expressions::ContextualFragment.FullMatch(value))
            tokenType = TokenPath;
        else if (value == "..")
            tokenType = TokenRangeSeparator;
        else
        {
            error.Set(start,
                      end,
                      "unknown literal in block: '" + value + "'");

            return false;
        }

        // Add the token
        tokens.push_back(Token(start,
                               end,
                               tokenType));

        return true;
    }

    bool Lexer::TryParseComment(LexerContext& context,
                                TokenList& tokens,
                                ParserError& error)
    {
        // Iterate
        while (context.Current)
        {
            // Check for opening tags
            if ((context.Current != '{') ||
                (context.Next != '%'))
            {
                context++;
                continue;
            }

            // Check if the tag is an end of a comment
            if (!IsLookAheadTag(context,
                                "endcomment",
                                10))
            {
                context++;
                continue;
            }

            // We're done!
            return true;
        }

        // If we got to this point, we reached the end of the file preemptively
        error.Set(context.MarkPosition,
                  context.CurrentPosition,
                  "unexpected end of source file while looking for ending comment tag");

        return false;
    }

    enum BlockParseState
    {
        StateIdentifier,
        StateOperator,
        StateString
    };

    bool Lexer::TryParseBlock(LexerContext& context,
                              TokenList& tokens,
                              ParserError& error,
                              const char wrapper)
    {
        // * Add the open token

        LexerPosition blockStart = context.CurrentPosition;
        
        // Move the context up ahead one character preemptively
        context++;
        
        // Push an open token
        tokens.push_back(Token(context.MarkPosition,
                               context.CurrentPosition,
                               wrapper == '%' ? TokenTagOpen : TokenOutputOpen));

        context++;

        // * Iterate
        context.Mark();

        // Initialize the string wrapper
        char stringWrapper = 0x00;

        while (context.Current)
        {
            // Tokens are explitcitly delimited by:
            // - whitespaces
            // - operator characters:
            //     = ! & > < % } | : ,

            // Check for delimiting if we're not doing string parsing
            if (((LexerDelimiterTable[(const unsigned char)context.Current]) ||
                 ((context.Current == '.') && (context.Next == '.'))) &&
                (!stringWrapper))
            {
                // Push the previous token
                if (context.MarkPosition != context.CurrentPosition)
                {
                    if (!TryInterpretToken(context.MarkPosition,
                                           context.PreviousPosition,
                                           tokens,
                                           error))
                        return false;
                }

                context.Mark();

                // Check for closing
                if ((context.Current == wrapper) &&
                    (context.Next == '}'))
                {
                    // Push a close token
                    context++;
                    
                    tokens.push_back(Token(context.MarkPosition,
                                           context.CurrentPosition,
                                           wrapper == '%' ? TokenTagClose : TokenOutputClose));
                    
                    // Return
                    context++;
                    context.Mark();
                    
                    return true;
                }

                // Skip white spaces
                if (LexerWhitespaceTable[(const unsigned char)context.Current])
                {
                    context++;
                    context.Mark();
                    
                    continue;
                }

                // Strings
                if (LexerStringWrapperTable[(const unsigned char)context.Current])
                {
                    stringWrapper = context.Current;
                    context++;
                    continue;
                }

                // Operators
                if (LexerOperatorTable[(const unsigned char)context.Current])
                {
                    // Read out the entire operator
                    while (LexerOperatorTable[(const unsigned char)context.Next])
                        context++;

                    // Add the operator as a token
                    tokens.push_back(Token(context.MarkPosition,
                                           context.CurrentPosition,
                                           TokenOperator));

                    // Mark it up!
                    context++;
                    context.Mark();
                    
                    continue;
                }

                // Function delimiters
                if ((context.Current == '|') ||
                    (context.Current == ',') ||
                    (context.Current == ':') ||
                    (context.Current == '(') ||
                    (context.Current == ')'))
                {
                    TokenType tokenType = TokenFilterSeparator;

                    if (context.Current == ',')
                        tokenType = TokenArgumentSeparator;
                    else if (context.Current == ':')
                        tokenType = TokenArgumentDelimiter;
                    else if (context.Current == '(')
                        tokenType = TokenParenthesisOpen;
                    else if (context.Current == ')')
                        tokenType = TokenParenthesisClose;

                    tokens.push_back(Token(context.MarkPosition,
                                           context.CurrentPosition,
                                           tokenType));

                    // Mark it up!
                    context++;
                    context.Mark();
                    
                    continue;
                }

                // Range delimiter
                if ((context.Current == '.') &&
                    (context.Next == '.'))
                {
                    context++;
                    tokens.push_back(Token(context.MarkPosition,
                                           context.CurrentPosition,
                                           TokenRangeSeparator));

                    // Mark it up!
                    context++;
                    context.Mark();

                    continue;
                }

                // Erroneous delimiter
                const char unhandled[2] = { context.Current, 0x00 };

                error.Set(context.CurrentPosition,
                          context.CurrentPosition,
                          std::string("unhandled delimiter character: ") + std::string(unhandled));
                return false;
            }
            else if ((context.Current == stringWrapper) &&
                     (context.Previous != '\\'))
            {
                // End of string
                tokens.push_back(Token(context.MarkPosition,
                                       context.CurrentPosition,
                                       TokenString));

                // Reset the string wrapper
                stringWrapper = 0x00;

                // Move up the marker
                context++;
                context.Mark();
            }
            else
                context++;
        }

        // If we got to this point, we reached the end of the file preemptively
        if (stringWrapper)
            error.Set(context.MarkPosition,
                      context.CurrentPosition,
                      "unexpected end of source file while parsing string");
        else
            error.Set(blockStart,
                      context.CurrentPosition,
                      "unexpected end of source file while parsing block");
        
        return false;
    }

    bool Lexer::TryParseRaw(LexerContext& context,
                            TokenList& tokens,
                            ParserError& error)
    {
        // Iterate
        while (context.Current)
        {
            // Check for opening tags
            if ((context.Current != '{') ||
                (context.Next != '%'))
            {
                context++;
                continue;
            }

            // Store the positions
            LexerPosition start = context.MarkPosition,
                          end = context.PreviousPosition;

            // Check if the tag is an end of a raw
            if (!IsLookAheadTag(context,
                                "endraw",
                                6))
            {
                context++;
                continue;
            }

            // Push back the literal
            tokens.push_back(Token(start,
                                   end,
                                   TokenLiteral));

            // We're done!
            return true;
        }

        // If we got to this point, we reached the end of the file preemptively
        error.Set(context.MarkPosition,
                  context.CurrentPosition,
                  "unexpected end of source file while looking for ending raw tag");

        return false;
    }

    bool Lexer::TryAnalyze(std::string& source,
                           TokenList& tokens,
                           ParserError& error)
    {
        // Reset the state and the offset
        LexerContext context(source.c_str());

        // Iterate through all the characters
        while (context.Current)
        {
            // Check for opening tags
            if ((context.Current != '{') ||
                ((context.Next != '{') &&
                 (context.Next != '%')))
            {
                context++;
                continue;
            }

            // Push back a literal token if necessary
            if (context.MarkPosition != context.CurrentPosition)
            {
                tokens.push_back(Token(context.MarkPosition,
                                       context.PreviousPosition,
                                       TokenLiteral));
                
                // Mark
                context.Mark();
            }
            
            // Handle the different kinds of states
            if (context.Next == '{')
            {
                // Handle output block parsing
                if (!TryParseBlock(context,
                                   tokens,
                                   error,
                                   '}'))
                    return false;
            }
            else
            {
                // Check if the tag matches a raw tag
                if (IsLookAheadTag(context,
                                   "raw",
                                   3))
                {
                    // Handle raw block parsing
                    if (!TryParseRaw(context,
                                     tokens,
                                     error))
                        return false;
                }
                // Check if the tag matches a comment tag
                else if (IsLookAheadTag(context,
                                        "comment",
                                        7))
                {
                    // Handle comment block parsing
                    if (!TryParseComment(context,
                                         tokens,
                                         error))
                        return false;
                }
                // Normal tag
                else
                {
                    // Parse the block
                    if (!TryParseBlock(context,
                                       tokens,
                                       error,
                                       '%'))
                        return false;
                }
            }
        }

        // Push back a literal token if necessary
        if (context.MarkPosition != context.CurrentPosition)
        {
            tokens.push_back(Token(context.MarkPosition,
                                   context.PreviousPosition,
                                   TokenLiteral));
        }

        return true;
    }
}
