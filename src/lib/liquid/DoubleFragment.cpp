#include "Fragment.hpp"

namespace Liquid
{
    bool FloatFragment::Compare(Fragment* other,
                                ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
            return (this->_value != 0.0);
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeBoolean:
            {
                bool thisBooleanValue = (this->_value > 0.0);
                bool booleanValue = reinterpret_cast<BooleanFragment*>(other)->GetValue();

                if (op == ConditionalEquals)
                    return thisBooleanValue == booleanValue;
                if (op == ConditionalNotEquals)
                    return thisBooleanValue != booleanValue;

                return false;
            }

        case FragmentTypeFloat:
        case FragmentTypeInteger:
            {
                double floatValue = (other->GetType() == FragmentTypeInteger ?
                                     double(reinterpret_cast<IntegerFragment*>(other)->GetValue()) :
                                     reinterpret_cast<FloatFragment*>(other)->GetValue());

                switch (op)
                {
                case ConditionalEquals:
                    return (floatValue == this->_value);
                    
                case ConditionalNotEquals:
                    return (this->_value != floatValue);
                    
                case ConditionalGreaterThan:
                    return (this->_value > floatValue);
                    
                case ConditionalLessThan:
                    return (this->_value < floatValue);
                    
                case ConditionalGreaterThanOrEquals:
                    return (this->_value >= floatValue);
                    
                case ConditionalLessThanOrEquals:
                    return (this->_value <= floatValue);

                default:
                    return false;
                }
                
                break;
            }

        default:
            break;
        }

        return (op == ConditionalNotEquals);
    }

    std::string FloatFragment::ToDebugString()
    {
        std::stringstream ss;
        ss << "float(" << Convert::ToString(_value) << ")";
        return ss.str();
    }
}
