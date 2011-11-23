#include "Fragment.hpp"

namespace Liquid
{
    bool ArrayFragment::Compare(Fragment* other,
                                ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
            return true;
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeEmpty:
            if (op == ConditionalEquals)
                return this->_array.empty();
            if (op == ConditionalNotEquals)
                return !this->_array.empty();
            return false;

        case FragmentTypeArray:
            if (op == ConditionalEquals)
                return (other == this);
            if (op == ConditionalNotEquals)
                return (other != this);
            return false;

        default:
            return (op == ConditionalNotEquals);
        }
    }
}
