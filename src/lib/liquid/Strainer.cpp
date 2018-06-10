#include "Strainer.hpp"

#include "IfTag.hpp"
#include "ForTag.hpp"
#include "CycleTag.hpp"
#include "AssignTag.hpp"
#include "CaptureTag.hpp"
#include "CaseTag.hpp"

#include "Filters/StandardFilters.hpp"

namespace Liquid
{
    Strainer::Strainer()
    {
        // Register standard tags
        this->_tagHash.insert(StrainerTagPair("if",
                                              &IfTag::Initialize));
        this->_tagHash.insert(StrainerTagPair("unless",
                                              &IfTag::Initialize));
        this->_tagHash.insert(StrainerTagPair("for",
                                              &ForTag::Initialize));
        this->_tagHash.insert(StrainerTagPair("cycle",
                                              &CycleTag::Initialize));
        this->_tagHash.insert(StrainerTagPair("assign",
                                              &AssignTag::Initialize));
        this->_tagHash.insert(StrainerTagPair("capture",
                                              &CaptureTag::Initialize));
        this->_tagHash.insert(StrainerTagPair("case",
                                              &CaseTag::Initialize));

        // Register standard filters
        this->_filterHash.insert(StrainerFilterPair("img_tag",
                                                    &StandardFilters::ImgTag));
        this->_filterHash.insert(StrainerFilterPair("script_tag",
                                                    &StandardFilters::ScriptTag));
        this->_filterHash.insert(StrainerFilterPair("stylesheet_tag",
                                                    &StandardFilters::StylesheetTag));
        this->_filterHash.insert(StrainerFilterPair("plus",
                                                    &StandardFilters::Plus));
        this->_filterHash.insert(StrainerFilterPair("minus",
                                                    &StandardFilters::Minus));
        this->_filterHash.insert(StrainerFilterPair("times",
                                                    &StandardFilters::Times));
        this->_filterHash.insert(StrainerFilterPair("divided_by",
                                                    &StandardFilters::DividedBy));
        this->_filterHash.insert(StrainerFilterPair("append",
                                                    &StandardFilters::Append));
        this->_filterHash.insert(StrainerFilterPair("prepend",
                                                    &StandardFilters::Prepend));
        this->_filterHash.insert(StrainerFilterPair("downcase",
                                                    &StandardFilters::Downcase));
        this->_filterHash.insert(StrainerFilterPair("upcase",
                                                    &StandardFilters::Upcase));
        this->_filterHash.insert(StrainerFilterPair("capitalize",
                                                    &StandardFilters::Capitalize));
        this->_filterHash.insert(StrainerFilterPair("truncate",
                                                    &StandardFilters::Truncate));
        this->_filterHash.insert(StrainerFilterPair("truncatewords",
                                                    &StandardFilters::TruncateWords));
        this->_filterHash.insert(StrainerFilterPair("first",
                                                    &StandardFilters::First));
        this->_filterHash.insert(StrainerFilterPair("last",
                                                    &StandardFilters::Last));
        this->_filterHash.insert(StrainerFilterPair("join",
                                                    &StandardFilters::Join));
        this->_filterHash.insert(StrainerFilterPair("size",
                                                    &StandardFilters::Size));
        this->_filterHash.insert(StrainerFilterPair("strip_newlines",
                                                    &StandardFilters::StripNewlines));
        this->_filterHash.insert(StrainerFilterPair("newline_to_br",
                                                    &StandardFilters::NewlineToBr));
        this->_filterHash.insert(StrainerFilterPair("replace",
                                                    &StandardFilters::Replace));
        this->_filterHash.insert(StrainerFilterPair("replace_first",
                                                    &StandardFilters::ReplaceFirst));
        this->_filterHash.insert(StrainerFilterPair("remove",
                                                    &StandardFilters::Remove));
        this->_filterHash.insert(StrainerFilterPair("remove_first",
                                                    &StandardFilters::RemoveFirst));
        this->_filterHash.insert(StrainerFilterPair("strip_html",
                                                    &StandardFilters::StripHtml));
        this->_filterHash.insert(StrainerFilterPair("escape",
                                                    &StandardFilters::Escape));
        this->_filterHash.insert(StrainerFilterPair("date",
                                                    &StandardFilters::Date));
        this->_filterHash.insert(StrainerFilterPair("url_encode",
                                                    &StandardFilters::UrlEncode));
        this->_filterHash.insert(StrainerFilterPair("sort",
                                                    &StandardFilters::Sort));
    }

    TagInitializer Strainer::ResolveTagInitializer(std::string& name)
    {
        // Try to find the tag name
        StrainerTagIterator iterator = this->_tagHash.find(name);

        if (iterator == this->_tagHash.end())
            return NULL;
        else
            return iterator->second;
    }

    FilterFunction Strainer::ResolveFilterFunction(std::string& name)
    {
        // Try to find the tag name
        StrainerFilterIterator iterator = this->_filterHash.find(name);

        if (iterator == this->_filterHash.end())
            return NULL;
        else
            return iterator->second;
    }

    void Strainer::RegisterTag(std::string name,
                               TagInitializer tagInitializer)
    {
        this->_tagHash.insert(StrainerTagPair(name,
                                              tagInitializer));
    }
}
