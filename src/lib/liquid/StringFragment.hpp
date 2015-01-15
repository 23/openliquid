#include "BaseFragment.hpp"

#ifndef __LIQUID_STRINGFRAGMENT
#define __LIQUID_STRINGFRAGMENT
namespace Liquid
{
    /// String variable
    class StringFragment
        :   public Fragment
    {
    public:
        /// Initialize a string variable
        StringFragment(std::string value)
            :   _value(value)
        {

        }


        /// Dispose of a variable base class
        virtual ~StringFragment()
        {

        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeString;
        }


        /// Get the value of the string

        /// @returns the value of the string
        std::string GetValue()
        {
            return this->_value;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return this->_value;
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
            return new StringFragment(this->_value);
        }


        virtual std::string ToDebugString();
    private:
        std::string _value; ///< Value of the string
    };
}
#endif
