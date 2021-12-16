add_executable(my_game main.cpp BobaUnit.h BobaUnit.cpp MyBobaApp.h MyBobaApp.cpp)

target_link_libraries(my_game boba_lib)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/.. PROPERTY VS_STARTUP_PROJECT my_game)

include_directories(../Boba)

file(COPY Assets DESTINATION ../MyGame)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)