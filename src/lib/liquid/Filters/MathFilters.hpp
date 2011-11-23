#include "FilterBase.hpp"

#ifndef __LIQUID_FILTERS_MATHFILTERS
#define __LIQUID_FILTERS_MATHFILTERS
namespace Liquid
{
    namespace StandardFilters
    {
        /// plus(input, operand)
        
        /// As per http://wiki.shopify.com/Plus
        static Fragment* Plus(Fragment* input,
                              std::vector<Fragment*>& arguments)
        {
            // Check for arguments
            if ((arguments.size() < 1) ||
                ((input->GetType() != FragmentTypeInteger) &&
                 (input->GetType() != FragmentTypeFloat)) ||
                ((arguments[0]->GetType() != FragmentTypeInteger) &&
                 (arguments[0]->GetType() != FragmentTypeFloat)))
                return new NullFragment();

            Fragment* operand = arguments[0];
            
            FragmentType inputType = input->GetType(),
                         operandType = operand->GetType();

            // Handle depending on input type
            if ((inputType == FragmentTypeInteger) &&
                (operandType == FragmentTypeInteger))
                return new IntegerFragment(reinterpret_cast<IntegerFragment*>(input)->GetValue() +
                                           reinterpret_cast<IntegerFragment*>(operand)->GetValue());

            double a = (inputType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(input)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(input)->GetValue()),
                   b = (operandType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(operand)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(operand)->GetValue());

            return new FloatFragment(a + b);
        }


        /// minus(input, operand)
        
        /// As per http://wiki.shopify.com/Minus
        static Fragment* Minus(Fragment* input,
                               std::vector<Fragment*>& arguments)
        {
            // Check for arguments
            if ((arguments.size() < 1) ||
                ((input->GetType() != FragmentTypeInteger) &&
                 (input->GetType() != FragmentTypeFloat)) ||
                ((arguments[0]->GetType() != FragmentTypeInteger) &&
                 (arguments[0]->GetType() != FragmentTypeFloat)))
                return new NullFragment();

            Fragment* operand = arguments[0];
            
            FragmentType inputType = input->GetType(),
                         operandType = operand->GetType();

            // Handle depending on input type
            if ((inputType == FragmentTypeInteger) &&
                (operandType == FragmentTypeInteger))
                return new IntegerFragment(reinterpret_cast<IntegerFragment*>(input)->GetValue() -
                                           reinterpret_cast<IntegerFragment*>(operand)->GetValue());

            double a = (inputType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(input)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(input)->GetValue()),
                   b = (operandType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(operand)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(operand)->GetValue());

            return new FloatFragment(a - b);
        }


        /// divided_by(input, operand)
        
        /// As per http://wiki.shopify.com/Divided_by
        static Fragment* DividedBy(Fragment* input,
                                   std::vector<Fragment*>& arguments)
        {
            // Check for arguments
            if ((arguments.size() < 1) ||
                ((input->GetType() != FragmentTypeInteger) &&
                 (input->GetType() != FragmentTypeFloat)) ||
                ((arguments[0]->GetType() != FragmentTypeInteger) &&
                 (arguments[0]->GetType() != FragmentTypeFloat)))
                return new NullFragment();

            Fragment* operand = arguments[0];
            
            FragmentType inputType = input->GetType(),
                         operandType = operand->GetType();

            // Handle depending on input type
            if ((inputType == FragmentTypeInteger) &&
                (operandType == FragmentTypeInteger))
            {
                int64_t a = reinterpret_cast<IntegerFragment*>(input)->GetValue(),
                        b = reinterpret_cast<IntegerFragment*>(operand)->GetValue();
                return new IntegerFragment(b == 0 ? 0 : a / b);
            }

            double a = (inputType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(input)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(input)->GetValue()),
                   b = (operandType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(operand)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(operand)->GetValue());

            return new FloatFragment(b == 0 ? 0 : a / b);
        }


        /// times(input, operand)
        
        /// As per http://wiki.shopify.com/Times
        static Fragment* Times(Fragment* input,
                               std::vector<Fragment*>& arguments)
        {
            // Check for arguments
            if ((arguments.size() < 1) ||
                ((input->GetType() != FragmentTypeInteger) &&
                 (input->GetType() != FragmentTypeFloat) &&
                 (input->GetType() != FragmentTypeString)) ||
                ((arguments[0]->GetType() != FragmentTypeInteger) &&
                 (arguments[0]->GetType() != FragmentTypeFloat)))
                return new NullFragment();

            Fragment* operand = arguments[0];
            
            FragmentType inputType = input->GetType(),
                         operandType = operand->GetType();

            // String multiplication
            if (inputType == FragmentTypeString)
            {
                if (operandType == FragmentTypeInteger)
                {
                    std::string inputString = reinterpret_cast<StringFragment*>(input)->GetValue(),
                                result;

                    int64_t times = reinterpret_cast<IntegerFragment*>(operand)->GetValue(),
                            current = 0;

                    while (current < times)
                    {
                        result += inputString;

                        current++;
                    }

                    return new StringFragment(result);                    
                }
                else
                    return new NullFragment();
            }

            // Number multiplication
            if ((inputType == FragmentTypeInteger) &&
                (operandType == FragmentTypeInteger))
                return new IntegerFragment(reinterpret_cast<IntegerFragment*>(input)->GetValue() *
                                           reinterpret_cast<IntegerFragment*>(operand)->GetValue());

            double a = (inputType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(input)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(input)->GetValue()),
                   b = (operandType == FragmentTypeInteger ?
                        double(reinterpret_cast<IntegerFragment*>(operand)->GetValue()) :
                        reinterpret_cast<FloatFragment*>(operand)->GetValue());

            return new FloatFragment(a * b);
        }
    }
}
#endif
