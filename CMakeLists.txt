cmake_minimum_required(VERSION 3.20)

project(my_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DBOBA_WINDOWS)
elseif(APPLE)
	add_definitions(-DBOBA_MAC)
elseif(UNIX)
	add_definitions(-DBOBA_LINUX)
endif()

add_definitions(-DBOBA_OPENGL)

add_subdirectory(MyGame)
add_subdirectory(Boba)
add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)

