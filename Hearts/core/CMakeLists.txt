##---------------- revision List -----------------------
##   2016-03-20  lichao  create version
##------------------------------------------------------

AUX_SOURCE_DIRECTORY(. CORE_SRCS)

##  build a executable file hearts
ADD_EXECUTABLE(hearts ${CORE_SRCS})

target_link_libraries(hearts hearts_game pthread)

