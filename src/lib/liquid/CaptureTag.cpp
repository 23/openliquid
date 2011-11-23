#include "CaptureTag.hpp"
#include "Fragment.hpp"

namespace Liquid
{
    CaptureTag::CaptureTag()
    {

    }

    CaptureTag::~CaptureTag()
    {

    }

    Node* CaptureTag::Initialize(Token* tagToken,
                                 ParserContext& context)
    {
        // Grammar:
        //   {% capture <path> %} .. {% endcapture %}

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
                              "unexpected end of file while parsing capture tag"); \
            return NULL;                                                \
        }

        // Create the tag node
        CaptureTag* tag = new CaptureTag();

        // Ensure that tag is the "cycle" tag
        Token* token = tagToken;
        
        HandleError(token->Value != "capture",
                    "capture tag called to handle a tag called " + token->Value);

        // Get the target
        HandleNext();

        HandleError(!(token->Type & TokenIdentifier) ||
                    (token->Value == "empty") ||
                    (token->Value == "null") ||
                    (token->Value == "nil") ||
                    (token->Value == "false") ||
                    (token->Value == "true"),
                    "cannot capture a value to " + token->Value);

        tag->_targetName = token->Value;

        // Get the ending tag
        HandleNext();
        
        HandleError(!(token->Type & TokenTagClose),
                    "expected tag to close but got " + token->Value);

        // Parse out the contents
        if (!tag->TryParse(context))
        {
            delete tag;
            return NULL;
        }

        // Return the tag
        return tag;
    }

    UnknownTagHandling CaptureTag::TryHandleUnknownTag(Token* token,
                                                       ParserContext& context)
    {
        Token* nextToken;
        
        // Ending of the block
        if (token->Value == "endcapture")
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
                                  "expected the tag to end, but found " + token->Value);
                return UnknownError;
            }

            return UnknownEndParsing;
        }

        return UnknownUnknown;
    }

    bool CaptureTag::TryRender(RenderContext& context)
    {
        // Construct a new rendering context
        RenderContext captureContext(context.Data,
                                     context.Strain,
                                     context.Error);

        // Try to execute rendering
        if (!BranchNode::TryRender(captureContext))
            return false;

        // Assign the result of the capture
        context.Data->Set(this->_targetName,
                          new StringFragment(captureContext.Result.str()));

        // Rendering done
        return true;
    }
}
