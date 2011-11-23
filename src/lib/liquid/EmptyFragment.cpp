#include "Fragment.hpp"

namespace Liquid
{
    bool EmptyFragment::Compare(Fragment* other,
                                ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
            return false;
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeEmpty:
            return (op == ConditionalEquals);

        case FragmentTypeArray:
            {
                std::size_t arrayCount = reinterpret_cast<ArrayFragment*>(other)->Count();

                if (op == ConditionalEquals)
                    return (arrayCount == 0);
                if (op == ConditionalNotEquals)
                    return (arrayCount > 0);
                return false;
            }
            
        case FragmentTypeString:
            {
                bool stringEmpty = reinterpret_cast<StringFragment*>(other)->GetValue().empty();

                if (op == ConditionalEquals)
                    return stringEmpty;
                if (op == ConditionalNotEquals)
                    return !stringEmpty;
                return false;
            }

        default:
            return (op == ConditionalNotEquals);
        }
    }
}
