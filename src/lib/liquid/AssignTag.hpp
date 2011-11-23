#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_ASSIGNTAG
#define __LIQUID_ASSIGNTAG
namespace Liquid
{
    /// Assign tag
    
    /// Handles assignment of a fragment to a variable
    class AssignTag
        :   public BranchNode
    {
    public:
        /// Initialize an empty assign tag
        AssignTag();


        /// Dispose of an assign tag
        virtual ~AssignTag();


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
    private:
        std::string _targetName; ///< Assignment target
        Fragment* _value; ///< Value to be assigned
    };
}
#endif
