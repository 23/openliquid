set(TCL_INCLUDE "/usr/include/tcl8.6")

if (APPLE)
  set(TCL_INCLUDE "/Library/Frameworks/Tcl.framework/Versions/8.5/Headers")
endif (APPLE)

include_directories(
        ${PROJECT_SOURCE_DIR}/lib
        ${TCL_INCLUDE}
)

add_library(tclliquid SHARED
        TclLiquid.cpp
        Data.cpp
        FileSystem.cpp
)

add_definitions(-DUSE_TCL_STUBS)

target_link_libraries(tclliquid
        openliquid
        tclstub8.6
        pcrecpp
)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/pkgIndex.tcl
               ${CMAKE_CURRENT_BINARY_DIR}/pkgIndex.tcl COPYONLY)
