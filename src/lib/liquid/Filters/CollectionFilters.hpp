#include <algorithm>
#include <locale>
#include <vector>

#include "FilterBase.hpp"

#ifndef __LIQUID_FILTERS_COLLECTIONFILTERS
#define __LIQUID_FILTERS_COLLECTIONFILTERS
namespace Liquid
{
    namespace StandardFilters
    {
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


        static bool SortFragmentLessThan(Fragment* a, Fragment* b) {
            return a->Compare(b, ConditionalLessThan);
        }


        /// sort(array)
        static Fragment* Sort(Fragment* input,
                              std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeArray)
                return new NullFragment();

            ArrayFragment* array = reinterpret_cast<ArrayFragment*>(input);

            if (array->Count() < 2)
                return input;

            // Build a vector of fragments to sort.
            std::vector<Fragment*> sortable;

            for (std::size_t i = 0; i < array->Count(); ++i)
            {
                sortable.push_back(array->Get(i));
            }

            // Sort the fragments.
            std::sort(sortable.begin(), sortable.end(), SortFragmentLessThan);

            // Construct the resulting array.
            ArrayFragment* result = new ArrayFragment();

            for (std::vector<Fragment*>::iterator it = sortable.begin(); it != sortable.end(); ++it)
            {
                result->Add((*it)->Clone());
            }

            return result;
        }
    }
}
#endif
