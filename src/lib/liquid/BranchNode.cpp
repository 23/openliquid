#include "BranchNode.hpp"
#include "LiteralNode.hpp"
#include "OutputNode.hpp"

namespace Liquid
{
    BranchNode::~BranchNode()
    {
        // Dispose of all children
        std::size_t index = this->_children.size();
        
        while (index--)
            delete this->_children[index];
    }

    bool BranchNode::TryParse(ParserContext& context)
    {
        Token* nextToken;

        // Parse through all nodes
        while (context.TryNext(nextToken))
        {
            switch (nextToken->Type)
            {
            case TokenLiteral:
                {
                    // * Construct a literal node
                    this->_children.push_back(new LiteralNode(nextToken->Value));
                    
                    break;
                }

            case TokenTagOpen:
                {
                    // * Construct a specific tag node

                    // Ensure that the tag name is an identifier
                    if (!context.TryNext(nextToken))
                        return context.Error.Set(nextToken,
                                                 "unexpected end of file after tag opening");

                    if (!(nextToken->Type & TokenIdentifier))
                        return context.Error.Set(nextToken,
                                                 "invalid tag name: " + nextToken->Value);

                    // Resolve the initializer for the tag
                    TagInitializer initializer = context.Strain.ResolveTagInitializer(nextToken->Value);

                    if (!initializer)
                    {
                        UnknownTagHandling handling = this->TryHandleUnknownTag(nextToken,
                                                                                context);

                        switch (handling)
                        {
                        case UnknownUnknown:
                            return context.Error.Set(nextToken,
                                                     "unknown tag " + nextToken->Value);

                        case UnknownError:
                            return false;

                        case UnknownHandled:
                            break;

                        case UnknownEndParsing:
                            return true;
                        }
                    }
                    else
                    {
                        // Invoke the initializer
                        Node* tagNode = (*initializer)(nextToken,
                                                       context);
                        
                        if (tagNode == NULL)
                            return false;
                        
                        this->_children.push_back(tagNode);
                    }
                    
                    break;
                }

            case TokenOutputOpen:
                {
                    // * Construct an output node

                    // Construct the actual node
                    OutputNode* node = new OutputNode();

                    // Try to parse the output node
                    if (!node->TryParse(context))
                    {
                        delete node;
                        return false;
                    }

                    // Push back the node
                    this->_children.push_back((Node*)node);
                    
                    break;
                }

            default:
                {
                    // * Unexpected token
                    return context.Error.Set(nextToken,
                                             "unexpected token " + nextToken->Value);
                }
            }
        }

        return true;
    }

    UnknownTagHandling BranchNode::TryHandleUnknownTag(Token* token,
                                                       ParserContext& context)
    {
        return UnknownUnknown;
    }

    bool BranchNode::TryRender(RenderContext& context)
    {
        // Render each of the child nodes
        std::size_t index = 0;
        
        while (index < this->_children.size())
        {
            if (!this->_children[index]->TryRender(context))
                return false;
            
            index++;
        }
        
        // Done
        return true;
    }
}
