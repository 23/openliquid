#ifndef __LIQUID_CONDITIONALOPERATOR
#define __LIQUID_CONDITIONALOPERATOR
namespace Liquid
{
    /// Conditional operator
    enum ConditionalOperator
    {
        /// ==
        ConditionalEquals,

        /// !=
        ConditionalNotEquals,

        /// >
        ConditionalGreaterThan,

        /// <
        ConditionalLessThan,

        /// >=
        ConditionalGreaterThanOrEquals,

        /// <=
        ConditionalLessThanOrEquals,

        /// Implicit, ie. LHS evaluation only
        ConditionalImplicit
    };
}
#endif
