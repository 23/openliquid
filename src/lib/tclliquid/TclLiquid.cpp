#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <tcl.h>

#include <liquid/Template.hpp>

#include "Data.hpp"
#include "FileSystem.hpp"

#define LiquidNamespace "liquid::"
#define LiquidDataError "liquid_data_error"
#define LiquidParseError "liquid_parse_error"
#define LiquidRenderError "liquid_render_error"

#define LiquidError(_code, _description)                        \
    {                                                           \
        Tcl_SetObjResult(interp,                                \
                         Tcl_NewStringObj(_description,         \
                                      strlen(_description)));   \
        Tcl_AddErrorInfo(interp, _description);                 \
        Tcl_SetErrorCode(interp, _code, NULL);                  \
        return TCL_ERROR;                                       \
    }

static int LiquidValidate_Command(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    // * Check the number of arguments
    if (objc != 3)
    {
        Tcl_WrongNumArgs(interp, 1, objv, "<templates> <root template>");
        return TCL_ERROR;
    }

    // Parse the data into a file system
    TclLiquid::FileSystem fileSystem(interp,
                                     objv[1]);

    // Get the template name
    const char* templateNameChars = Tcl_GetStringFromObj(objv[2], NULL);
    std::string templateName(templateNameChars);

    // Try to get the template source
    std::string templateSource;

    if (!fileSystem.TryFind(templateName,
                            templateSource))
        LiquidError(LiquidDataError, "Template not found in template list");

    // Try to parse the template
    Liquid::ParserError parserError;
    Liquid::RenderError renderError;
    Liquid::Strainer strainer;

    Liquid::Template* templ = Liquid::Template::Parse(templateSource,
                                                      strainer,
                                                      parserError);

    if (!templ)
    {
        // Set the error
        std::stringstream errorStream;
        errorStream << parserError;

        LiquidError(LiquidParseError,
                    errorStream.str().c_str());
    }

    // Clean up the data.
    delete templ;

    return TCL_OK;
}

static int LiquidRender_Command(ClientData cdata, Tcl_Interp *interp, int objc, Tcl_Obj *const objv[])
{
    // * Check the number of arguments
    if ((objc < 3) || (objc > 4))
    {
        Tcl_WrongNumArgs(interp, 1, objv, "<templates> <root template> <values>");
        return TCL_ERROR;
    }

    // Parse out the data
    Liquid::HashFragment* data = TclLiquid::Data::Parse(interp,
                                                        objv[3]);

    if (data == NULL)
        LiquidError(LiquidDataError, "Invalid values passed to command");

    // Parse the data into a file system
    TclLiquid::FileSystem fileSystem(interp,
                                     objv[1]);

    // Get the template name
    const char* templateNameChars = Tcl_GetStringFromObj(objv[2], NULL);
    std::string templateName(templateNameChars);

    // Try to get the template source
    std::string templateSource;

    if (!fileSystem.TryFind(templateName,
                            templateSource))
        LiquidError(LiquidDataError, "Template not found in template list");

    // Try to parse the template
    Liquid::ParserError parserError;
    Liquid::RenderError renderError;
    Liquid::Strainer strainer;

    Liquid::Template* templ = Liquid::Template::Parse(templateSource,
                                                      strainer,
                                                      parserError);

    if (!templ)
    {
        // Delete left over data
        delete data;

        // Set the error
        std::stringstream errorStream;
        errorStream << parserError;

        LiquidError(LiquidParseError,
                    errorStream.str().c_str());
    }

    // Try to render the template
    std::string rendered;

    if (!templ->TryRender(data,
                          renderError,
                          rendered))
    {
        // Delete left over data
        delete templ;
        delete data;

        // Set the error
        std::stringstream errorStream;
        errorStream << renderError;

        LiquidError(LiquidParseError,
                    errorStream.str().c_str());
    }

    // Clean up the data
    delete templ;
    delete data;

    // Return the result
    Tcl_SetObjResult(interp,
                     Tcl_NewStringObj(rendered.c_str(),
                                      rendered.length()));
    return TCL_OK;
}

extern "C"
{
    /*
     * Load the extension in normal execution mode
     */
    int DLLEXPORT Tclliquid_Init(Tcl_Interp *interp)
    {
        // Initialize the stubs and verify the result
        if (Tcl_InitStubs(interp, TCL_VERSION, 0) == NULL)
            return TCL_ERROR;

        // Initialize the package provided by this extension
        if (Tcl_PkgProvide(interp, "liquid", "0.1.0") == TCL_ERROR)
            return TCL_ERROR;

        // Initialize commands
        Tcl_CreateObjCommand(interp, LiquidNamespace"validate", LiquidValidate_Command, NULL, NULL);
        Tcl_CreateObjCommand(interp, LiquidNamespace"render", LiquidRender_Command, NULL, NULL);

        // All set!
        return TCL_OK;
    }

    /*
     * Load the extension in safe execution mode
     */
    int DLLEXPORT Tclliquid_SafeInit(Tcl_Interp *interp)
    {
        // Default to the normal execution mode path - we're not doing anything extreme here anyway
        return Tclliquid_Init(interp);
    }

    /*
     * Unloads the extension in normal execution mode
     */
    int DLLEXPORT Tclliquid_Unload(Tcl_Interp *interp)
    {
        return TCL_OK;
    }

    /*
     * Unloads the extension in safe execution mode
     */
    int DLLEXPORT Tclliquid_SafeUnload(Tcl_Interp *interp)
    {
        return TCL_OK;
    }
}
