##---------------- revision List -----------------------
##   2016-03-28  lichao  create version
##------------------------------------------------------

AUX_SOURCE_DIRECTORY(. UT_SRCS)

##  build a executable file hearts
ADD_EXECUTABLE(hearts_ut ${UT_SRCS})

target_link_libraries(hearts_ut hearts_game pthread)

