#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_FORTAG
#define __LIQUID_FORTAG
namespace Liquid
{
    /// Type of for enumeration
    enum ForEnumeration
    {
        /// Enumeration over a collection of arbitrary elements
        ForCollectionEnumeration,

        
        /// Enumaration over a render-time known range
        ForRangeEnumeration
    };
    

    /// For tag
    
    /// Handles iteration over collections or ranges
    class ForTag
        :   public BranchNode
    {
    public:
        /// Initialize an empty for tag
        ForTag();


        /// Dispose of a for tag
        virtual ~ForTag();


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


        ForEnumeration _enumeration; ///< Type of enumeration
        std::string _targetName; ///< Name of the enumeration target
        Fragment* _start; ///< Range start in the case of range enumeration, collection fragment in the case of fragment evaluation
        Fragment* _end; ///< Range end in the case of range enumration, otherwise unspecified

        Fragment* _limit; ///< Limit of the enumeration
        Fragment* _offset; ///< Offset of the enumeration
        bool _reversed; ///< Reversed enumeration
    };
}
#endif
