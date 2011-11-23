# Project setup
project(openliquid)
cmake_minimum_required(VERSION 2.6)
enable_testing()

# Debugging flags for debug version
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${GENERIC_CXX_FLAGS} -DDEBUG -Wall -Wno-deprecated-declarations")

# Flags for release version
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${GENERIC_CXX_FLAGS} -Wall -Wno-deprecated-declarations")

# Sub projects
add_subdirectory(lib/liquid)

# Include tests
include(tests.cmake)