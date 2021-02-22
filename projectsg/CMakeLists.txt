cmake_minimum_required(VERSION 3.10)

project(projectsg)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/projectsg/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    mingw32
    ${SDL2MAIN_LIBRARY}
    ${SDL2_LIBRARY}
    projectsg-gui
    projectsg-physics
)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
