#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <gl0/gl_project0.hpp>

namespace gl0 {
    void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        getKeyInput(key, action);
    }

    void cursorCallback(GLFWwindow* window, double xpos, double ypos) {
        getCursorInput(xpos, ypos);
    }

    int Init(std::string title, int width, int height, bool show_fps)
    {
        // Init
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // macOS compatibility
        #endif

        // Window object
        GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
        if (window == NULL) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return -1;
        }
        glfwMakeContextCurrent(window);

        // GLAD init
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            return -1;
        }    

        // Viewport (and callback for resizing)
        glViewport(0, 0, width, height);
        glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int w, int h){
            glViewport(0, 0, w, h);
        });
        glEnable(GL_DEPTH_TEST);

        // Input callback functions
        glfwSetKeyCallback(window, keyCallback);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); 
        glfwSetCursorPosCallback(window, cursorCallback);

        Start();

        // Render loop
        while(!glfwWindowShouldClose(window)) {
            double before = glfwGetTime();

            if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                glfwSetWindowShouldClose(window, true); // Close on ESC
            }
        
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

            Update();

            glfwPollEvents(); // input changes
            glfwSwapBuffers(window); // swaps front and back buffers

            auto after = glfwGetTime();
            if (show_fps) {
                std::cout << 1000 / (after - before) << std::endl;
            }
        }

        glfwTerminate();
        End();

        return 0;
    }
};