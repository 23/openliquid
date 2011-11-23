#include "BaseFragment.hpp"

#ifndef __LIQUID_EMPTYFRAGMENT
#define __LIQUID_EMPTYFRAGMENT
namespace Liquid
{
    /// Empty variable
    class EmptyFragment
        :   public Fragment
    {
    public:
        /// Initialize an empty variable
        EmptyFragment()
        {

        }


        /// Dispose of an empty variable
        virtual ~EmptyFragment()
        {

        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeEmpty;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return std::string();
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
            return new EmptyFragment();
        }
    };
}
#endif
