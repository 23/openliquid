#include "ForTag.hpp"

#include "Fragment.hpp"

namespace Liquid
{
    ForTag::ForTag()
        :   _enumeration(_enumeration),
	    _start(NULL),
            _end(NULL),
            _limit(NULL),
            _offset(NULL),
            _reversed(false)
    {

    }

    ForTag::~ForTag()
    {
        if (this->_start)
            delete this->_start;
        if (this->_end)
            delete this->_end;
        if (this->_limit)
            delete this->_limit;
        if (this->_offset)
            delete this->_offset;
    }

    Node* ForTag::Initialize(Token* tagToken,
                             ParserContext& context)
    {
        // Hacky-ish macro definitions to make my life easier
#define HandleError(expression, description) \
        if (expression)                      \
        {                                    \
            delete tag;                      \
            context.Error.Set(token,         \
                              description);  \
            return NULL;                     \
        }

#define HandleNext()                                                    \
        if (!context.TryNext(token))                                    \
        {                                                               \
            delete tag;                                                 \
            context.Error.Set(token,                                    \
                              "unexpected end of file while parsing for tag"); \
            return NULL;                                                \
        }

        // Create the tag node
        ForTag* tag = new ForTag();

        // Ensure that tag is the "for" tag
        Token* token = tagToken;
        
        HandleError(token->Value != "for",
                    "for tag called to handle a tag called " + tagToken->Value);

        // Get the identifier of the variable to be assigned during the
        // evaluation of the for loop
        HandleNext();
        
        HandleError(!(token->Type & TokenIdentifier),
                    "invalid variable name for for loop");
        HandleError(token->Value == "forloop",
                    "for loops cannot use 'forloop' as the keyword, as "
                    "tag is reserved for information regarding the loop.");

        tag->_targetName = token->Value;

        // Make sure that the next tag is "in"
        HandleNext();
        
        HandleError(token->Value != "in",
                    "expected 'in' but found '" + token->Value + "' in for loop");

        // Check if tag is a range or collection evaluation
        HandleNext();

        if (token->Type & TokenParenthesisOpen)
        {
            // Range evaluation.
            tag->_enumeration = ForRangeEnumeration;

            // Get the start of the range
            HandleNext();

            HandleError(!(token->Type & TokenInteger) &&
                        !(token->Type & TokenPath),
                        "range start must either be an integer or a variable");

            tag->_start = Fragment::Initialize(token);
            
            // Get the range separator
            HandleNext();

            HandleError(!(token->Type & TokenRangeSeparator),
                        "expected '..' but got " + token->Value);

            // Get the end of the range
            HandleNext();

            HandleError(!(token->Type & TokenInteger) &&
                        !(token->Type & TokenPath),
                        "range end must either be an integer or a variable");

            tag->_end = Fragment::Initialize(token);

            // Get the closing parenthesis
            HandleNext();
            
            HandleError(!(token->Type & TokenParenthesisClose),
                        "expected ')' but found '" + token->Value + "'");
        }
        else if (token->Type & TokenPath)
        {
            // Collection evaluation
            tag->_start = Fragment::Initialize(token);
        }
        else
        {
            delete tag;
            context.Error.Set(token,
                              "unexpected for loop identifier: " + token->Value);
            return NULL;
        }

        // * Check for extra modifiers
        //   (limit: <path | number>)? (offset: <path | number>)? (reversed)?
        HandleNext();

        while (!(token->Type & TokenTagClose))
        {
            if (token->Value == "limit")
            {
                // Check for the colon
                HandleNext();
                
                HandleError(!(token->Type & TokenArgumentDelimiter),
                            "expected colon after 'limit' but got " + token->Value);
                
                // Check for the value
                HandleNext();

                HandleError(!(token->Type & TokenInteger) &&
                            !(token->Type & TokenPath),
                            "limit must either be an integer or a variable");

                tag->_limit = Fragment::Initialize(token);
            }
            else if (token->Value == "offset")
            {
                // Check for the colon
                HandleNext();

                HandleError(!(token->Type & TokenArgumentDelimiter),
                            "expected colon after 'offset' but got " + token->Value);

                // Check for the value
                HandleNext();

                HandleError(!(token->Type & TokenInteger) &&
                            !(token->Type & TokenPath),
                            "offset must either be an integer or a variable");

                tag->_offset = Fragment::Initialize(token);
            }
            else if (token->Value == "reversed")
            {
                tag->_reversed = true;
            }
            else
            {
                delete tag;
                context.Error.Set(token,
                                  "expected for loop modifier or end of forloop tag, but got " + token->Value);
                return NULL;
            }

            HandleNext();
        }

        // Parse out the rest of the block
        if (!tag->TryParse(context))
        {
            delete tag;
            return NULL;
        }

        // Return the tag node
        return tag;
    }

