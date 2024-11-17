cmake_minimum_required(VERSION 3.5.0)
project(gl_project0)
set(CMAKE_CXX_STANDARD 17)

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
target_include_directories(${PROJECT_NAME} PUBLIC
	dependencies/stb-image
	include
)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)
target_link_libraries(${PROJECT_NAME} glfw glad glm)