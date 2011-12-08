#include "Data.hpp"

namespace TclLiquid
{
    Liquid::HashFragment* Data::Parse(Tcl_Interp* interp,
                                      Tcl_Obj* data)
    {
        // Ensure that the incoming data is in fact a dictionary
        // - currently being ignored
        /*
        if ((data->typePtr == NULL) ||
            (strcmp(data->typePtr->name,
                    "dict") != 0))
            return NULL;
        */

        // Parse the root dictionary
        return ParseTclDict(interp,
                            data);
    }

    Liquid::HashFragment* Data::ParseTclDict(Tcl_Interp* interp,
                                             Tcl_Obj* dict)
    {
        // Initialize an empty hash fragment
        Liquid::HashFragment* hash = new Liquid::HashFragment();

        // Set up dictionary scanning
        Tcl_DictSearch dictSearch;
        Tcl_Obj* key,
               * value;
        int done,
            stringLength;
        char* stringData;

        Tcl_DictObjFirst(interp,
                         dict,
                         &dictSearch,
                         &key,
                         &value,
                         &done);
        
        // Iterate through the dictionary
        while (done == 0)
        {
            // Read out the key
            stringData = Tcl_GetStringFromObj(key,
                                              &stringLength);
            std::string keyName(stringData,
                                stringLength);

            // Parse depending on the value type
            if ((value->typePtr != NULL) &&
                (strcmp(value->typePtr->name,
                        "list") == 0))
            {
                hash->Set(keyName,
                          ParseTclList(interp,
                                       value));
            }
            else if ((value->typePtr != NULL) &&
                     (strcmp(value->typePtr->name,
                             "dict") == 0))
            {
                hash->Set(keyName,
                          ParseTclDict(interp,
                                       value));
            }
            else
            {
                stringData = Tcl_GetStringFromObj(value,
                                                  &stringLength);
                
                hash->Set(keyName,
                          ParseTclObject(stringData,
                                         stringLength));
            }
            
            // Scoop over to the next element
            Tcl_DictObjNext(&dictSearch,
                            &key,
                            &value,
                            &done);
        }
        
        // Return the hash
        return hash;
    }

    Liquid::ArrayFragment* Data::ParseTclList(Tcl_Interp* interp,
                                              Tcl_Obj* list)
    {
        // Initialize an empty array fragment
        Liquid::ArrayFragment* array = new Liquid::ArrayFragment();
        
        // Get the beginning of the list
        int entryCount,
            entryIndex = 0,
            stringLength;
        char* stringData;
        Tcl_Obj** entrys;

        Tcl_ListObjGetElements(interp,
                               list,
                               &entryCount,
                               &entrys);

        // Iterate through the list
        Tcl_Obj* value;

        while (entryIndex < entryCount)
        {
            // Get the item
            value = entrys[entryIndex];

            // Parse depending on the value type
            if ((value->typePtr != NULL) &&
                (strcmp(value->typePtr->name,
                        "list") == 0))
            {
                array->Add(ParseTclList(interp,
                                        value));
            }
            else if ((value->typePtr != NULL) &&
                     (strcmp(value->typePtr->name,
                             "dict") == 0))
            {
                array->Add(ParseTclDict(interp,
                                        value));
            }
            else
            {
                stringData = Tcl_GetStringFromObj(value,
                                                  &stringLength);
                
                array->Add(ParseTclObject(stringData,
                                          stringLength));
            }
            
            entryIndex++;
        }

        // Return the array
        return array;
    }

    Liquid::Fragment* Data::ParseTclObject(char*& stringData,
                                           int& stringLength)
    {
        // Turn the string data into a string
        std::string value(stringData,
                          stringLength);

        // Boolean?
        if (value == "true")
            return new Liquid::BooleanFragment(true);
        if (value == "false")
            return new Liquid::BooleanFragment(false);

        // Integer fragment?
        if (IntegerFragment.FullMatch(value))
            return new Liquid::IntegerFragment(value);

        // Floating point fragment?
        if (FloatFragment.FullMatch(value))
            return new Liquid::FloatFragment(value);
                
        // If nothing else, return it as a string
        return new Liquid::StringFragment(value);
    }
}
