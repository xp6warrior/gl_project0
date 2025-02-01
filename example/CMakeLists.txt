cmake_minimum_required(VERSION 3.5.0)
project(gl_project_example)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} example.cpp)
target_link_libraries(${PROJECT_NAME} gl_project0)