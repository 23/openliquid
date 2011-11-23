#include <sstream>

#include "RenderError.hpp"
#include "Strainer.hpp"
#include "HashFragment.hpp"

#ifndef __LIQUID_RENDERCONTEXT
#define __LIQUID_RENDERCONTEXT
namespace Liquid
{
    /// Rendering context
    class RenderContext
    {
    public:
        /// Stream that holds the result
        std::stringstream Result;


        /// Root of the data
        HashFragment* Data;


        /// Strainer
        Strainer& Strain;


        /// Rendering error
        RenderError& Error;


        /// Initialize a rendering context

        /// @param data Root of the data
        /// @param strain Reference to the strainer
        /// @param error Reference to the rendering error
        RenderContext(HashFragment* data,
                      Strainer& strain,
                      RenderError& error)
            :   Data(data),
                Strain(strain),
                Error(error)
        {

        }
    };
}
#endif
