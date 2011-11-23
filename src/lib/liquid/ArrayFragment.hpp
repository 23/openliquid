#include <vector>

#include "BaseFragment.hpp"

#ifndef __LIQUID_ARRAYFRAGMENT
#define __LIQUID_ARRAYFRAGMENT
namespace Liquid
{
    /// Array
    class ArrayFragment
        :   public Fragment
    {
    public:
        /// Create an empty array
        ArrayFragment()
        {

        }


        /// Dispose of an array
        virtual ~ArrayFragment()
        {
            std::size_t index = this->_array.size();
            
            while (index--)
            {
                if (this->_array[index] != NULL)
                    delete this->_array[index];
            }
        }
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeArray;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return std::string();
        }
        
        
        /// Get the entry at a specific index
        
        /// @param index Index
        /// @returns the pointer to the fragment at the given index, otherwise NULL
        Fragment* Get(std::size_t index)
        {
            return (this->_array.size() <= index ?
                    NULL :
                    this->_array[index]);
        }


        /// Add an entry to the array

        /// @param value Fragment to add to the array
        void Add(Fragment* value)
        {
            this->_array.push_back(value);
        }


        /// Get the number of entries in the array

        /// @returns the number of entries in the array
        std::size_t Count()
        {
            return this->_array.size();
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
            ArrayFragment* result = new ArrayFragment();

            std::size_t index = 0;
            while (index < this->_array.size())
            {
                result->Add(this->_array[index] == NULL ?
                            NULL :
                            this->_array[index]->Clone());
                
                index++;
            }

            return result;
        }
    private:
        std::vector<Fragment*> _array; ///< Array of entries
    };
}
#endif
