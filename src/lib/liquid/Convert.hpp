#include <iostream>
#include <sstream>

#ifndef __LIQUID_CONVERT
#define __LIQUID_CONVERT
namespace Liquid
{
    namespace Convert
    {
        /// Convert an arbitrary value to a string

        /// Utilizes the default C++ string stream approach to
        /// generate the appropriate string representation.
        /// 
        /// @param value Value of type T to be represented as a string
        /// @returns a string representation of the value
        template<typename T>
        std::string ToString(T& value)
        {
            std::stringstream stream;

            stream << value;

            return stream.str();
        }
    }
}
#endif
