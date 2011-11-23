#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "CaseTagOption.hpp"

#ifndef __LIQUID_CASETAG
#define __LIQUID_CASETAG
namespace Liquid
{
    /// Case tag
    
    /// Handles case evaluation
    class CaseTag
        :   public BranchNode
    {
    public:
        /// Initialize an empty case tag
        CaseTag();


        /// Dispose of a case tag
        virtual ~CaseTag();


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
        Fragment* _value; ///< Value being switched
        CaseTagOption* _current; ///< Currently parsing option
        std::vector<CaseTagOption*> _options; ///< Fully parsed options
    };
}
#endif
