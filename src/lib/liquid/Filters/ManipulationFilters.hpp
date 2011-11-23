#include <locale>
#include <ctime>

#include "FilterBase.hpp"

#ifndef __LIQUID_FILTERS_MANIPULATIONFILTERS
#define __LIQUID_FILTERS_MANIPULATIONFILTERS
namespace Liquid
{
    namespace StandardFilters
    {
        /// append(input, added)
        
        /// As per http://wiki.shopify.com/Append
        static Fragment* Append(Fragment* input,
                                std::vector<Fragment*>& arguments)
        {
            if (arguments.size() < 1)
                return new NullFragment();

            return new StringFragment(input->ToString() + arguments[0]->ToString());
        }


        /// prepend(input, added)
        
        /// As per http://wiki.shopify.com/Prepend
        static Fragment* Prepend(Fragment* input,
                                 std::vector<Fragment*>& arguments)
        {
            if (arguments.size() < 1)
                return new NullFragment();

            return new StringFragment(arguments[0]->ToString() + input->ToString());
        }


        /// downcase(input)
        
        /// As per http://wiki.shopify.com/Downcase
        static Fragment* Downcase(Fragment* input,
                                  std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString(),
                        result;

            std::locale locale;
            for (std::size_t index = 0; index < representation.length(); index++)
                result += std::tolower(representation[index]);

            return new StringFragment(result);
        }


        /// upcase(input)
        
        /// As per http://wiki.shopify.com/Upcase
        static Fragment* Upcase(Fragment* input,
                                std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString(),
                        result;

            std::locale locale;
            for (std::size_t index = 0; index < representation.length(); index++)
                result += std::toupper(representation[index]);

            return new StringFragment(result);
        }


        /// capitalize(input)
        
        /// As per http://wiki.shopify.com/Capitalize
        static Fragment* Capitalize(Fragment* input,
                                    std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString();

            std::locale locale;
            for (std::size_t index = 0; index < representation.length(); index++)
            {
                if (std::isspace(representation[index]))
                    continue;

                representation[index] = std::toupper(representation[index]);

                break;
            }
            
            return new StringFragment(representation);
        }


        /// truncate(input, characters = 100, end = "...")
        
        /// As per http://wiki.shopify.com/Truncate
        static Fragment* Truncate(Fragment* input,
                                  std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString();
            
            // Parse the length to truncate to
            std::size_t characters = 100;
            
            if (arguments.size() > 0)
            {
                Fragment* charactersFragment = arguments[0];
                
                if ((charactersFragment->GetType() == FragmentTypeInteger) ||
                    (charactersFragment->GetType() == FragmentTypeFloat))
                {
                    int64_t charactersRaw = (charactersFragment->GetType() == FragmentTypeInteger ? 
                                             reinterpret_cast<IntegerFragment*>(charactersFragment)->GetValue() :
                                             int64_t(reinterpret_cast<FloatFragment*>(charactersFragment)->GetValue()));
                    
                    if (charactersRaw <= 0)
                        return new StringFragment("");

                    characters = charactersRaw;
                }
            }

            // Parse the ending
            std::string ending = "...";

            if (arguments.size() > 1)
                ending = arguments[1]->ToString();

            // Cut and end!
            if (characters < representation.length())
                representation = representation.substr(0, characters) + ending;
            
            return new StringFragment(representation);
        }


        /// first(array)
        
        /// As per http://wiki.shopify.com/First
        static Fragment* First(Fragment* input,
                               std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeArray)
                return new NullFragment();

            ArrayFragment* array = reinterpret_cast<ArrayFragment*>(input);

            if (array->Count() == 0)
                return new NullFragment();

            Fragment* toClone = array->Get(0);
            return (toClone == NULL ?
                    new NullFragment() : 
                    toClone->Clone());
        }


        /// last(array)
        
        /// As per http://wiki.shopify.com/Last
        static Fragment* Last(Fragment* input,
                              std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeArray)
                return new NullFragment();

