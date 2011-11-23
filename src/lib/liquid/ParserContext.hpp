#include "Token.hpp"
#include "ParserError.hpp"
#include "Strainer.hpp"

#ifndef __LIQUID_PARSERCONTEXT
#define __LIQUID_PARSERCONTEXT
namespace Liquid
{
    /// Parsing context
    class ParserContext
    {
    public:
        /// List of tokens to be parsed
        TokenList& Tokens;


        /// Strainer
        Strainer& Strain;


        /// Parser error reference
        ParserError& Error;


        /// Initialize a new parsing context

        /// @param tokens List of tokens to be parsed
        /// @param strain Strainer
        /// @param error Reference to the parser error
        ParserContext(TokenList& tokens,
                      Strainer& strain,
                      ParserError& error)
            :   Tokens(tokens),
                Strain(strain),
                Error(error),
                _position(0)
        {
            
        }


        /// Try to get the next token without moving up the position

        /// @param token Reference to the pointer to hold the token
        /// @returns true if a token was found and assigned, otherwise false
        bool TryPeekNext(Token*& token)
        {
            if (this->_position == this->Tokens.size())
                return false;

            token = &this->Tokens[this->_position];
            return true;
        }


        /// Try to get the next token

        /// @param token Reference to the pointer to hold the token
        /// @returns true if a token was found and assigned, otherwise false
        bool TryNext(Token*& token)
        {
            if (this->_position == this->Tokens.size())
                return false;

            token = &this->Tokens[this->_position++];

            return true;
        }
    private:
        std::size_t _position; ///< Current position in the token list
    };
}
#endif
