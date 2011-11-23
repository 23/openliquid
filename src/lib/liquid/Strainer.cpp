#include "Strainer.hpp"

#include "IfTag.hpp"
#include "ForTag.hpp"
#include "CycleTag.hpp"
#include "AssignTag.hpp"
#include "CaptureTag.hpp"
#include "CaseTag.hpp"

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

    void Strainer::RegisterTag(std::string name,
                               TagInitializer tagInitializer)
    {
        this->_tagHash.insert(StrainerTagPair(name,
                                              tagInitializer));
    }
}
