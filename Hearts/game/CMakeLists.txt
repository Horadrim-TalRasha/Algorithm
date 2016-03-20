set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_C_FLAGS_DEBUG "-O0 -g -Wall -ggdb")

set(CMAKE_C_FLAGS_RELEASE "-O3 -Wall")

AUX_SOURCE_DIRECTORY(. GAME_SRCS)

add_library(hearts_game ${GAME_SRCS})
