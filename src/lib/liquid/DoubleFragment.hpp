#include <stdint.h>
#include <cstdlib>

#include "Convert.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_FLOATFRAGMENT
#define __LIQUID_FLOATFRAGMENT
namespace Liquid
{
    /// Double precision floating point variable
    class FloatFragment
        :   public Fragment
    {
    public:
        /// Initialize a floating point variable

        /// Requires the markup to be pre-validated
        /// @param markup Markup representation of the floating point value
        FloatFragment(std::string markup)
            :   _value(atof(markup.c_str()))
        {
            
        }


        /// Initialize a floating point variable
        FloatFragment(float value)
            :   _value(value)
        {

        }


        /// Initialize a floating point variable
        FloatFragment(double value)
            :   _value(value)
        {

        }
        

        /// Dispose of a variable base class
        virtual ~FloatFragment()
        {

        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeFloat;
        }


        /// Get the value of the string

        /// @returns the value of the string
        double GetValue()
        {
            return this->_value;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return Convert::ToString(this->_value);
        }

        
        /// Compare this fragment to another fragment
        
        /// @param other Other fragment to compare to
        /// @param op Comparator
        /// @returns true if the statement is true, otherwise false
        virtual bool Compare(Fragment* other,
                             ConditionalOperator op);


        /// Clone this fragment

        /// @returns the pointer to a clone of this fragment
        virtual Fragment* Clone()
        {
            return new FloatFragment(this->_value);
        }
    private:
        double _value; ///< Value of the floating point variable
    };
}
#endif
