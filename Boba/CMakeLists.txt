set(SOURCE_FILES BobaApp.cpp BobaWindow.cpp GLFWimport/GLFW_implementation.cpp BobaRenderer.cpp BobaShader.cpp BobaSprite.cpp BobaEvents.cpp OpenGLimport/OpenGLRenderer.cpp OpenGLimport/OpenGLBobaSprite.cpp OpenGLimport/OpenGLShader.cpp)

set(HEADER_FILES Boba.h BobaApp.h BobaUtils.h BobaWindow.h BobaWindowImplementation.h BobaEvents.h BobaKeyCodes.h GLFWimport/GLFW_implementation.h BobaRenderer.h BobaRendererImplementation.h BobaShader.h BobaShaderImplementation.h BobaSprite.h BobaSpriteImplementation.h OpenGLimport/OpenGLRenderer.h OpenGLimport/OpenGLBobaSprite.h OpenGLimport/OpenGLShader.h)

add_library(boba_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(boba_lib PRIVATE pch.h)

add_definitions(-DBOBA_LIB)


target_link_libraries(boba_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../Boba)
include_directories(../glad/include)
include_directories(../stbi)





