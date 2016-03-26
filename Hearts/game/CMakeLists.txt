##--------------- Revision List -----------------------
##   2016-03-21  lichao  create version
##   2016-03-26  lichao  delete unwanted code
##-----------------------------------------------------

AUX_SOURCE_DIRECTORY(. GAME_SRCS)

add_library(hearts_game ${GAME_SRCS})
