#include "OutputNode.hpp"
#include "RenderContext.hpp"
#include "ContextualFragment.hpp"

namespace Liquid
{
    OutputNode::OutputNode()
        :   _baseFragment(NULL)
    {

    }

    OutputNode::~OutputNode()
    {
        // Destroy the fragment if necessary
        if (this->_baseFragment)
            delete this->_baseFragment;
        
        // Delete the filters
        std::size_t index = this->_filters.size();
        while (index--)
            delete this->_filters[index];
    }

    bool OutputNode::TryParse(ParserContext& context)
    {
        // The lexical layout of an output node is as follows
        // <ambigious> (| <identifier>(: <ambigious>(, <ambigious>)? )? )?

        Token* token;
        OutputFilter* filter = NULL;

        // * Parse the variable identifier
        if (!context.TryNext(token))
        {
            context.Error.Description = "unexpected end of file when parsing output tag";
            return false;
        }

#define HandleNext()                                                                     \
        if (!context.TryNext(token))                                                     \
            return context.Error.Set(token,                                              \
                                     "unexpected end of file while parsing output tag"); \

#define HandleError(expression, message)           \
        if (expression)                            \
            return context.Error.Set(token,        \
                                     message);     \

        // Validate the token as a fragment
        HandleError(!Fragment::IsValid(token),
                    "invalid fragment in output tag: " + token->Value);

        // Construct the fragment
        this->_baseFragment = Fragment::Initialize(token);

        // * Handle filters
        HandleNext();
        
        // Iterate through filters
        while (token->Type & TokenFilterSeparator)
        {
            // Try to get the name of the fragment
            HandleNext();
            HandleError(!(token->Type & TokenIdentifier),
                        "invalid filter name in output tag: " + token->Value);

            // Construct the filter
            filter = new OutputFilter(token);
            this->_filters.push_back(filter);

            // Handle arguments
            HandleNext();

            if (token->Type & TokenArgumentDelimiter)
            {
                // Iterate arguments
                do
                {
                    // Step one ahead to get to the fragment
                    HandleNext();

                    // Validate the fragment
                    HandleError(!Fragment::IsValid(token),
                                "invalid argument for filter: " + token->Value);

                    // Add the argument
                    filter->AddArgument(token);

                    // Move ahead
                    HandleNext();
                }
                while (token->Type & TokenArgumentSeparator);
            }
        }

        // Check that this is an ending token
        HandleError(!(token->Type & TokenOutputClose),
                    "expected end of output tag, but got " + token->Value);

#undef HandleNext
#undef HandleError

        // Done!
        return true;
    }
    
    bool OutputNode::TryRender(RenderContext& context)
    {
        // Resolve the base fragment
        Fragment* outputFragment = this->_baseFragment;
        
        if (!outputFragment)
            return true;

        if (outputFragment->GetType() == FragmentTypeContextual)
        {
            outputFragment = reinterpret_cast<ContextualFragment*>(outputFragment)->Resolve(context);

            if (!outputFragment)
                return true;
        }

        // Save a reference to the base before filters are applied
        Fragment* baseFragment = outputFragment;

        // Output the value
        context.Result << outputFragment->ToString();

        // Delete the output fragment if it isn't the base fragment
        if (outputFragment != baseFragment)
            delete outputFragment;

        return true;
    }
}
