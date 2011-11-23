#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "IfTagOption.hpp"

#ifndef __LIQUID_IFTAG
#define __LIQUID_IFTAG
namespace Liquid
{
    /// If tag
    
    /// Handles if and unless tags by evaluating their expressions
    class IfTag
        :   public BranchNode
    {
    public:
        /// Initialize an empty if tag
        IfTag();


        /// Dispose of an if tag
        virtual ~IfTag();


        /// Initialize a tag

        /// Guaranteed to have the first token be available as the name
        /// of the tag.
        /// 
        /// @param tagToken Token representing the tag name
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
        IfTagOption* _current; ///< Currently parsing option
        std::vector<IfTagOption*> _options; ///< Fully parsed options
    };
}
#endif
