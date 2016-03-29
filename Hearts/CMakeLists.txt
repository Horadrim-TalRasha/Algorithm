##--------------- Revision List -----------------------
##   2016-03-20  lichao  create version
##   2016-03-20  lichao  add sub directory 'game'
##   2016-03-21  lichao  add DISPLAY_BUILD_ARGS to display
##                       build arguments
##   2016-03-26  lichao  delete unwanted code and add new
##                       subdirectory
##   2016-03-28  lichao  add subdirectory 'ut'
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

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(game)

add_subdirectory(core)

add_subdirectory(ut)
