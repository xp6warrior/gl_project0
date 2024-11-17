cmake_minimum_required(VERSION 3.5.0)
project(gl_project0_test)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)

add_subdirectory(.. dependencies/gl0)
target_link_libraries(${PROJECT_NAME} gl_project0)