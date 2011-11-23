#include "AssignTag.hpp"
#include "Fragment.hpp"

namespace Liquid
{
    AssignTag::AssignTag()
        :   _value(NULL)
    {

    }

    AssignTag::~AssignTag()
    {
        if (this->_value)
            delete this->_value;
    }

    Node* AssignTag::Initialize(Token* tagToken,
                                ParserContext& context)
    {
        // Grammar:
        //   {% assign <path> = <fragment> %}

        // Hacky-ish macro definitions to make my life easier
#define HandleError(expression, description) \
        if (expression)                      \
        {                                   \
            delete tag;                     \
            context.Error.Set(token,        \
                              description); \
            return NULL;                    \
        }

#define HandleNext()                                                    \
        if (!context.TryNext(token))                                    \
        {                                                               \
            delete tag;                                                 \
            context.Error.Set(token,                                    \
                              "unexpected end of file while parsing assign tag"); \
            return NULL;                                                \
        }

        // Create the tag node
        AssignTag* tag = new AssignTag();

        // Ensure that tag is the "cycle" tag
        Token* token = tagToken;
        
        HandleError(token->Value != "assign",
                    "assign tag called to handle a tag called " + token->Value);

        // Get the target
        HandleNext();

        HandleError(!(token->Type & TokenIdentifier) ||
                    (token->Value == "empty") ||
                    (token->Value == "null") ||
                    (token->Value == "nil") ||
                    (token->Value == "false") ||
                    (token->Value == "true"),
                    "cannot assign a value to " + token->Value);

        tag->_targetName = token->Value;
        std::string targetName = token->Value;

        // Ensure that the next token is an assignment operator
        HandleNext();

        HandleError(!(token->Type & TokenOperator) ||
                    (token->Value != "="),
                    "expected '=' but found '" + token->Value + "' in assign tag");

        // Get the value
        HandleNext();

        HandleError(!Fragment::IsValid(token),
                    "cannot assign " + token->Value + " as the value of " + targetName);

        HandleError(token->Value == tag->_targetName,
                    "self-assignment is not allowed");

        tag->_value = Fragment::Initialize(token);

        // Get the ending tag
        HandleNext();
        
        HandleError(!(token->Type & TokenTagClose),
                    "expected tag to close but got " + token->Value);

        // Return the tag
        return tag;
    }

    bool AssignTag::TryRender(RenderContext& context)
    {
        // Resolve the value if necessary
        Fragment* value = this->_value;

        if ((value) &&
            (this->_value->GetType() == FragmentTypeContextual))
        {
            value = reinterpret_cast<ContextualFragment*>(this->_value)->Resolve(context);
        }

        // Avoid null resolution problems
        if (value == NULL)
        {
            context.Data->Set(this->_targetName,
                              new NullFragment());
            
            return true;
        }
        
        // Clone the value into the assignment location
        context.Data->Set(this->_targetName,
                          value->Clone());
        
        // Rendering done
        return true;
    }
}
