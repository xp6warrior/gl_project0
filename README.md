# Currently WIP, no documentation available at the moment 

# gl_project0

### An OpenGL-based 3D renderer
As the name suggests, this project is my first try at OpenGL. It is simply the result of my learning, starting off as a playground for testing, eventually becoming a simply library that can be utilized in my future projects.

## Adding to your project (CMake)
To add gl_project0 to your project simply add a subdirectory to your project's CMakeLists.txt file. Then, specify the include directory of gl_project0, and link the library.

```cmake
# Add subdirectory
add_subdirectory([path_to_library_dir])
# Specify include directory
target_include_directories([your_project_name] PUBLIC [path_to_include_dir])
# Link library with project
target_link_libraries([your_project_name] gl_project0)
```

## Initial setup
To setup the renderer, include the master header file. First define the Start(), Update(), and End() functions. Only then you can call the Init() function to start the renderer. A black window should appear when the program is executed.
```c
#include <gl_project0.hpp>

void gl0::Start() {} // Runs once at the start of the program
void gl0::Update() {} // Runs every frame
void gl0::End() {} // Runs when the program is exited

int main(int argc, char** argv) {
    gl0::Init("My project", 800, 600); // Initialises the renderer
    return 0;
}
```
