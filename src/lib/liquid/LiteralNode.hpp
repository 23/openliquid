#include <string>

#include "RenderContext.hpp"
#include "Node.hpp"

#ifndef __LIQUID_LITERALNODE
#define __LIQUID_LITERALNODE
namespace Liquid
{
    /// Literal node

    /// Renders its supplied value directly to
    /// the output.
    class LiteralNode
        :   public Node
    {
    public:
        /// Initialize a literal node

        /// @param value Value of the literal node
        LiteralNode(std::string& value);
        

        /// Try to render the node
        
        /// @param context Rendering context
        /// @returns true if rendering succeeded, otherwise false
        virtual bool TryRender(RenderContext& context)
        {
            context.Result << this->_value;
            return true;
        }
    private:
        std::string _value; ///< Local copy of the value
    };
}
#endif
