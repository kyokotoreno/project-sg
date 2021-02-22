cmake_minimum_required(VERSION 3.10)

project(projectsg-physics)

add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/projectsg/physics/vectors.cpp)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
