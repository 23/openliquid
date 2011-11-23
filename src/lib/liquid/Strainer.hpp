#include <string>
#include <map>
#include <vector>

#include "Node.hpp"

#ifndef __LIQUID_STRAINER
#define __LIQUID_STRAINER
namespace Liquid
{
    class ParserContext;
    class Token;
    class Fragment;

    typedef Node* (*TagInitializer)(Token* token,
                                    ParserContext& context);
    typedef Fragment* (*FilterFunction)(Fragment* input,
                                        std::vector<Fragment*>& arguments);

    typedef std::map<std::string, TagInitializer> StrainerTagMap;
    typedef StrainerTagMap::iterator StrainerTagIterator;
    typedef std::pair<std::string, TagInitializer> StrainerTagPair;

    typedef std::map<std::string, FilterFunction> StrainerFilterMap;
    typedef StrainerFilterMap::iterator StrainerFilterIterator;
    typedef std::pair<std::string, FilterFunction> StrainerFilterPair;
    
    /// Strainer

    /// Manages the resolution of tags and filters for a given
    /// context. Tags must be registered prior to parsing, while
    /// filters can be registered before rendering as well.
    class Strainer
    {
    public:
        /// Initialize a strainer

        /// Sets up the strainer with all the standard tags
        /// and filters
        Strainer();


        /// Register a non-standard tag
        
        /// @param name Name of the tag in lower case
        /// @param tagInitializer Pointer to the initializer
        void RegisterTag(std::string name,
                         TagInitializer tagInitializer);

        
        /// Resolve a tag initializer

        /// @param name Name of the tag to be resolved in lower case
        /// @returns the pointer to the tag initializer on success, otherwise NULL
        TagInitializer ResolveTagInitializer(std::string& name);


        /// Resolve a filter function

        /// @param name Name of the filter to be resolved in lower case
        /// @returns the pointer to the filter function on success, otherwise NULL
        FilterFunction ResolveFilterFunction(std::string& name);
    private:
        StrainerTagMap _tagHash; ///< Local tag hash map
        StrainerFilterMap _filterHash; ///< Local filter hash map
    };
}
#endif
