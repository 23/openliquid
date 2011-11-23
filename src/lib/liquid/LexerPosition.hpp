#include <stdint.h>
#include <iostream>

#ifndef __LIQUID_LEXERPOSITION
#define __LIQUID_LEXERPOSITION
namespace Liquid
{
    /// Utility class for position in the lexical analyzer
    struct LexerPosition
    {
        /// Current line number
        uint32_t Line;


        /// Current character offset in line
        uint32_t Character;
        

        /// Current data offset in data stream
        const char* Data;


        /// Initialize a new lexer position instance

        /// @param data Data offset
        /// @param line Initial line offset
        /// @param character Initial character offset
        LexerPosition(const char* data,
                      uint32_t line = 1,
                      uint32_t character = 1)
            :   Line(line),
                Character(character),
                Data(data)
        {

        }

        
        /// Assignment operator overload

        /// @param from Lexer position to assign from
        /// @returns a reference to this position instance
        LexerPosition& operator =(const LexerPosition& from)
        {
            this->Line = from.Line;
            this->Character = from.Character;
            this->Data = from.Data;
            
            return *this;
        }


        /// Stream representation of the position

        /// @param stream Stream to output the representation to
        /// @param position Position to represent
        /// @returns a reference to the stream
        friend std::ostream& operator <<(std::ostream& stream, LexerPosition& position)
        {
            stream << position.Line << ":" << position.Character << " @ " << (void*)position.Data;
            return stream;
        }


        /// Increment operator overload

        /// Moves the stream up ahead one character and handles
        /// occurances of new lines.
        /// 
        /// @returns a reference to this position instance
        LexerPosition& operator ++(int)
        {
            // Handle new lines
            if (*(this->Data) == '\n')
            {
                this->Line++;
                this->Character = 0;
            }

            // Move up the character by one
            this->Character++;
            this->Data++;

            return *this;
        }

        
        /// Equality operator overload
        bool operator ==(const LexerPosition& other)
        {
            return (this->Data == other.Data);
        }

        
        /// Inequality operator overload
        bool operator !=(const LexerPosition& other)
        {
            return (this->Data != other.Data);
        }
    };
}
#endif
