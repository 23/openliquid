#include "BaseFragment.hpp"

#ifndef __LIQUID_BOOLEANFRAGMENT
#define __LIQUID_BOOLEANFRAGMENT
namespace Liquid
{
    /// Boolean fragment
    class BooleanFragment
        :   public Fragment
    {
    public:
        /// Initialize a boolean variable
        BooleanFragment(bool value)
            :   _value(value)
        {

        }


        /// Dispose of a variable base class
        virtual ~BooleanFragment()
        {

        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeBoolean;
        }


        /// Get the value of the boolean

        /// @returns the value of the boolean
        bool GetValue()
        {
            return this->_value;
        }


        /// Set the value of the boolean
        
        /// @param value New value of the boolean
        void SetValue(bool value)
        {
            this->_value = value;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return (this->_value ?
                    std::string("true") :
                    std::string("false"));
        }

        
        /// Compare this fragment to another fragment
        
        /// @param other Other fragment to compare to
        /// @param comparator Comparator
        /// @returns true if the statement is true, otherwise false
        virtual bool Compare(Fragment* other,
                             ConditionalOperator op);
        
        
        /// Clone this fragment
        
        /// @returns the pointer to a clone of this fragment
        virtual Fragment* Clone()
        {
            return new BooleanFragment(this->_value);
        }
    private:
        bool _value; ///< Value of the string
    };
}
#endif
