cmake_minimum_required(VERSION 3.10)

project(Vector2Test)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/vector2-test.cpp)

target_link_libraries(${PROJECT_NAME} 
    projectsg-physics
)
