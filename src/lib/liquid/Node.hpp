#include <iostream>
#include <stdexcept>

#ifndef __LIQUID_NODE
#define __LIQUID_NODE
namespace Liquid
{
    class RenderContext;

    /// Base class for AST nodes
    class Node
    {
    public:
        /// Virtual detructor for AST nodes
        virtual ~Node() { }


        /// Try to render the node
        
        /// @param context Rendering context
        /// @returns true if rendering succeeded, otherwise false
        virtual bool TryRender(RenderContext& context)
        {
            std::cout << "Fatal error: rendering node base class" << std::endl;
            throw;
        }
    };
}
#endif
