#include <vector>

#include "Node.hpp"
#include "ParserContext.hpp"
#include "RenderContext.hpp"

#ifndef __LIQUID_BRANCHNODE
#define __LIQUID_BRANCHNODE
namespace Liquid
{
    enum UnknownTagHandling
    {
        UnknownUnknown,
        UnknownHandled,
        UnknownEndParsing,
        UnknownError
    };
    

    /// Branch node

    /// A node which holds one or more child nodes.
    class BranchNode
        :   public Node
    {
    public:
        /// Dispose of a branch node
        virtual ~BranchNode();


        /// Try to parse the branch node node

        /// @param tokens Tokens
        /// @param error Parser error reference
        /// @returns true if parsing succeeds, otherwise false
        virtual bool TryParse(ParserContext& context);


        /// Try to render the node
        
        /// @param context Rendering context
        /// @returns true if rendering succeeded, otherwise false
        virtual bool TryRender(RenderContext& context);
    protected:
        std::vector<Node*> _children; ///< Child nodes


        /// Try to handle the occurance of an unknown tag

        /// Returns true if the implementation has handled
        /// the unknown tag, otherwise false
        /// 
        /// @param token Token representing the tag name
        /// @param context Parser context
        /// @returns true if the tag has been handled, otherwise false
        virtual UnknownTagHandling TryHandleUnknownTag(Token* token,
                                                       ParserContext& context);
    };
}
#endif
