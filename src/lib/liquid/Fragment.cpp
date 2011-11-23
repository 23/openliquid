#include "Expressions.hpp"

#include "BaseFragment.hpp"
#include "DoubleFragment.hpp"
#include "EmptyFragment.hpp"
#include "IntegerFragment.hpp"
#include "NullFragment.hpp"
#include "StringFragment.hpp"
#include "BooleanFragment.hpp"
#include "HashFragment.hpp"
#include "ArrayFragment.hpp"
#include "ContextualFragment.hpp"

namespace Liquid
{
    std::string UnescapeString(std::string& markup)
    {
        // Assumption: the string has already been validated
        char container = markup[0];

        // Go through all the characters
        std::string result;
        std::size_t index = 1,
                    indexMax = markup.length() - 1;
        
        while (index < indexMax)
        {
            if (markup[index] == '\\')
            {
                index++;

                switch (markup[index])
                {
                case 'n':
                    result += '\n';
                    break;

                case 'r':
                    result += '\r';
                    break;

                case 't':
                    result += '\t';
                    break;

                default:
                    result += markup[index];
                    break;
                }
            }
            else if (markup[index] == container)
            {
                return result;
            }
            else
                result += markup[index];

            index++;
        }

        return result;
    }

    Fragment* Fragment::Initialize(std::string markup)
    {
        // Null variables
        if ((markup == "null") ||
            (markup == "nil"))
            return new NullFragment();
        
        // Empty variables
        if (markup == "empty")
            return new EmptyFragment();

        // Boolean variables
        if (markup == "true")
            return new BooleanFragment(true);
        if (markup == "false")
            return new BooleanFragment(false);

        // Integer variables
        if (Expressions::IntegerFragment.FullMatch(markup))
            return new IntegerFragment(markup);
        
        // Floating point variables
        if (Expressions::FloatFragment.FullMatch(markup))
            return new FloatFragment(markup);

        // String variables
        if (Expressions::StringFragment.FullMatch(markup))
            return new StringFragment(UnescapeString(markup));

        // Contextual variables

        return NULL;
    }

    Fragment* Fragment::Initialize(Token* token)
    {
        if (token->Type & TokenString)
            return new StringFragment(UnescapeString(token->Value));
        if (token->Type & TokenInteger)
            return new IntegerFragment(token->Value);
        if (token->Type & TokenFloat)
            return new FloatFragment(token->Value);
        if (token->Type & TokenTrue)
            return new BooleanFragment(true);
        if (token->Type & TokenFalse)
            return new BooleanFragment(false);
        if (token->Type & TokenNull)
            return new NullFragment();
        if (token->Type & TokenEmpty)
            return new EmptyFragment();
        if (token->Type & TokenPath)
            return new ContextualFragment(token->Value);

        throw;
    }
}
