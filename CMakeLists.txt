cmake_minimum_required(VERSION 3.5.0)
project(gl_project0)

add_executable(${PROJECT_NAME} 
	src/main.cpp
	src/entry.cpp
	src/objects/renderer.cpp
	src/objects/mesh.cpp
	src/objects/shaderProgram.cpp
	src/objects/texture.cpp
	src/objects/camera.cpp
	src/primitives/cube.cpp
	src/primitives/quad.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC dependencies/stb-image)

add_subdirectory(dependencies/glfw-3.4)
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)
target_link_libraries(${PROJECT_NAME} glfw glad glm)