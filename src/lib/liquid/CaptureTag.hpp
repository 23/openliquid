#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_CAPTURETAG
#define __LIQUID_CAPTURETAG
namespace Liquid
{
    /// Capture tag
    
    /// Captures its child nodes to an assignment target
    class CaptureTag
        :   public BranchNode
    {
    public:
        /// Initialize an empty capture tag
        CaptureTag();


        /// Dispose of a capture tag
        virtual ~CaptureTag();


        /// Initialize a tag

        /// Guaranteed to have the first token be available as the name
        /// of the tag.
        /// 
        /// @param context Parser context
        /// @returns a tag node if successful, otherwise NULL
        static Node* Initialize(Token* tagToken,
                                ParserContext& context);

        
        /// Try to render the node
        
        /// @param context Rendering context
        /// @returns true if rendering succeeded, otherwise false
        virtual bool TryRender(RenderContext& context);
    protected:
        /// Try to handle the occurance of an unknown tag

        /// @param token Token representing the tag name
        /// @param context Parser context
        /// @returns true if the tag has been handled, otherwise false
        virtual UnknownTagHandling TryHandleUnknownTag(Token* token,
                                                       ParserContext& context);
    private:
        std::string _targetName; ///< Assignment target upon evaluation
    };
}
#endif
