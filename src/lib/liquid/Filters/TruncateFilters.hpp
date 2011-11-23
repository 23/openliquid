#include <locale>
#include <ctime>

#include "FilterBase.hpp"

#ifndef __LIQUID_FILTERS_TRUNCATEFILTER
#define __LIQUID_FILTERS_TRUNCATEFILTER
namespace Liquid
{
    namespace StandardFilters
    {
        /// Table of delimiter characters
        static const bool WordDelimiterTable[256] = {
/*         nul      soh      stx      etx      eot      enq      ack      bel  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*         bs       ht       nl       vt       np       cr       so       si   */
            0,       1,       1,       0,       0,       1,       0,       0,
/*         dle      dc1      dc2      dc3      dc4      nak      syn      etb */
            0,       0,       0,       0,       0,       0,       0,       0,
/*         can      em       sub      esc      fs       gs       rs       us  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*         sp        !        "        #        $        %        &        '  */
            1,       1,       1,       0,       0,       0,       0,       1,
/*          (        )        *        +        ,        -        .        /  */
            1,       1,       0,       0,       1,       0,       1,       0,
/*          0        1        2        3        4        5        6        7  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          8        9        :        ;        <        =        >        ?  */
            0,       0,       1,       0,       0,       0,       0,       0,
/*          @        A        B        C        D        E        F        G  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          H        I        J        K        L        M        N        O  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          P        Q        R        S        T        U        V        W  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          X        Y        Z        [        \        ]        ^        _  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          `        a        b        c        d        e        f        g  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          h        i        j        k        l        m        n        o  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          p        q        r        s        t        u        v        w  */
            0,       0,       0,       0,       0,       0,       0,       0,
/*          x        y        z        {        |        }        ~       del */
            0,       0,       0,       0,       0,       0,       0,       0,
        };


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


        /// truncatewords(input, words = 15, end = "...")
        
        /// As per http://wiki.shopify.com/Truncatewords
        static Fragment* TruncateWords(Fragment* input,
                                       std::vector<Fragment*>& arguments)
        {
            std::string representation = input->ToString();
            
            // Parse the length to truncate to
            std::size_t words = 15;
            
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

                    words = charactersRaw;
                }
            }

            // Parse the ending
            std::string ending = "...";

            if (arguments.size() > 1)
                ending = arguments[1]->ToString();

            // Cut and end!
            char current;
            std::size_t wordCount = 1,
                        resultLength = 0;
            bool lastWasDelimiter = false;

            for (std::size_t index = 0; index < representation.length(); index++)
            {
                current = representation[index];
                
                if (WordDelimiterTable[(unsigned char)current])
                {
                    if (!lastWasDelimiter)
                    {
                        wordCount++;
                        lastWasDelimiter = true;
                        
                        if (wordCount > words)
                            break;
                    }
                }
                else if (lastWasDelimiter)
                    lastWasDelimiter = false;
                
                resultLength++;
            }

            std::string result = representation.substr(0,
                                                       resultLength);

            if (wordCount > words)
                result = result + ending;
            
            return new StringFragment(result);
        }
    }
}
#endif
