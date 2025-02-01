cmake_minimum_required(VERSION 3.5.0)
project(gl_project0)
set(CMAKE_CXX_STANDARD 17)

# Creates static library
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
target_include_directories(${PROJECT_NAME} PUBLIC include dependencies) # PUBLIC passes down to test

# Libraries (gl_project0) don't link with other libraries (glad, glfw, etc.)
# This is so gl_project0 known where the library's include directories are (and for inheritence to test)
add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw glad glm) # PUBLIC passes down to test

# Example
add_subdirectory(example)