#include "FileSystem.hpp"

namespace TclLiquid
{
    FileSystem::FileSystem(Tcl_Interp* interp,
                           Tcl_Obj* list)
    {
        // Set up for iteration
        int listLength,
            listIndex = 0;
        Tcl_Obj** templates;

        if (Tcl_ListObjGetElements(interp,
                                   list,
                                   &listLength,
                                   &templates) == TCL_ERROR)
            return;

        // Iterate through the templates
        while (listIndex < listLength)
        {
            int templateDataLength;
            Tcl_Obj** templateData;

            Tcl_ListObjGetElements(interp,
                                   templates[listIndex],
                                   &templateDataLength,
                                   &templateData);

            if (templateDataLength != 2)
                continue;

            int nameLength,
                sourceLength;

            const char* name = Tcl_GetStringFromObj(templateData[0],
                                                    &nameLength),
                      * source = Tcl_GetStringFromObj(templateData[1],
                                                      &sourceLength);

            this->_map.insert(FileSystemPair(std::string(name),
                                             std::string(source)));
            
            listIndex++;
        }
    }

    bool FileSystem::TryFind(std::string path,
                             std::string& source)
    {
        FileSystemIterator iterator = this->_map.find(path);

        if (iterator == this->_map.end())
            return false;

        source = iterator->second;
        return true;
    }
}
