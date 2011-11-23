#include <string>
#include <iostream>
#include <cstring>
#include <tcl.h>

#include <liquid/Template.hpp>
#include <liquid/Expressions.hpp>

#ifndef __TCLLIQUID_TCLDATA
#define __TCLLIQUID_TCLDATA
namespace TclLiquid
{
    /// Static class for translating TCL data
    class Data
    {
    public:
        /// Parse the data passed to a TCL function
        
        /// @param interp Interpreter
        /// @param data Pointer to the TCL data
        static Liquid::HashFragment* Parse(Tcl_Interp* interp,
                                           Tcl_Obj* data);
    private:
        /// Private constructor
        Data() {}
        
        
        /// Parse a TCL dictionary to a hash fragment
        
        /// @param interp Interpreter
        /// @param dict Pointer to the TCL dictionary object
        /// @returns a pointer to a hash fragment
        static Liquid::HashFragment* ParseTclDict(Tcl_Interp* interp,
                                                  Tcl_Obj* dict);
        
        
        /// Parse a TCL list to an array fragment
        
        /// @param interp Interpreter
        /// @param list Pointer to the TCL list object
        /// @returns a pointer to an array fragment
        static Liquid::ArrayFragment* ParseTclList(Tcl_Interp* interp,
                                                   Tcl_Obj* list);
        
        
        /// Parse a TCL object to an arbitrary fragment
        
        /// @param stringData Value data
        /// @param stringLength Value length
        /// @returns a pointer to an arbitrary fragment representing the object
        static Liquid::Fragment* ParseTclObject(char*& stringData,
                                                int& stringLength);
    };
}
#endif
