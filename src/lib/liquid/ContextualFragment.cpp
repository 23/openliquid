#include "ContextualFragment.hpp"

#include "RenderContext.hpp"
#include "ArrayFragment.hpp"
#include "HashFragment.hpp"

namespace Liquid
{
    ContextualFragment::ContextualFragment(std::string markup)
    {
        // Split the markup
        std::size_t markupOffset = 0,
                    splitOffset;
        
        while ((splitOffset = markup.find('.', markupOffset)) != std::string::npos)
        {
            this->_paths.push_back(markup.substr(markupOffset, splitOffset - markupOffset));
            
            // Move up the position
            markupOffset = splitOffset + 1;
        }
        
        this->_paths.push_back(markup.substr(markupOffset));
    }

    
    Fragment* ContextualFragment::Resolve(RenderContext& context)
    {
        // Make sure that we actually have any path elements
        if (this->_paths.size() == 0)
            return NULL;

        // Iterate each of the path elements
        std::size_t pathIndex = 0;
        Fragment* current = context.Data;

        while (pathIndex < this->_paths.size())
        {
            ContextualFragmentPath& element = this->_paths[pathIndex];

            // Ensure that the current element is a hash dictionary
            if (current->GetType() != FragmentTypeHash)
                return NULL;
            
            // Do a lookup in the current hash dictionary
            current = reinterpret_cast<HashFragment*>(current)->Get(element.Name);
            
            if (current == NULL)
                return NULL;

            // Check if we need to do an offset lookup
            if (element.Offset != ContextualFragmentPathOffsetNone)
            {
                if (current->GetType() != FragmentTypeArray)
                    return NULL;

                current = reinterpret_cast<ArrayFragment*>(current)->Get(element.Offset);
                
                if (current == NULL)
                    return NULL;
            }

            pathIndex++;
        }
        
        return current;
    }


    std::string ContextualFragment::ToDebugString()
    {
        return "contextual(?)";
    }
}
