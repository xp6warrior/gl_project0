cmake_minimum_required(VERSION 3.5.0)
project(gl_project0)
set(CMAKE_CXX_STANDARD 17)

# Source files
add_library(${PROJECT_NAME} STATIC
	src/gl_project0.cpp
	src/objects/renderer.cpp
	src/objects/mesh.cpp
	src/objects/shader.cpp
	src/objects/texture.cpp
	src/objects/camera.cpp
	src/objects/material.cpp
	src/primitives/cube.cpp
	src/primitives/quad.cpp
)
# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Dependencies
add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad)

# Test
add_subdirectory(test)