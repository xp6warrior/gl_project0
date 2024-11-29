cmake_minimum_required(VERSION 3.5.0)
project(gl_project0)
set(CMAKE_CXX_STANDARD 17)

# Source files
add_library(${PROJECT_NAME} STATIC
	src/gl_project0.cpp
	src/objects/renderer.cpp
	src/objects/mesh.cpp
	src/objects/shaderProgram.cpp
	src/objects/texture.cpp
	src/objects/camera.cpp
	src/primitives/cube.cpp
	src/primitives/quad.cpp
)
# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
	include
	dependencies/stb-image
)

# Dependencies
add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)
target_link_libraries(${PROJECT_NAME} PUBLIC glfw glad glm) # Make this PRIVATE one day (details in TODO)

# Test
add_subdirectory(test)