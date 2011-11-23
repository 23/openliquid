#include "FilterBase.hpp"

#ifndef __LIQUID_FILTERS_HTMLFILTERS
#define __LIQUID_FILTERS_HTMLFILTERS
namespace Liquid
{
    namespace StandardFilters
    {
        /// img_tag(url, alt="")
        
        /// As per http://wiki.shopify.com/Img_tag
        static Fragment* ImgTag(Fragment* input,
                                std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeString)
                return new NullFragment();
            
            return new StringFragment("<img src=\"" + input->ToString() + "\" alt=\"" + (arguments.size() > 0 ? arguments[0]->ToString() : std::string("")) + "\" />");
        }


        /// script_tag(url)
        
        /// As per http://wiki.shopify.com/Script_tag
        static Fragment* ScriptTag(Fragment* input,
                                   std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeString)
                return new NullFragment();
            
            return new StringFragment("<script src=\"" + input->ToString() + "\" type=\"text/javascript\"></script>");
        }


        /// stylesheet_tag(url)
        
        /// As per http://wiki.shopify.com/Stylesheet_tag
        static Fragment* StylesheetTag(Fragment* input,
                                       std::vector<Fragment*>& arguments)
        {
            if (input->GetType() != FragmentTypeString)
                return new NullFragment();
            
            return new StringFragment("<link href=\"" + input->ToString() + "\" rel=\"stylesheet\" type=\"text/javascript\" media=\"all\" />");
        }
    }
}
#endif
