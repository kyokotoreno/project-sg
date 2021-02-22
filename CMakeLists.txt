cmake_minimum_required(VERSION 3.10)

# set the project name
project(projectsg)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "C:/mingw-w64/mingw64/cmake/")

# Add Subdirectory
add_subdirectory(projectsg-gui)
add_subdirectory(projectsg-physics)
add_subdirectory(projectsg)
add_subdirectory(tests)
add_subdirectory(doc)

#Add Tests
enable_testing()

add_test(NAME testVector2 COMMAND $<TARGET_FILE:Vector2Test>)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
