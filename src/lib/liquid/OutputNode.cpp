#include "OutputNode.hpp"
#include "RenderContext.hpp"
#include "Fragment.hpp"

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
        Fragment* baseFragment = outputFragment,
                * nextFragment;

        // Run through each filter
        std::size_t filterIndex = 0;
        while (filterIndex < this->_filters.size())
        {
            // Try to apply the filter
            if (!this->_filters[filterIndex]->TryApply(outputFragment,
                                                       nextFragment,
                                                       context))
            {
                if (outputFragment != baseFragment)
                    delete outputFragment;

                return false;
            }

            // Check the next fragment and swap them
            if ((nextFragment != outputFragment) &&
                (outputFragment != baseFragment))
                delete outputFragment;

            outputFragment = nextFragment;
            
            filterIndex++;
        }

        // Output the value
        context.Result << outputFragment->ToString();

        // Delete the output fragment if it isn't the base fragment
        if (outputFragment != baseFragment)
            delete outputFragment;

        return true;
    }

    OutputFilter::OutputFilter(Token* filterToken)
        :   _name(filterToken->Value),
            _nameLineBegin(filterToken->LineBegin),
            _nameLineEnd(filterToken->LineEnd),
            _nameCharacterBegin(filterToken->CharacterBegin),
            _nameCharacterEnd(filterToken->CharacterEnd)
    {
        
    }

    OutputFilter::~OutputFilter()
    {
        std::size_t index = this->_arguments.size();
        while (index--)
            delete this->_arguments[index];
    }

    bool OutputFilter::TryApply(Fragment*& input,
                                Fragment*& output,
                                RenderContext& context)
    {
        // Try to resolve the filter
        FilterFunction filterFunction = context.Strain.ResolveFilterFunction(this->_name);

        if (filterFunction == NULL)
        {
            context.Error.LineBegin = this->_nameLineBegin;
            context.Error.LineEnd = this->_nameLineEnd;
            context.Error.CharacterBegin = this->_nameCharacterBegin;
            context.Error.CharacterEnd = this->_nameCharacterEnd;

            context.Error.Description = "filter not found: " + this->_name;

            return false;
        }

        // Resolve the arguments
        std::vector<Fragment*> arguments;
        Fragment* argument;
        NullFragment nullFragment;

        std::size_t index = 0;
        while (index < this->_arguments.size())
        {
            argument = this->_arguments[index];

            if (argument->GetType() == FragmentTypeContextual)
                argument = reinterpret_cast<ContextualFragment*>(argument)->Resolve(context);

            if (argument == NULL)
                argument = &nullFragment;
            
            arguments.push_back(argument);
            
            index++;
        }

        // Call the function
        output = (*filterFunction)(input,
                                   arguments);

        return true;
    }
}
