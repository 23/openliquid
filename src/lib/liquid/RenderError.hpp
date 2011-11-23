#include <string>
#include <stdint.h>
#include <limits>

#include "LexerPosition.hpp"
#include "Token.hpp"

#ifndef __LIQUID_RENDERERROR
#define __LIQUID_RENDERERROR
namespace Liquid
{
#define LineCharacterNone (std::numeric_limits<uint32_t>::max())

    class RenderError
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
        RenderError()
            :   LineBegin(LineCharacterNone),
                LineEnd(LineCharacterNone),
                CharacterBegin(LineCharacterNone),
                CharacterEnd(LineCharacterNone)
        {

        }


        /// Stream representation of the error

        /// @param stream Stream to output the representation to
        /// @param error Error to represent
        /// @returns a reference to the stream
        friend std::ostream& operator <<(std::ostream& stream, RenderError& error)
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
