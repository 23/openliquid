#include "HashFragment.hpp"
#include "Fragment.hpp"

namespace Liquid
{
    HashFragment::HashFragment()
    {

    }

    HashFragment::~HashFragment()
    {
        // Iterate through all entries and delete them
        HashFragmentIterator iterator = this->_map.begin();
        
        while (iterator != this->_map.end())
        {
            if (iterator->second != NULL)
            {
                delete iterator->second;
                iterator->second = NULL;
            }
            
            iterator++;
        }
    }

    void HashFragment::Set(std::string key,
                           Fragment* value)
    {
        // Check if the key already exists in the dictionary
        HashFragmentIterator iterator = this->_map.find(key);

        if (iterator != this->_map.end())
        {
            // Delete the old value if necessary
            if (iterator->second != NULL)
                delete iterator->second;

            // Assign the new value
            iterator->second = value;
        }
        else
        {
            // Insert a new element
            this->_map.insert(HashFragmentPair(key,
                                               value));
        }
    }

    void HashFragment::Remove(std::string key)
    {
        // Check if the key already exists in the dictionary
        HashFragmentIterator iterator = this->_map.find(key);

        if (iterator == this->_map.end())
            return;

        // Delete the old value if necessary
        if (iterator->second != NULL)
            delete iterator->second;

        // NULL out the value
        iterator->second = NULL;
    }

    Fragment* HashFragment::Swap(std::string key,
                                 Fragment* value)
    {
        // Check if the key already exists in the dictionary
        HashFragmentIterator iterator = this->_map.find(key);
        Fragment* oldValue = NULL;

        if (iterator != this->_map.end())
        {
            // Store the old value
            oldValue = iterator->second;

            // Assign the new value
            iterator->second = value;
        }
        else
        {
            // Insert a new element
            this->_map.insert(HashFragmentPair(key,
                                               value));
        }

        return oldValue;
    }

    Fragment* HashFragment::Get(std::string key)
    {
        HashFragmentIterator iterator = this->_map.find(key);

        if (iterator == this->_map.end())
            return NULL;

        return iterator->second;
    }

    bool HashFragment::Compare(Fragment* other,
                               ConditionalOperator op)
    {
        // Implicit operators need to respect boolean comparison
        if (op == ConditionalImplicit)
            return true;
        
        // Type dependant evaluation
        switch (other->GetType())
        {
        case FragmentTypeHash:
            return ((op == ConditionalEquals) &&
                    (other == this));

        default:
            return (op == ConditionalNotEquals);
        }
    }

    std::string HashFragment::ToDebugString()
    {
        std::stringstream ss;
        ss << "{";

        bool first = true;
        HashFragmentIterator it = _map.begin();
        while (it != _map.end())
        {
            if (it->second)
            {
                if (first)
                    first = false;
                else
                    ss << ", ";

                ss << it->first << ": " << it->second->ToDebugString();
            }

            ++it;
        }

        ss << "}";
        return ss.str();
    }
}
