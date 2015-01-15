#include "Fragment.hpp"

namespace Liquid
{
    bool IntegerFragment::Compare(Fragment* other,
                                 ConditionalOperator op)
    {
        // Implicit value handling
        if (op == ConditionalImplicit)
            return this->_value;

        // Value handling based on RHS
        switch (other->GetType())
        {
        case FragmentTypeBoolean:
            {
                bool booleanValue = reinterpret_cast<BooleanFragment*>(other)->GetValue();

                switch (op)
                {
                case ConditionalEquals:
                    return (this->_value <= 0 ?
                            !booleanValue :
                            booleanValue);
                    
                case ConditionalNotEquals:
                    return (this->_value <= 0 ?
                            booleanValue :
                            !booleanValue);

                default:
                    return false;
                }
                
                break;
            }

        case FragmentTypeFloat:
            {
                double a = double(this->_value),
                       b = reinterpret_cast<FloatFragment*>(other)->GetValue();

                switch (op)
                {
                case ConditionalEquals:
                    return (a == b);
                    
                case ConditionalNotEquals:
                    return (a != b);
                    
                case ConditionalGreaterThan:
                    return (a > b);
                    
                case ConditionalLessThan:
                    return (a < b);
                    
                case ConditionalGreaterThanOrEquals:
                    return (a >= b);
                    
                case ConditionalLessThanOrEquals:
                    return (a <= b);

                default:
                    return false;
                }
                
                break;
            }
            
        case FragmentTypeInteger:
            {
                int64_t integerValue = reinterpret_cast<IntegerFragment*>(other)->GetValue();

                switch (op)
                {
                case ConditionalEquals:
                    return (integerValue == this->_value);
                    
                case ConditionalNotEquals:
                    return (this->_value != integerValue);
                    
                case ConditionalGreaterThan:
                    return (this->_value > integerValue);
                    
                case ConditionalLessThan:
                    return (this->_value < integerValue);
                    
                case ConditionalGreaterThanOrEquals:
                    return (this->_value >= integerValue);
                    
                case ConditionalLessThanOrEquals:
                    return (this->_value <= integerValue);

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

    std::string IntegerFragment::ToDebugString()
    {
        std::stringstream ss;
        ss << "integer(" << _value << ")";
        return ss.str();
    }
}
