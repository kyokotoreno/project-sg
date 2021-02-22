cmake_minimum_required(VERSION 3.10)

project(projectsg-gui)

find_package(SDL2 REQUIRED)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/projectsg/gui/gui.cpp)

target_link_libraries(${PROJECT_NAME}
    ${SDL2MAIN_LIBRARY}
    ${SDL2_LIBRARY}
    projectsg-physics
)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
    PUBLIC ${SDL2_INCLUDE_DIR}
)
