cmake_minimum_required(VERSION 3.5.0)
project(gl_project0_test)
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} test.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ../include)
target_link_libraries(${PROJECT_NAME} gl_project0 glfw glad)