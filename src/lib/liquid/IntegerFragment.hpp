#include <stdint.h>

#include "Convert.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_INTEGERFRAGMENT
#define __LIQUID_INTEGERFRAGMENT
namespace Liquid
{
    /// Integer variable
    class IntegerFragment
        :   public Fragment
    {
    public:
        /// Initialize an integer variable

        /// Requires the markup to be pre-validated
        /// @param markup Markup representation of the integer value
        IntegerFragment(std::string markup)
            :   _value(strtoull(markup.c_str(),
                                NULL,
                                10))
        {
            
        }


        /// Initialize an integer variable
        IntegerFragment(int64_t value)
            :   _value(value)
        {

        }


        /// Dispose of a variable base class
        virtual ~IntegerFragment()
        {

        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeInteger;
        }


        /// Get the value of the integer

        /// @returns the value of the integer
        int64_t GetValue()
        {
            return this->_value;
        }


        /// Set the value of the integer

        /// @param value The value to assign
        void SetValue(int64_t value)
        {
            this->_value = value;
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
            return new IntegerFragment(this->_value);
        }
    private:
        int64_t _value; ///< Value of the string
    };
}
#endif
