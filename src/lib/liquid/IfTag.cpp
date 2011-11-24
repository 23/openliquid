#include "IfTag.hpp"

namespace Liquid
{
    IfTag::IfTag()
        :   _current(NULL)
    {
        
    }

    IfTag::~IfTag()
    {
        // Delete the currently parsing option if available
        if (this->_current)
            delete this->_current;
        
        // Delete the fully parsed options
        std::size_t index = this->_options.size();
        while (index--)
            delete this->_options[index];
    }

    Node* IfTag::Initialize(Token* tagToken,
                            ParserContext& context)
    {
        // Construct an IfTag node
        IfTag* tag = new IfTag();
        
        // Create an option for the expressions
        tag->_tagName = tagToken->Value;
        tag->_current = new IfTagOption(tagToken->Value == "unless");
        
        // Try to parse the expression
        if (!tag->_current->TryParseExpression(context))
        {
            delete tag;
            return NULL;
        }

        // Try to parse the contents
        if (!tag->TryParse(context))
        {
            delete tag;
            return NULL;
        }
        
        // Return the node
        return tag;
    }

    UnknownTagHandling IfTag::TryHandleUnknownTag(Token* token,
                                                  ParserContext& context)
    {
        Token* nextToken;
        
        // Push the current option off being the actual option
        this->_current->SetChildren(this->_children);
        this->_children.clear();
        this->_options.push_back(this->_current);
        this->_current = NULL;
        
        // Ending of the block
        if (token->Value == "end" + this->_tagName)
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
        else if ((token->Value == "elif") ||
                 (token->Value == "elsif") ||
                 (token->Value == "elseif"))
        {
            // Create an option for the expressions
            this->_current = new IfTagOption();
        
            // Try to parse the expression
            if (!this->_current->TryParseExpression(context))
                return UnknownError;

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

            // Create an option for the expressions
            this->_current = new IfTagOption();
            
            return UnknownHandled;
        }

        return UnknownUnknown;
    }
    
    bool IfTag::TryRender(RenderContext& context)
    {
        // Iterate through all options until one is possibly met
        std::size_t index = 0;
        while (index < this->_options.size())
        {
            if (this->_options[index]->Evaluate(context))
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
