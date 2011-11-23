#include "BaseFragment.hpp"

#ifndef __LIQUID_NULLFRAGMENT
#define __LIQUID_NULLFRAGMENT
namespace Liquid
{
    /// Nil variable
    class NullFragment
        :   public Fragment
    {
    public:
        /// Initialize a nil variable
        NullFragment()
        {

        }


        /// Dispose of a nil variable
        virtual ~NullFragment()
        {

        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeNull;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return std::string();
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
            return new NullFragment();
        }
    };
}
#endif
