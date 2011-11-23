#include <map>

#include "BaseFragment.hpp"

#ifndef __LIQUID_HASHFRAGMENT
#define __LIQUID_HASHFRAGMENT
namespace Liquid
{
    /// Type definition for a hash dictionary map
    typedef std::map<std::string, Fragment*> HashFragmentMap;


    /// Type definition for a hash dictionary iterator
    typedef HashFragmentMap::iterator HashFragmentIterator;


    /// Type definition for a hash dictionary key-value pair
    typedef std::pair<std::string, Fragment*> HashFragmentPair;
    

    /// Hash dictionary
    class HashFragment
        :   public Fragment
    {
    public:
        /// Create an empty hash dictionary
        HashFragment();


        /// Dispose of a hash dictionary
        virtual ~HashFragment();
        
        
        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeHash;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return std::string();
        }
        
        
        /// Set a specific entry in the hash dictionary
        
        /// If a non-NULL entry already exists with the specific key,
        /// it is removed and freed before the new entry is put into
        /// its place.
        /// 
        /// @param key Key of the entry
        /// @param value Value of the entry
        void Set(std::string key,
                 Fragment* value);


        /// Remove a specific entry in the hash dictionary

        /// If a non-NULL entry exists with the specific key,
        /// it is freed.
        /// 
        /// @param key Key of the entry
        void Remove(std::string key);
        
        
        /// Get a specific entry in the hash dictionary
        
        /// @param key Key of the entry
        /// @returns the fragment held at the specific key if available, otherwise NULL
        Fragment* Get(std::string key);
        
        
        /// Swap a specific entry in the hash dictionary
        
        /// @param key Key of the entry
        /// @param value New value of the entry
        /// @returns the old value of the entry if available, otherwise NULL
        Fragment* Swap(std::string key,
                       Fragment* value);

        
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
            HashFragment* result = new HashFragment();

            HashFragmentIterator iterator = this->_map.begin();
            while (iterator != this->_map.end())
            {
                if (iterator->second != NULL)
                    result->Set(iterator->first,
                                iterator->second->Clone());

                iterator++;
            }

            return result;
        }
    private:
        HashFragmentMap _map; ///< Hash map
    };
}
#endif
