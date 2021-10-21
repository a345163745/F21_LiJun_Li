set(SOURCE_FILES BobaApp.cpp BobaWindow.cpp GLFWimport/GLFW_implementation.cpp)

set(HEADER_FILES Boba.h BobaApp.h BobaUtils.h BobaWindow.h BobaWindowImplementation.h GLFWimport/GLFW_implementation.h)

add_library(boba_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(boba_lib PRIVATE pch.h)

add_definitions(-DBOBA_LIB)

target_link_libraries(boba_lib glfw)
include_directories(../glfw/include)
include_directories(../Boba)





