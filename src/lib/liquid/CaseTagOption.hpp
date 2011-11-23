#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_CASETAGOPTION
#define __LIQUID_CASETAGOPTION
namespace Liquid
{
    class CaseTagOption
    {
    public:
        /// Initialize a case option

        /// @param option Option to be evaluated against. A NULL option will always evaluate to true
        CaseTagOption(Fragment* option)
            :   _option(option)
        {

        }
        

        /// Dispose of a case option
        ~CaseTagOption()
        {
            // Delete the option if it's available
            if (this->_option)
                delete this->_option;

            // Delete child nodes
            std::size_t index = this->_children.size();
            while (index--)
                delete this->_children[index];
        }

        
        /// Set the children

        /// @param children Child nodes to be assigned
        void SetChildren(std::vector<Node*> children)
        {
            this->_children = children;
        }


        /// Evaluate the option

        /// @param lhs Left hand side of the evaluation
        bool Evaluate(Fragment* lhs)
        {
            return (this->_option == NULL ? 
                    true :
                    lhs->Compare(this->_option, ConditionalEquals));
        }

        /// Try to render the node
        
        /// @param context Rendering context
        /// @returns true if rendering succeeded, otherwise false
        bool TryRender(RenderContext& context)
        {
            // Render each of the child nodes
            std::size_t index = 0;
            
            while (index < this->_children.size())
            {
                if (!this->_children[index]->TryRender(context))
                    return false;
                
                index++;
            }
            
            // Done
            return true;
        }
    private:
        Fragment* _option; ///< Representation of the actual option
        std::vector<Node*> _children; ///< Child nodes for the given option
    };
}
#endif
