#include "ParserError.hpp"
#include "RenderError.hpp"
#include "Document.hpp"
#include "Fragment.hpp"

#ifndef __LIQUID_TEMPLATE
#define __LIQUID_TEMPLATE
namespace Liquid
{
    class TemplateCache
    {

    };
    
    class FileSystem
    {

    };

    /// Primary representation of a template

    /// Cannot be instantiated in other ways than using the TryParse
    /// function family and can furthermore not be copied on assignment as
    /// the class makes heavy use of pointers to keep its data.
    /// To utilize the include functionality, a virtual file system must
    /// be supplied and the filename of the file to be parsed must be
    /// passed to TryParseFile.
    class Template
    {
    public:
        /// Try to parse a single template from a string

        /// Removes the possibility to utilize includes in both parsing
        /// and rendering as no virtual file system is present.
        /// 
        /// @param source Source code of the template
        /// @param strainer Reference to a strainer, that must persist for the entire lifetime of the template
        /// @param error Reference to an error structure to hold the error description upon failure
        /// @returns a pointer to a Template instance if successful, otherwise NULL
        static Template* Parse(std::string source,
                               Strainer& strainer,
                               ParserError& error);


        /// Try to render a template

        /// @param data Root data node
        /// @param error Reference to a structure to hold the error description upon failure
        /// @param result Reference to a string to hold the rendering output upon success
        /// @returns a string representation of the rendered template
        bool TryRender(HashFragment* data,
                       RenderError& error,
                       std::string& result);
        

        /// Dispose of a template instance
        ~Template();
    private:
        /// Initialize a new template instance
        
        /// A local cache will be initialized if no cache is supplied
        /// as an argument, hence only in the case of a root template.
        /// 
        /// @param strainer Reference to a strainer, that must persist for the entire lifetime of the template
        /// @param filesystem File system to use
        /// @param cache Optional pointer to a cache instance to use for filesystem traversal
        Template(Strainer& strainer,
                 TemplateCache* cache = NULL,
                 FileSystem* filesystem = NULL);


        /// Internally parse a template from a string

        /// Updates the error scope to represent this template
        /// 
        /// @param source Reference to the source code of the template
        /// @param error Reference to an error structure
        /// @returns true if parsing succeeded, otherwise false
        bool TryParseInternal(std::string& source,
                              ParserError& error);
        
        
        Strainer& _strainer; ///< Template strainer
        Document _root; ///< Template root node
        TemplateCache* _cache; ///< Local template cache
        FileSystem* _filesystem; ///< Local file system reference -- unnecessary?
    };
}
#endif
