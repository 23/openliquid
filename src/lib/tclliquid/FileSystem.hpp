#include <string>
#include <iostream>
#include <cstring>
#include <map>
#include <tcl.h>

#ifndef __TCLLIQUID_FILESYSTEM
#define __TCLLIQUID_FILESYSTEM
namespace TclLiquid
{
    typedef std::map<std::string, std::string> FileSystemMap;
    typedef FileSystemMap::iterator FileSystemIterator;
    typedef std::pair<std::string, std::string> FileSystemPair;
    
    /// File system parsed from double TCL lists
    class FileSystem
    {
    public:
        /// Initialize a file system
        
        /// @param interp Interpreter
        /// @param list List of templates
        FileSystem(Tcl_Interp* interp,
                   Tcl_Obj* list);


        /// Get a template file by its path
        
        /// @param path Path of the template
        /// @param source Reference to a string to hold the source code
        /// @returns true if the template was found, otherwise false
        bool TryFind(std::string path,
                     std::string& source);
    private:
        FileSystemMap _map; ///< File system map
    };
}
#endif
