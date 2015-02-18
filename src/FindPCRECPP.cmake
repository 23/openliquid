# first look at the pc config info
include(FindPkgConfig)
if(PKG_CONFIG_FOUND)
  pkg_check_modules(PC_pcrecpp libpcrecpp)
endif()

# look in the standard locations and give an option to the user to configure it
# by hand
find_library(PCRECPP_LIBRARIES
  NAMES pcrecpp
  HINTS ${PC_pcrecpp_LIBRARY_DIRS})

find_path(PCRECPP_INCLUDE_DIRS
  NAMES pcrecpp.h
  HINTS ${PC_pcrecpp_INCLUDE_DIRS})

set(PCRECPP_VERSION ${PC_pcrecpp_VERSION})

# and set the expected variables for find_package
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(PCRECPP DEFAULT_MSG
  PCRECPP_LIBRARIES PCRECPP_INCLUDE_DIRS)
