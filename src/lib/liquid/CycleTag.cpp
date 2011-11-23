#include "CycleTag.hpp"

namespace Liquid
{
    CycleTag::CycleTag()
        :   _cycleName(NULL),
            _hash(0x00000000)
    {

    }

    CycleTag::~CycleTag()
    {
        // Delete the cycle name if necessary
        if (_cycleName)
            delete this->_cycleName;

        // Delete the options if necessary
        std::size_t index = this->_options.size();
        while (index--)
            delete this->_options[index];
    }

    Node* CycleTag::Initialize(Token* tagToken,
                               ParserContext& context)
    {
        // Grammar:
        //   {% cycle (<fragment>:)? <fragment> (, <fragment>)* %}

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
                              "unexpected end of file while parsing cycle tag"); \
            return NULL;                                                \
        }

        // Create the tag node
        CycleTag* tag = new CycleTag();

        // Ensure that tag is the "cycle" tag
        Token* token = tagToken;
        
        HandleError(token->Value != "cycle",
                    "cycle tag called to handle a tag called " + tagToken->Value);

        // Check if tag is a named cycle
        HandleNext();

        Token* firstToken = token;

        HandleError(!Fragment::IsValid(firstToken),
                    "invalid cycle name or option");

        HandleNext();

        if (token->Type & TokenArgumentDelimiter)
        {
            tag->_cycleName = Fragment::Initialize(firstToken);

            // Read out the first option
            HandleNext();
            
            HandleError(!Fragment::IsValid(token),
                        "invalid cycle option");

            tag->_options.push_back(Fragment::Initialize(token));
            
            // Skip to the next token
            HandleNext();
        }
        else if (token->Type & TokenArgumentSeparator)
        {
            tag->_options.push_back(Fragment::Initialize(firstToken));
        }
        else
        {
            delete tag;
            context.Error.Set(token,
                              "invalid separator in cycle tag");
            return NULL;
        }

        // Iterate over the consecutive options
        while (token->Type & TokenArgumentSeparator)
        {
            // Skip past the separator
            HandleNext();

            // Ensure that the option is viable
            HandleError(!Fragment::IsValid(token),
                        "invalid cycle option");
            
            tag->_options.push_back(Fragment::Initialize(token));

            // Skip to the next token
            HandleNext();
        }

        // When we get here, we're expecting an ending token
        HandleError(!(token->Type & TokenTagClose),
                    "expected end of cycle tag, but got " + token->Value);

        // Return the tag node
        return tag;
    }
}
