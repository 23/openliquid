#include <vector>

#include "BranchNode.hpp"
#include "ParserContext.hpp"
#include "BaseFragment.hpp"

#ifndef __LIQUID_CYCLETAG
#define __LIQUID_CYCLETAG
namespace Liquid
{
    /// Cycle tag
    
    /// Handles cycling through multiple values
    class CycleTag
        :   public BranchNode
    {
    public:
        /// Initialize an empty cycle tag
        CycleTag();


        /// Dispose of a cycle tag
        virtual ~CycleTag();


        /// Initialize a tag

        /// Guaranteed to have the first token be available as the name
        /// of the tag.
        /// 
        /// @param context Parser context
        /// @returns a tag node if successful, otherwise NULL
        static Node* Initialize(Token* tagToken,
                                ParserContext& context);
    protected:
        Fragment* _cycleName; ///< Name of the cycle, default is NULL
        std::vector<Fragment*> _options; ///< Options
        uint32_t _hash; ///< Hash of the cycle
    };
}
#endif
