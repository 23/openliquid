#include "Template.hpp"
#include "Lexer.hpp"

namespace Liquid
{
    Template* Template::Parse(std::string source,
                              Strainer& strainer,
                              ParserError& error)
    {
        // Initialize a template instance
        Template* templ = new Template(strainer);

        // Do internal parsing of the source
        if (!templ->TryParseInternal(source,
                                     error))
        {
            // An error occurred during parsing
            delete templ;
            return NULL;
        }

        // Finally, return the template instance
        return templ;
    }

    Template::Template(Strainer& strainer,
                       TemplateCache* cache,
                       FileSystem* filesystem)
        :   _strainer(strainer),
            _cache(cache ? NULL : new TemplateCache()),
            _filesystem(filesystem)
    {
        
    }

    Template::~Template()
    {
        // Dispose the cache if necessary
        if (this->_cache)
            delete this->_cache;
    }

    bool Template::TryParseInternal(std::string& source,
                                    ParserError& error)
    {
        // Tokenize the source
        TokenList tokens;

        if (!Lexer::TryAnalyze(source,
                               tokens,
                               error))
            return false;

        // Construct a parsing context
        ParserContext parserContext(tokens,
                                    this->_strainer,
                                    error);

        // Start building the AST
        if (!this->_root.TryParse(parserContext))
            return false;

        // Yay!
        return true;
    }

    bool Template::TryRender(HashFragment* data,
                             RenderError& error,
                             std::string& result)
    {
        // Initialize a render context
        RenderContext renderContext(data,
                                    this->_strainer,
                                    error);
        
        // Try to render the root node
        if (!this->_root.TryRender(renderContext))
            return false;
        
        // Assign the result to the output
        result = renderContext.Result.str();
        return true;
    }
}
