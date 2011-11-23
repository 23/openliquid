#include "IfTagOption.hpp"

namespace Liquid
{
    bool IsValidFragment(Token* token)
    {
        return ((token->Type & TokenString) ||
                (token->Type & TokenInteger) ||
                (token->Type & TokenFloat) ||
                (token->Type & TokenNull) ||
                (token->Type & TokenEmpty) ||
                (token->Type & TokenPath) ||
                (token->Type & TokenBoolean));
    }

    IfTagOption::IfTagOption(bool invert)
        :   _rootCondition(NULL),
            _invertCondition(invert)
    {
        
    }

    IfTagOption::~IfTagOption()
    {
        // Delete the root condition if available
        if (this->_rootCondition)
            delete this->_rootCondition;
        
        // Delete the children
        std::size_t index = this->_children.size();
        while (index--)
            delete this->_children[index];
    }

    bool IfTagOption::TryParseExpression(ParserContext& context)
    {
        Token* token,
             * lhsToken = NULL,
             * rhsToken = NULL,
             * unaryToken = NULL;

        ConditionalOperator conditionalOperator;
        UnaryOperator unaryOperator;

        // Evaluate the expressions
        do
        {
            // Get the LHS token
            if (!context.TryNext(token))
            {
                context.Error.Description = "unexpected end of file while parsing condition";
                return false;
            }

            // Ensure the type of the LHS
            if (!IsValidFragment(token))
                return context.Error.Set(token,
                                         "invalid left hand side of expression: " + token->Value);

            // Save the LHS token
            lhsToken = token;

            // Get the operator token
            if (!context.TryNext(token))
                return context.Error.Set(token,
                                         "unexpected end of file while parsing condition");

            // Check the type
            if (token->Type & TokenOperator)
            {
                // Check the operator
                if (token->Value == "==")
                    conditionalOperator = ConditionalEquals;
                else if ((token->Value == "!=") ||
                         (token->Value == "<>"))
                    conditionalOperator = ConditionalNotEquals;
                else if (token->Value == ">")
                    conditionalOperator = ConditionalGreaterThan;
                else if (token->Value == "<")
                    conditionalOperator = ConditionalLessThan;
                else if (token->Value == ">=")
                    conditionalOperator = ConditionalGreaterThanOrEquals;
                else if (token->Value == "<=")
                    conditionalOperator = ConditionalLessThanOrEquals;
                else
                    return context.Error.Set(token,
                                             "invalid expression operator: " + token->Value);

                // Get the RHS token
                if (!context.TryNext(token))
                    return context.Error.Set(token,
                                             "unexpected end of file while parsing condition");

                // Check the type
                if (!IsValidFragment(token))
                    return context.Error.Set(token,
                                             "invalid right hand side of expression: " + token->Value);

                // Store the RHS token
                rhsToken = token;

                // Try to get the unary operator
                if (!context.TryNext(token))
                    return context.Error.Set(token,
                                             "unexpected end of file while parsing condition");
            }
            else
                conditionalOperator = ConditionalImplicit;

            // Evaluate the unary operator
            if (token->Type & TokenIdentifier)
            {
                // Ensure that this is a unary operator
                if (token->Value == "and")
                    unaryOperator = UnaryAnd;
                else if (token->Value == "or")
                    unaryOperator = UnaryOr;
                else
                    return context.Error.Set(token,
                                             "invalid unary operator: " + token->Value);

                // Store the unary operator token
                unaryToken = token;
            }
            else
                unaryToken = NULL;

            // Construct the condition
            Condition* condition = new Condition(lhsToken,
                                                 conditionalOperator,
                                                 rhsToken);

            if (this->_rootCondition)
                condition->Attach(this->_rootCondition,
                                  unaryOperator);

            this->_rootCondition = condition;
            
            // Reset the stored tokens
            lhsToken = NULL;
            rhsToken = NULL;
        }
        while (unaryToken != NULL);

        // Ensure that this is a closing tag
        if (!(token->Type & TokenTagClose))
            return context.Error.Set(token,
                                     "expected end of tag but got " + token->Value);

        // Done
        return true;
    }

    bool IfTagOption::Evaluate(RenderContext& context)
    {
        if (this->_rootCondition == NULL)
            return true;

        bool result = this->_rootCondition->Evaluate(context);
        
        return (this->_invertCondition ? 
                !result :
                result);
    }
}
