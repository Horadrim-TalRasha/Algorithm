##--------------- Revision List -----------------------
##   2016-03-21  lichao  create version
##-----------------------------------------------------

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -ggdb")

set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")

AUX_SOURCE_DIRECTORY(. GAME_SRCS)

add_library(hearts_game ${GAME_SRCS})