            ArrayFragment* array = reinterpret_cast<ArrayFragment*>(input);

            if (array->Count() == 0)
                return new NullFragment();

            Fragment* toClone = array->Get(array->Count() - 1);
            return (toClone == NULL ?
                    new NullFragment() : 
                    toClone->Clone());
        }


        /// join(input, segmenter = " ")
        
        /// As per http://wiki.shopify.com/Join
        static Fragment* Join(Fragment* input,
                              std::vector<Fragment*>& arguments)
        {
            // Initially check things
            if (input->GetType() != FragmentTypeArray)
                return new NullFragment();

            ArrayFragment* array = reinterpret_cast<ArrayFragment*>(input);

            if (array->Count() == 0)
                return new StringFragment("");

            // Get the segmenter
            std::string result,
                        segmenter = " ";
            
            if (arguments.size() > 0)
                segmenter = arguments[0]->ToString();

            // Produce the result
            Fragment* toOutput;
            for (std::size_t index = 0; index < array->Count(); index++)
            {
                toOutput = array->Get(index);

                if (toOutput != NULL)
                    result += (result.empty() ? std::string() : segmenter) + toOutput->ToString();
            }

            return new StringFragment(result);
        }


        /// size(input)
        
        /// As per http://wiki.shopify.com/Size
        static Fragment* Size(Fragment* input,
                              std::vector<Fragment*>& arguments)
        {
            if (input->GetType() == FragmentTypeString)
                return new IntegerFragment(reinterpret_cast<StringFragment*>(input)->GetValue().length());
            if (input->GetType() == FragmentTypeArray)
                return new IntegerFragment(reinterpret_cast<ArrayFragment*>(input)->Count());

            return new IntegerFragment(0);
        }


        /// strip_newlines(input)

        /// As per http://wiki.shopify.com/Strip_newlines
        static Fragment* StripNewlines(Fragment* input,
                                       std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString(),
                        result;

            char current;

            for (std::size_t index = 0; index < representation.length(); index++)
            {
                current = representation[index];
                
                if ((current != '\n') &&
                    (current != '\r'))
                    result += current;
                else if (current == '\n')
                    result += " ";
            }

            return new StringFragment(result);
        }

        
        /// newline_to_br(input)

        /// As per http://wiki.shopify.com/Newline_to_br
        static Fragment* NewlineToBr(Fragment* input,
                                     std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString(),
                        result;

            char current;

            for (std::size_t index = 0; index < representation.length(); index++)
            {
                current = representation[index];
                if (current == '\n')
                    result += "<br />";

                result += current;
            }

            return new StringFragment(result);
        }


        /// replace(input, substring, replacement)

        /// As per http://wiki.shopify.com/Replace
        static Fragment* Replace(Fragment* input,
                                 std::vector<Fragment*>& arguments)
        {
            if (arguments.size() < 1)
                return new StringFragment(input->ToString());

            std::string search = arguments[0]->ToString(),
                        replace = (arguments.size() > 1 ?
                                   arguments[1]->ToString() :
                                   ""),
                        result = input->ToString();

            std::size_t position;
            while ((position = result.find(search)) != std::string::npos)
            {
                result.replace(position,
                               search.size(),
                               replace);
            }

            return new StringFragment(result);
        }


        /// replace_first(input, substring, replacement)

        /// As per http://wiki.shopify.com/Replace_first
        static Fragment* ReplaceFirst(Fragment* input,
                                      std::vector<Fragment*>& arguments)
        {
            if (arguments.size() < 1)
                return new StringFragment(input->ToString());

            std::string search = arguments[0]->ToString(),
                        replace = (arguments.size() > 1 ?
                                   arguments[1]->ToString() :
                                   ""),
                        result = input->ToString();

            std::size_t position;
            if ((position = result.find(search)) != std::string::npos)
            {
                result.replace(position,
                               search.size(),
                               replace);
            }

            return new StringFragment(result);
        }


        /// remove(input, substring, replacement)

        /// As per http://wiki.shopify.com/Remove
        static Fragment* Remove(Fragment* input,
                                std::vector<Fragment*>& arguments)
        {
            if (arguments.size() < 1)
                return new StringFragment(input->ToString());

            std::string search = arguments[0]->ToString(),
                        result = input->ToString();

            std::size_t position;
            while ((position = result.find(search)) != std::string::npos)
            {
                result.erase(position,
                             search.size());
            }

            return new StringFragment(result);
        }


        /// remove_first(input, substring, replacement)

        /// As per http://wiki.shopify.com/Remove_first
        static Fragment* RemoveFirst(Fragment* input,
                                     std::vector<Fragment*>& arguments)
        {
            if (arguments.size() < 1)
                return new StringFragment(input->ToString());

            std::string search = arguments[0]->ToString(),
                        result = input->ToString();

            std::size_t position;
            if ((position = result.find(search)) != std::string::npos)
            {
                result.erase(position,
                             search.size());
            }

            return new StringFragment(result);
        }


        /// strip_html(input)
        
        /// As per http://wiki.shopify.com/Strip_html
        static Fragment* StripHtml(Fragment* input,
                                   std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString(),
                        result;

            char current,
                 stringWrapper = 0x00;
            bool inHtml = false;
            
            for (std::size_t index = 0; index < representation.length(); index++)
            {
                current = representation[index];

                if (stringWrapper)
                {
                    if (current == stringWrapper)
                        stringWrapper = 0x00;
                }
                else if (inHtml)
                {
                    if ((current == '"') ||
                        (current == '\''))
                        stringWrapper = current;
                    else if (current == '>')
                        inHtml = false;
                }
                else
                {
                    if (current == '<')
                        inHtml = true;
                    else
                        result += current;
                }
            }

            return new StringFragment(result);
        }


        /// escape(input)
        
        /// As per http://wiki.shopify.com/Escape
        static Fragment* Escape(Fragment* input,
                                std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString(),
                        result;

            char current;
            bool lastSpace = false;
            
            for (std::size_t index = 0; index < representation.length(); index++)
            {
                current = representation[index];

                if (current == ' ')
                {
                    if (lastSpace)
                        result += "&nbsp;";
                    else
                    {
                        result += " ";
                        lastSpace = true;
                    }
                }
                else
                {
                    if (current == '"')
                        result += "&quot;";
                    else if (current == '&')
                        result += "&amp;";
                    else if (current == '<')
                        result += "&lt;";
                    else if (current == '>')
                        result += "&gt;";
                    else
                        result += current;

                    lastSpace = false;
                }
            }

            return new StringFragment(result);
        }


        /// date(input, fmt)
        static Fragment* Date(Fragment* input,
                              std::vector<Fragment*>& arguments)
        {
            // Check for the format argument
            if (arguments.size() == 0)
                return new NullFragment();

            // Check the input
            time_t inputTime;

            if (input->GetType() == FragmentTypeString)
            {
                std::string stringTime = input->ToString();

                if (stringTime == "now")
                    inputTime = time(NULL);
                else
                    return new NullFragment();
            }
            else if (input->GetType() == FragmentTypeInteger)
                inputTime = reinterpret_cast<IntegerFragment*>(input)->GetValue();
            else if (input->GetType() == FragmentTypeFloat)
                inputTime = reinterpret_cast<FloatFragment*>(input)->GetValue();
            else
                return new NullFragment();

            // Convert the input
            struct tm inputTm;

            if (localtime_r(&inputTime,
                            &inputTm) == NULL)
                return new NullFragment();

            // Format the output
            char outputBuffer[256];
            std::string outputFormat = arguments[0]->ToString();

            std::size_t formattedLength = strftime(outputBuffer,
                                                   255,
                                                   outputFormat.c_str(),
                                                   &inputTm);

            return (formattedLength == 0 ?
                    (Fragment*)new NullFragment() :
                    (Fragment*)new StringFragment(std::string(outputBuffer,
                                                              formattedLength)));
        }
    }
}
#endif
