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

    std::string ArrayFragment::ToDebugString()
    {
        std::stringstream ss;
        ss << "[";

        bool first = true;

        for (std::size_t i = 0; i < _array.size(); ++i)
        {
            if (!_array[i])
                continue;

            if (first)
                first = false;
            else
                ss << ", ";

            ss << _array[i]->ToDebugString();
        }

        ss << "]";
        return ss.str();
    }
}