    UnknownTagHandling ForTag::TryHandleUnknownTag(Token* token,
                                                   ParserContext& context)
    {
        // Check the token name
        if (token->Value != "endfor")
            return UnknownUnknown;

        // Check that the tag ends after the name
        if (!context.TryNext(token))
        {
            context.Error.Set(token,
                              "unexpected end of file while parsing ending for tag");
            return UnknownError;
        }

        if (!(token->Type & TokenTagClose))
        {
            context.Error.Set(token,
                              "expected end of tag block, found " + token->Value);
            return UnknownError;
        }
        
        // Done
        return UnknownEndParsing;
    }

    inline bool ResolveInteger(RenderContext& context,
                               Fragment*& fragment,
                               int64_t& target)
    {
        if (fragment == NULL)
            return false;

        Fragment* resolvedFragment = fragment;

        if (fragment->GetType() == FragmentTypeContextual)
        {
            resolvedFragment = reinterpret_cast<ContextualFragment*>(fragment)->Resolve(context);
            
            if (resolvedFragment == NULL)
                return false;
        }
        
        if (resolvedFragment->GetType() == FragmentTypeInteger)
        {
            target = reinterpret_cast<IntegerFragment*>(resolvedFragment)->GetValue();
            return true;
        }

        return false;
    }
    
