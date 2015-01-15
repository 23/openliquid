#include "Fragment.hpp"

#define TARGET_TCL

namespace Liquid
{
    bool StringFragment::Compare(Fragment* other,
                                 ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
        {
#ifdef TARGET_TCL
            if (this->_value == "t")
                return true;
            else if (this->_value == "f")
                return false;
#endif
            return (!this->_value.empty());
        }
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeBoolean:
            {
#ifdef TARGET_TCL
                bool booleanValue = reinterpret_cast<BooleanFragment*>(other)->GetValue();

                if (this->_value == "t")
                {
                    if (op == ConditionalEquals)
                        return booleanValue;
                    if (op == ConditionalNotEquals)
                        return !booleanValue;
                }
                else if (this->_value == "f")
                {
                    if (op == ConditionalEquals)
                        return !booleanValue;
                    if (op == ConditionalNotEquals)
                        return booleanValue;
                }
#endif
                
                break;
            }

        case FragmentTypeEmpty:
            if (op == ConditionalEquals)
                return this->_value.empty();
            if (op == ConditionalNotEquals)
                return !this->_value.empty();
            return false;
            
        case FragmentTypeString:
            {
                int comparison = this->_value.compare(reinterpret_cast<StringFragment*>(other)->_value);
                
                switch (op)
                {
                case ConditionalEquals:
                    return (comparison == 0);
                    
                case ConditionalNotEquals:
                    return (comparison != 0);
                    
                case ConditionalGreaterThan:
                    return (comparison > 0);
                    
                case ConditionalLessThan:
                    return (comparison < 0);
                    
                case ConditionalGreaterThanOrEquals:
                    return (comparison >= 0);
                    
                case ConditionalLessThanOrEquals:
                    return (comparison <= 0);
                    
                default:
                    return false;
                }
            }

        default:
            break;
        }

        return (op == ConditionalNotEquals);
    }

    std::string StringFragment::ToDebugString()
    {
        std::stringstream ss;
        ss << "string(" << _value << ")";
        return ss.str();
    }
}
