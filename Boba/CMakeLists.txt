set(SOURCE_FILES BobaApp.cpp)

set(HEADER_FILES Boba.h BobaApp.h BobaUtils.h )


add_library(boba_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(boba_lib PRIVATE pch.h)

add_definitions(-DBUBBLE_LIB)

target_link_libraries(boba_lib glfw)
include_directories(../glfw/include)





