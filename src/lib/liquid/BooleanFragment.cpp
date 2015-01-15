#include "Fragment.hpp"

#define TARGET_TCL

namespace Liquid
{
    bool BooleanFragment::Compare(Fragment* other,
                                  ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
            return this->_value;

        // We can only evaluate equality and non-equality for booleans
        if ((op != ConditionalEquals) &&
            (op != ConditionalNotEquals))
            return false;
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeBoolean:
            {
                bool booleanValue = reinterpret_cast<BooleanFragment*>(other)->GetValue();
                
                return (op == ConditionalEquals ?
                        booleanValue == this->_value :
                        booleanValue != this->_value);
            }

        case FragmentTypeFloat:
            {
                double floatValue = reinterpret_cast<FloatFragment*>(other)->GetValue();
                bool booleanValue = (floatValue > 0.0);

                return (op == ConditionalEquals ?
                        booleanValue == this->_value :
                        booleanValue != this->_value);
            }

        case FragmentTypeInteger:
            {
                int64_t integerValue = reinterpret_cast<IntegerFragment*>(other)->GetValue();
                bool booleanValue = (integerValue > 0.0);

                return (op == ConditionalEquals ?
                        booleanValue == this->_value :
                        booleanValue != this->_value);
            }

        case FragmentTypeString:
            {
#ifdef TARGET_TCL
                std::string stringValue = reinterpret_cast<StringFragment*>(other)->GetValue();

                if (stringValue == "t")
                    return (op == ConditionalEquals ?
                            this->_value :
                            !this->_value);
                else if (stringValue == "f")
                    return (op == ConditionalEquals ?
                            !this->_value :
                            this->_value);
#endif
                break;
            }

        default:
            break;
        }

        return (op == ConditionalNotEquals);
    }

    std::string BooleanFragment::ToDebugString()
    {
        std::stringstream ss;
        ss << "bool(" << (_value ? "true" : "false") << ")";
        return ss.str();
    }
}
