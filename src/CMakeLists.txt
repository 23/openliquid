# Project setup
project(openliquid)
cmake_minimum_required(VERSION 2.6)
enable_testing()

# Debugging flags for debug version
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${GENERIC_CXX_FLAGS} -DDEBUG -Wall -Wno-deprecated-declarations")

# Flags for release version
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${GENERIC_CXX_FLAGS} -Wall -Wno-deprecated-declarations")

# find required libs
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
find_package(PCRECPP)
include_directories(${PCRECPP_INCLUDE_DIRS})

# Sub projects
add_subdirectory(lib/liquid)
add_subdirectory(lib/tclliquid)

# Include tests
include(tests.cmake)
