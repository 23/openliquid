#include <string>

#include "DoubleVariable.hpp"
#include "EmptyVariable.hpp"
#include "IntegerVariable.hpp"
#include "NullVariable.hpp"
#include "StringVariable.hpp"

#ifndef __LIQUID_VARIABLE
#define __LIQUID_VARIABLE
namespace Liquid
{
    /// Representation of actual variable
    class Variable
    {
    public:
        Variable(std::string markup);
        ~Variable();

    private:
        BaseFragment* _root; ///< Root fragment
    };
}
#endif
