#include <iostream>

#include "Token.hpp"
#include "ParserError.hpp"
#include "LexerPosition.hpp"

#ifndef __LIQUID_LEXER
#define __LIQUID_LEXER
namespace Liquid
{
    /// Lexical analysis context

    /// Handles positional state and supports forward
    /// going movements as well as position resets through
    /// reassignment of CurrentPosition
    class LexerContext
    {
    public:
        /// Character at the current position

        /// NULL at the end of the stream
        char Current;


        /// Character at the previous position

        /// Initialized as NULL
        char Previous;

        
        /// Character at the next position
        char Next;


        /// Current position
        LexerPosition CurrentPosition;


        /// Previous position
        LexerPosition PreviousPosition;


        /// Reference mark position

        /// Used for easily tokenizing longer pieces of data
        /// by using the span of MarkPosition -> (Previous)Position
        LexerPosition MarkPosition;


        /// Initialize a new context

        /// @param data Pointer to the data stream in a NULL-terminated fashion
        LexerContext(const char* data)
            :   Current(*data),
                Previous(0x00),
                Next(*(data + 1)),
                CurrentPosition(data),
                PreviousPosition(data),
                MarkPosition(data)
        {
            
        }


        /// Mark the current position as the reference position
        void Mark()
        {
            this->MarkPosition = this->CurrentPosition;
        }


        /// Move the context up ahead one character
        LexerContext& operator ++(int)
        {
            // Store previous data
            this->PreviousPosition = this->CurrentPosition;
            this->Previous = this->Current;

            // Move up the current position
            this->CurrentPosition++;

            // Update the lookahead
            this->Current = *(this->CurrentPosition.Data);
            this->Next = (this->Current == 0x00 ?
                          0x00 :
                          *(this->CurrentPosition.Data + 1));

            return *this;
        }
    };


    /// Static class for lexical analysis/tokenization of Liquid source code
    class Lexer
    {
    public:
        /// Try to perform lexical analysis of the given source code

        /// @param source Source code to analyze
        /// @param tokens Reference to list of tokens to be populated
        /// @param error Parser error to hold errors
        /// @returns true if the analysis suceeeded, otherwise false
        static bool TryAnalyze(std::string& source,
                               TokenList& tokens,
                               ParserError& error);
    private:
        /// Private, inaccessible constructor
        Lexer() { throw; }


        /// Private, inaccessible assignment constructor
        Lexer(const Lexer&) { throw; }


        /// Try to parse through a comment block
        
        /// @param context Lexical analysis context
        /// @param tokens Reference to list of tokens to be populated
        /// @param error Parser error to hold errors
        /// @returns true if parsing succeeded, otherwise false
        static bool TryParseComment(LexerContext& context,
                                    TokenList& tokens,
                                    ParserError& error);

        
        /// Try to parse through a raw block

        /// @param context Lexical analysis context
        /// @param tokens Reference to list of tokens to be populated
        /// @param error Parser error to hold errors
        /// @returns true if parsing succeeded, otherwise false
        static bool TryParseRaw(LexerContext& context,
                                TokenList& tokens,
                                ParserError& error);


        /// Try to parse through an ambigious block

        /// @param context Lexical analysis context
        /// @param tokens Reference to list of tokens to be populated
        /// @param error Parser error to hold errors
        /// @returns true if parsing succeeded, otherwise false
        static bool TryParseBlock(LexerContext& context,
                                  TokenList& tokens,
                                  ParserError& error,
                                  const char wrapper);



        /// Try to interpret an ambigious token
        
        /// Pushes the token to the token list if successful.
        /// 
        /// @param start Starting position
        /// @param end Ending position
        /// @param tokens Reference to list of tokens to be populated
        /// @param error Parser error to hold errors
        /// @returns true if parsing succeeded, otherwise false
        static inline bool TryInterpretToken(LexerPosition& start,
                                             LexerPosition& end,
                                             TokenList& tokens,
                                             ParserError& error);
    };
}
#endif
