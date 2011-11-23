#include "CaseTag.hpp"
#include "Fragment.hpp"

namespace Liquid
{
    CaseTag::CaseTag()
        :   _value(NULL),
            _current(NULL)
    {

    }

    CaseTag::~CaseTag()
    {
        // Delete the value if available
        if (this->_value)
            delete this->_value;
        
        // Delete the currently parsing option if available
        if (this->_current)
            delete this->_current;
        
        // Delete the fully parsed options
        std::size_t index = this->_options.size();
        while (index--)
            delete this->_options[index];
    }

    Node* CaseTag::Initialize(Token* tagToken,
                              ParserContext& context)
    {
        // Ensure that this is a case tag
        if (tagToken->Value != "case")
        {
            context.Error.Set(tagToken,
                              "case tag being parsed for unknown tag " + tagToken->Value);
            return NULL;
        }

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
                              "unexpected end of file while parsing case tag"); \
            return NULL;                                                \
        }

        // Construct a case node
        CaseTag* tag = new CaseTag();

        // Get the value being switched
        Token* token = tagToken;

        HandleNext();
        HandleError(!Fragment::IsValid(token),
                    "cannot compare " + token->Value + " in case tag");

        tag->_value = Fragment::Initialize(token);

        // Get the end of the tag
        HandleNext();
        HandleError(!(token->Type & TokenTagClose),
                    "expected end of case tag, but found " + token->Value);

        // Try to parse the contents
        if (!tag->TryParse(context))
        {
            delete tag;
            return NULL;
        }
        
        // Return the node
        return tag;
    }

    UnknownTagHandling CaseTag::TryHandleUnknownTag(Token* token,
                                                    ParserContext& context)
    {
        Token* nextToken = token;
        
        // Push the current option off being the actual option
        if (this->_current)
        {
            this->_current->SetChildren(this->_children);
            this->_options.push_back(this->_current);
            this->_current = NULL;
        }
        else
        {
            std::size_t index = this->_children.size();
            while (index--)
                delete this->_children[index];
        }

        this->_children.clear();
        
        // Ending of the block
        if (token->Value == "endcase")
        {
            if (!context.TryNext(nextToken))
            {
                context.Error.Set(token,
                                  "unexpected end of file");
                return UnknownError;
            }
            
            if (!(nextToken->Type & TokenTagClose))
            {
                context.Error.Set(token,
                                  "expected the tag to end, but found " + nextToken->Value);
                return UnknownError;
            }

            return UnknownEndParsing;
        }
        else if (token->Value == "when")
        {
            // Get the fragment name
            if (!context.TryNext(nextToken))
            {
                context.Error.Set(token,
                                  "unexpected end of file");
                return UnknownError;
            }

            if (!Fragment::IsValid(nextToken))
            {
                context.Error.Set(nextToken,
                                  "cannot evaluate " + nextToken->Value + " as a case");
                return UnknownError;
            }

            Fragment* optionValue = Fragment::Initialize(nextToken);

            // Make sure that the tag block is closed
            if (!context.TryNext(nextToken))
            {
                delete optionValue;
                context.Error.Set(token,
                                  "unexpected end of file");
                return UnknownError;
            }
            
            if (!(nextToken->Type & TokenTagClose))
            {
                delete optionValue;
                context.Error.Set(token,
                                  "expected the tag to end, but found " + nextToken->Value);
                return UnknownError;
            }

            // Create an option
            this->_current = new CaseTagOption(optionValue);
            return UnknownHandled;
        }
        else if (token->Value == "else")
        {
            // Make sure that the tag is closed
            if (!context.TryNext(nextToken))
            {
                context.Error.Set(token,
                                  "unexpected end of file");
                return UnknownError;
            }
            
            if (!(nextToken->Type & TokenTagClose))
            {
                context.Error.Set(token,
                                  "expected the tag to end, but found " + token->Value);
                return UnknownError;
            }

            // Create an option
            this->_current = new CaseTagOption(NULL);
            
            return UnknownHandled;
        }

        return UnknownUnknown;
    }

    bool CaseTag::TryRender(RenderContext& context)
    {
        // Try to resolve the left hand side
        Fragment* value = this->_value;
        NullFragment nullFragment;

        if ((value) &&
            (value->GetType() == FragmentTypeContextual))
            value = reinterpret_cast<ContextualFragment*>(value)->Resolve(context);

        if (value == NULL)
            value = &nullFragment;

        // Iterate through all options until one is possibly met
        std::size_t index = 0;
        while (index < this->_options.size())
        {
            if (this->_options[index]->Evaluate(value))
            {
                if (!this->_options[index]->TryRender(context))
                    return false;
                
                break;
            }
            
            index++;
        }

        return true;
    }
}
