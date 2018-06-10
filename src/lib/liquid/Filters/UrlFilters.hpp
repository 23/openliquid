#include "FilterBase.hpp"

#ifndef __LIQUID_FILTERS_URLFILTERS
#define __LIQUID_FILTERS_URLFILTERS
namespace Liquid
{
    namespace StandardFilters
    {
        static const bool URL_ENCODE_SAFE[] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
            0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };

        /// url_encode(parameter)

        /// As per https://help.shopify.com/themes/liquid/filters/string-filters#url_encode
        static Fragment* UrlEncode(Fragment* input,
                                   std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeString)
                return new NullFragment();

            // Allocate a large enough buffer. This is the simplest, least efficient approach but it avoids the
            // complexity of growing buffers.
            static const char hexChars[] = "0123456789ABCDEF";
            const std::string unescapedValue = input->ToString();
            char* escapedValue = (char*)malloc(unescapedValue.length() * 3 + 1);
            std::size_t escapedLength = 0;

            for (std::string::const_iterator it = unescapedValue.begin(); it != unescapedValue.end(); ++it)
            {
                const char chr = *it;

                if (URL_ENCODE_SAFE[int(chr)])
                {
                    escapedValue[escapedLength++] = chr;
                }
                else if (chr == ' ')
                {
                    escapedValue[escapedLength++] = '+';
                }
                else
                {
                    escapedValue[escapedLength++] = '%';
                    escapedValue[escapedLength++] = hexChars[(chr >> 4) & 0xf];
                    escapedValue[escapedLength++] = hexChars[chr & 0xf];
                }
            }

            // Construct the resulting fragment.
            Fragment* result = new StringFragment(std::string(escapedValue, escapedLength));
            free(escapedValue);

            return result;
        }
    }
}
#endif