    bool ForTag::TryRender(RenderContext& context)
    {
        // * Resolution of offset and limits
        int64_t offset = 0,
                limit = 0;

        if (this->_offset)
        {
            if (!ResolveInteger(context,
                                this->_offset,
                                offset))
            {
                context.Error.Description = "invalid offset in for loop";
                return false;
            }
            
            // We don't allow negative offsets
            if (offset < 0)
            {
                context.Error.Description = "negative offsets are not allowed in for loops";
                return false;
            }
        }

        if (this->_limit)
        {
            if (!ResolveInteger(context,
                                this->_limit,
                                limit))
            {
                context.Error.Description = "invalid limit in for loop";
                return false;
            }
            
            // We don't allow negative limits
            if (limit < 0)
            {
                context.Error.Description = "negative limits are not allowed";
                return false;
            }
        }

        // * Determining start and end offsets based on
        //   the enumeration type
        ArrayFragment* collection = NULL;

        int64_t start,
                end;

        switch (this->_enumeration)
        {
        case ForCollectionEnumeration:
            {
                // Resolve the collection
                {
                    if ((!this->_start) ||
                        (this->_start->GetType() != FragmentTypeContextual))
                        return true;
                    
                    Fragment* collectionBase = reinterpret_cast<ContextualFragment*>(this->_start)->Resolve(context);
                    
                    if ((!collectionBase) ||
                        (collectionBase->GetType() != FragmentTypeArray))
                        return true;
                    
                    collection = reinterpret_cast<ArrayFragment*>(collectionBase);
                }

                // If this is an empty collection, let's not give a fuck about it
                if (collection->Count() == 0)
                    return true;

                // Determine a start and end offset of the collection
                start = 0;
                end = collection->Count() - 1;

                // Apply an offset if possible
                if (this->_offset)
                {
                    // If we're offseting outside the range, let's just return from this point
                    start += offset;

                    if (start > end)
                        return true;
                }

                // Apply a limit if possible
                if (this->_limit)
                {
                    // Check if we're overstepping here
                    end = (start + limit - 1 > end ?
                           end : 
                           start + limit - 1);
                }
                
                break;
            }

        case ForRangeEnumeration:
            {
                // Get the start of the range
                if (!ResolveInteger(context,
                                    this->_start,
                                    start))
                {
                    context.Error.Description = "invalid range start in for loop";
                    return false;
                }
                
                // Get the end of the range
                if (!ResolveInteger(context,
                                    this->_end,
                                    end))
                {
                    context.Error.Description = "invalid range end in for loop";
                    return false;
                }

                // Apply an offset to the start and end values
                if (this->_offset)
                {
                    // If we're offseting outside the range, let's just return from this point
                    if (((start > end) &&
                         (start - offset < end)) ||
                        ((start <= end) &&
                         (start + offset > end)))
                        return true;
                    
                    // Offset the range
                    start += (start > end ? -offset : offset);
                }

                // Apply a limit
                if (this->_limit)
                {
                    // Apply the limit
                    int64_t rangeAbsolute = (start > end ?
                                             start - end + 1 :
                                             end - start + 1);

                    if (limit < rangeAbsolute)
                        end += (start > end ?
                                rangeAbsolute - limit :
                                limit - rangeAbsolute);
                }
                
                break;
            }
        }

        // Swap the start and end if necessary
        if (this->_reversed)
        {
            int64_t swapping = start;
            start = end;
            end = swapping;
        }

        // * Rendering

        // Construct a forloop variable and the identifying variables
        HashFragment* forloopVariable = new HashFragment();

        IntegerFragment* forloopLength = new IntegerFragment(start > end ?
                                                             start - end + 1 : 
                                                             end - start + 1),
                       * forloopIndex = new IntegerFragment(1),
                       * forloopIndex0 = new IntegerFragment(0),
                       * forloopRIndex = new IntegerFragment(1),
                       * forloopRIndex0 = new IntegerFragment(0);
        
        BooleanFragment* forloopFirst = new BooleanFragment(true),
                       * forloopLast = new BooleanFragment(false),
                       * forloopOdd = new BooleanFragment(true),
                       * forloopEven = new BooleanFragment(false);
        
        
        // Assign each of the variables to the forloop hash
        forloopVariable->Set("length", forloopLength);
        forloopVariable->Set("index", forloopIndex);
        forloopVariable->Set("index0", forloopIndex0);
        forloopVariable->Set("rindex", forloopRIndex);
        forloopVariable->Set("rindex0", forloopRIndex0);
        forloopVariable->Set("first", forloopFirst);
        forloopVariable->Set("last", forloopLast);
        forloopVariable->Set("odd", forloopOdd);
        forloopVariable->Set("even", forloopEven);
        
        // Swap the forloop variable into the context
        Fragment* forloopVariableOld = context.Data->Swap("forloop",
                                                          forloopVariable);
        
        // Iterate through all the possible solutions
        int64_t current = start,
                step = (start > end ?
                        -1 :
                        1),
                currentLimit = end + step,
                index = 0,
                rindex = (start > end ? start - end : end - start);

        // Determine if any contextual variable is needed
        Fragment* contextualFragment = NULL,
                * oldContextualFragment = NULL;

        if (this->_enumeration == ForRangeEnumeration)
        {
            contextualFragment = new IntegerFragment(0);
            oldContextualFragment = context.Data->Swap(this->_targetName,
                                                       contextualFragment);
        }
        else
            oldContextualFragment = context.Data->Swap(this->_targetName,
                                                       NULL);

        while (current != currentLimit)
        {
            // Swap in or update the contextual variable
            if (this->_enumeration == ForRangeEnumeration)
                reinterpret_cast<IntegerFragment*>(contextualFragment)->SetValue(current);
            else
                context.Data->Swap(this->_targetName,
                                   collection->Get(current));
            
            // Update the forloop variable
            forloopIndex->SetValue(index + 1);
            forloopIndex0->SetValue(index);
            forloopRIndex->SetValue(rindex + 1);
            forloopRIndex0->SetValue(rindex);
            forloopFirst->SetValue(index == 0);
            forloopLast->SetValue(rindex == 0);
            forloopOdd->SetValue(index % 2 == 0);
            forloopEven->SetValue(index % 2 == 1);
            
            // Render this block
            if (!BranchNode::TryRender(context))
                return false;
            
            // Go to the next step in the iteration
            current += step;
            index++;
            rindex--;
        }

        // Swap the old contextual fragment back in
        context.Data->Swap(this->_targetName,
                           oldContextualFragment);
        
        if (contextualFragment)
            delete contextualFragment;
        
        // Get rid of the forloop variable
        context.Data->Swap("forloop",
                           forloopVariableOld);
        
        delete forloopVariable;

        return true;
    }
}
