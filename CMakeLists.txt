cmake_minimum_required(VERSION 3.5.0)

add_subdirectory(dependencies/glfw-3.4)
add_subdirectory(dependencies/glad)

project(gl_project0)
add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE glfw glad)