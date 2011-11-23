#include "Fragment.hpp"

#define TARGET_TCL

namespace Liquid
{
    bool NullFragment::Compare(Fragment* other,
                               ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
            return false;
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeNull:
            return (op == ConditionalEquals);

        default:
            return (op == ConditionalNotEquals);
        }
    }
}
