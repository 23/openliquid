#include "Token.hpp"
#include "Fragment.hpp"
#include "ConditionalOperator.hpp"

#ifndef __LIQUID_CONDITION
#define __LIQUID_CONDITION
namespace Liquid
{
    /// Unary operator
    enum UnaryOperator
    {
        /// Unary and operator
        UnaryAnd,

        /// Unary or operator
        UnaryOr
    };


    class RenderContext;

    
    /// Condition

    /// Conditions should be linked in a reverse
    /// manner for proper evaluation.
    class Condition
    {
    public:
        /// Initialize a condition

        /// Note that the LHS token can never be NULL,
        /// and if the RHS token is NULL, the operator must
        /// be implicit.
        /// 
        /// @param lhs Left hand side token
        /// @param op Operator
        /// @param rhs Right hand side token
        Condition(Token* lhs,
                  ConditionalOperator op,
                  Token* rhs);


        /// Dispose of a condition
        ~Condition();

        
        /// Attach a child condition
        void Attach(Condition* childCondition,
                    UnaryOperator childUnary);

        
        /// Evaluate the condition tree
        
        /// @param context Rendering context
        /// @returns true if the condition evaluates to true, otherwise false
        bool Evaluate(RenderContext& context);
    private:
        Condition* _childCondition;
        UnaryOperator _childUnary;

        Fragment* _lhs;
        ConditionalOperator _op;
        Fragment* _rhs;
    };
}
#endif
