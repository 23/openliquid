#include <iostream>
#include <string>
#include <vector>
#include <stdint.h>

#include "LexerPosition.hpp"

#ifndef __LIQUID_TOKEN
#define __LIQUID_TOKEN
namespace Liquid
{
    /// Token type

    /// Note that token types are evaluated as bit flags
    /// as a raw value may match numerous token characteristics
    enum TokenType
    {
        TokenString = 0x1,
        TokenInteger = 0x2,
        TokenFloat = 0x4,
        TokenNull = 0x8,
        TokenEmpty = 0x10,
        TokenIdentifier = 0x20,
        TokenPath = 0x40,
        TokenLiteral = 0x80,
        TokenOperator = 0x100,
        TokenTagOpen = 0x200,
        TokenTagClose = 0x400,
        TokenOutputOpen = 0x800,
        TokenOutputClose = 0x1000,
        TokenBoolean = 0x2000,
        TokenTrue = 0x4000,
        TokenFalse = 0x8000,
        TokenFilterSeparator = 0x10000,
        TokenArgumentDelimiter = 0x20000,
        TokenArgumentSeparator = 0x40000,
        TokenParenthesisOpen = 0x80000,
        TokenParenthesisClose = 0x100000,
        TokenRangeSeparator = 0x200000
    };


    /// Token type output representation
    static std::string FormatTokenType(int tokenType)
    {
#define ResultDelimited(x) if (tokenType & x) { result += (result.empty() ? std::string(#x) : std::string(" | " #x)); }

        std::string result;

        ResultDelimited(TokenString);
        ResultDelimited(TokenInteger);
        ResultDelimited(TokenFloat);
        ResultDelimited(TokenNull);
        ResultDelimited(TokenEmpty);
        ResultDelimited(TokenIdentifier);
        ResultDelimited(TokenPath);
        ResultDelimited(TokenLiteral);
        ResultDelimited(TokenOperator);
        ResultDelimited(TokenTagOpen);
        ResultDelimited(TokenTagClose);
        ResultDelimited(TokenOutputOpen);
        ResultDelimited(TokenOutputClose);
        ResultDelimited(TokenBoolean);
        ResultDelimited(TokenTrue);
        ResultDelimited(TokenFalse);
        ResultDelimited(TokenFilterSeparator);
        ResultDelimited(TokenArgumentDelimiter);
        ResultDelimited(TokenArgumentSeparator);
        ResultDelimited(TokenParenthesisOpen);
        ResultDelimited(TokenParenthesisClose);
        ResultDelimited(TokenRangeSeparator);

#undef ResultDelimited

        return result;
    }

    
    /// Token within a specific source code context

    /// Represented by a raw string value and line/character number span
    class Token
    {
    public:
        /// Raw string value of the token
        std::string Value;
        
        /// Line on which the token begins
        uint32_t LineBegin;

        /// Line on which the token ends
        uint32_t LineEnd;
        
        /// Character on the begining line where the token begins
        uint32_t CharacterBegin;

        /// Character on the ending line where the token ends
        uint32_t CharacterEnd;

        /// Token type
        int Type;

        
        /// Initialize a token
        
        /// @param value Raw string value
        /// @param tokenType Token type
        /// @param lineBegin Line on which the token begins
        /// @param lineEnd Line on which the token ends
        /// @param characterBegin Character at which the token begins
        /// @param characterEnd Character at which the token ends
        Token(std::string value,
              int tokenType,
              uint32_t lineBegin,
              uint32_t lineEnd,
              uint32_t characterBegin,
              uint32_t characterEnd)
            :   Value(value),
                LineBegin(lineBegin),
                LineEnd(lineEnd),
                CharacterBegin(characterBegin),
                CharacterEnd(characterEnd),
                Type(tokenType)
        {
            
        }


        /// Initialize a token from two lexer positions

        /// @param start Starting position
        /// @param end Ending position
        /// @param tokenType Token type
        Token(LexerPosition& start,
              LexerPosition& end,
              int tokenType)
            :   Value(start.Data,
                      end.Data - start.Data + 1),
                LineBegin(start.Line),
                LineEnd(end.Line),
                CharacterBegin(start.Character),
                CharacterEnd(end.Character),
                Type(tokenType)
        {
            
        }


        /// Represent the token in a debug format
        
        /// @returns a debug string representation of the token
        std::string ToString()
        {
            return FormatTokenType(this->Type) + ": " + this->Value;
        }
    };


    /// List of tokens
    typedef std::vector<Token> TokenList;
}
#endif
