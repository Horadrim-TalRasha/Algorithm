##--------------- Revision List -----------------------
##   2016-03-20  lichao  create version
##   2016-03-20  lichao  add sub directory 'game'
##   2016-03-21  lichao  add DISPLAY_BUILD_ARGS to display
##                       build arguments
##-----------------------------------------------------


cmake_minimum_required(VERSION 2.6)

project(Hearts C CXX)

enable_testing()

##  show all compiling options
if(DISPLAY_BUILD_ARGS)
  set(CMAKE_VERBOSE_MAKEFILE ON)
endif()

##  set gcc debug flags
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -ggdb")

##  set gcc release flags
set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")

##set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(game)

##  put the src files into variable CORE_SRCS
AUX_SOURCE_DIRECTORY(core CORE_SRCS)

##  build a executable file hearts
ADD_EXECUTABLE(hearts ${CORE_SRCS})
