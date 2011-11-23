#include <stdint.h>
#include <iostream>
#include <vector>
#include <limits>

#include "BaseFragment.hpp"

#ifndef __LIQUID_CONTEXTUALFRAGMENT
#define __LIQUID_CONTEXTUALFRAGMENT
namespace Liquid
{
    class RenderContext;

    static const std::size_t ContextualFragmentPathOffsetNone = std::numeric_limits<std::size_t>::max();

    /// Path element of a contextual fragment
    struct ContextualFragmentPath
    {
        /// Name of the variable to be looked up
        std::string Name;


        /// Possible offset of the variable to be looked up
        std::size_t Offset;


        /// Initialize a contextual path element

        /// Expects the input to have been fully validated by the lexer.
        /// 
        /// @param markup Markup of the path to be parsed
        ContextualFragmentPath(std::string markup)
            :   Name(markup),
                Offset(ContextualFragmentPathOffsetNone)
        {
            std::size_t bracketPosition = markup.find('[');

            if (bracketPosition != std::string::npos)
            {
                this->Name = markup.substr(0,
                                           bracketPosition);
                
                std::string offsetMarkup = markup.substr(bracketPosition + 1,
                                                         markup.length() - bracketPosition - 2);

                this->Offset = strtoull(offsetMarkup.c_str(),
                                        NULL,
                                        10);
            }
        }
    };
    

    /// Contextual variable
    class ContextualFragment
        :   public Fragment
    {
    public:
        /// Initialize a contextual variable

        /// Requires the markup to be pre-validated
        /// @param markup Markup representation of the contextual variable
        ContextualFragment(std::string markup);


        /// Get the type of a variable implementation

        /// @returns the type of the variable implementation
        virtual FragmentType GetType()
        {
            return FragmentTypeContextual;
        }


        /// Get the string representation of the variable

        /// @returns the printable string representation of the variable
        virtual std::string ToString()
        {
            return std::string();
        }


        /// Resolves the contextual variable to an actual variable
        
        /// @param context Rendering context from which to resolve the variable
        /// @returns the pointer to the fragment described by the variable markup if it exists, otherwise NULL
        Fragment* Resolve(RenderContext& context);

        
        /// Compare this fragment to another fragment
        
        /// @param other Other fragment to compare to
        /// @param comparator Comparator
        /// @returns true if the statement is true, otherwise false
        virtual bool Compare(Fragment* other,
                             ConditionalOperator op)
        {
            return false;
        }
        
        
        /// Clone this fragment
        
        /// @returns the pointer to a clone of this fragment
        virtual Fragment* Clone()
        {
            throw;
        }
    private:
        std::vector<ContextualFragmentPath> _paths; ///< Path of the variable
    };
}
#endif
