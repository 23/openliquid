#include <string>
#include <stdint.h>
#include <limits>

#include "LexerPosition.hpp"
#include "Token.hpp"

#ifndef __LIQUID_PARSER_ERROR
#define __LIQUID_PARSER_ERROR
namespace Liquid
{
#define LineCharacterNone (std::numeric_limits<uint32_t>::max())

    class ParserError
    {
    public:
        /// Filename where the parse error occurred
        std::string Filename;
        

        /// Starting line on which the parser error occured
        uint32_t LineBegin;
        

        /// Ending line on which the parser error occured
        uint32_t LineEnd;
        

        /// Character on the begining line where the error occured
        uint32_t CharacterBegin;

        
        /// Character on the ending line where the error occured
        uint32_t CharacterEnd;
        

        /// Error description

        /// Should always start with a lower case character
        std::string Description;


        /// Initialize a new parser error structure
        ParserError()
            :   LineBegin(LineCharacterNone),
                LineEnd(LineCharacterNone),
                CharacterBegin(LineCharacterNone),
                CharacterEnd(LineCharacterNone)
        {

        }


        /// Easily set the error from a lexer

        /// @param start Starting lexical position
        /// @param end Ending lexical position
        /// @param description Error description
        void Set(LexerPosition& start,
                 LexerPosition& end,
                 std::string description)
        {
            this->LineBegin = start.Line;
            this->LineEnd = end.Line;

            this->CharacterBegin = start.Character;
            this->CharacterEnd = end.Character;

            this->Description = description;
        }


        /// Easily set the error from a node

        /// @param token Token causing the error
        /// @param description Error description
        /// @returns false to make it easier to throw it back
        bool Set(Token* token,
                 std::string description)
        {
            if (token != NULL)
            {
                this->LineBegin = token->LineBegin;
                this->LineEnd = token->LineEnd;
                
                this->CharacterBegin = token->CharacterBegin;
                this->CharacterEnd = token->CharacterEnd;
            }

            this->Description = description;

            return false;
        }


        /// Stream representation of the error

        /// @param stream Stream to output the representation to
        /// @param error Error to represent
        /// @returns a reference to the stream
        friend std::ostream& operator <<(std::ostream& stream, ParserError& error)
        {
            stream << "Error";

            // Filename
            if (!error.Filename.empty())
                stream << " in " << error.Filename;
            
            // Position
            if (error.LineBegin == LineCharacterNone)
            {
                
            }
            else if (error.LineBegin == error.LineEnd)
            {
                stream << " at " << error.LineBegin << ":" << error.CharacterBegin;

                if (error.CharacterBegin < error.CharacterEnd)
                    stream << "-" << error.CharacterEnd;
            }
            else
            {
                stream << " at " << error.LineBegin << ":" << error.CharacterBegin << " - " <<
                    error.LineEnd << ":" << error.CharacterEnd;
            }

            stream << ": " << error.Description;

            return stream;
        }
    };
#undef LineCharacterNone
}
#endif
