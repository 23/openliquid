#include "Condition.hpp"
#include "ParserContext.hpp"

#ifndef __LIQUID_IFTAGOPTION
#define __LIQUID_IFTAGOPTION
namespace Liquid
{
    /// If option

    /// Represents a possible outcome of an if block
    class IfTagOption
    {
    public:
        /// Initialize an empty option

        /// @param invert Invert the outcome of the expression
        IfTagOption(bool invert = false);
        
        
        /// Dispose of an option
        ~IfTagOption();

        
        /// Try to parse the expression for the option
        bool TryParseExpression(ParserContext& context);
        
        
        /// Set the children
        void SetChildren(std::vector<Node*> children)
        {
            this->_children = children;
        }


        /// Evaluate the option

        /// @param context Rendering context
        /// @returns treu if the option evaluates as supposed, otherwise false
        bool Evaluate(RenderContext& context);


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
        std::vector<Node*> _children; ///< Children of the option

        Condition* _rootCondition; ///< Root condition for the option
        bool _invertCondition; ///< Invert the condition for this option to be valid
    };
}
#endif
