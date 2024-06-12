#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

/* DATA */
float vertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f,
//   0.5f,  0.5f, 0.0f,
//  -0.5f, -0.5f, 0.0f
};
unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main() {\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main() {\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\0";


/* FUNCTIONS */
void handleDraw(unsigned int VAO, unsigned int shaderProgram) {

    // 1. Enable shaderProgram
    glUseProgram(shaderProgram);
    // 2. Bind VAO
    glBindVertexArray(VAO);
    // 3. Draw
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//  glDrawArrays(GL_TRIANGLES, 0, 6);
}

unsigned int createShader(GLenum type, const char* src) {
    // Compile
    unsigned int shader;
    shader = glCreateShader(type);
    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    // Error handling
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR: " << ((type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT")
            << " SHADER COMPILE ERROR\n" << infoLog << std::endl;
    }
    return shader;
}
unsigned int createShaderProgram(unsigned int vertex, unsigned int fragment) {
    // Linking
    unsigned int program;
    program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);

    // Error handling
    int success;
    char infoLog[512];
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR: SHADER PROGRAM LINK ERROR\n" << infoLog << std::endl;
    }

    glDeleteShader(vertex);
    glDeleteShader(fragment);
    return program;
}


int main()
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
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    });

        /* INITALISATION */
        unsigned int VAO, VBO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &EBO);
        glGenBuffers(1, &VBO);
        unsigned int vertexShader = createShader(GL_VERTEX_SHADER, vertexShaderSource);
        unsigned int fragmentShader = createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
        unsigned int shaderProgram = createShaderProgram(vertexShader, fragmentShader);
        // Bind VAO
        glBindVertexArray(VAO);
        // Set up VAO properties (VBO, EBO, attributes)
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

    // Render loop
    while(!glfwWindowShouldClose(window)) {
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // Close on ESC
            glfwSetWindowShouldClose(window, true);
    
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

        handleDraw(VAO, shaderProgram);

        glfwPollEvents(); // input changes
        glfwSwapBuffers(window); // swaps front and back buffers
    }

    glfwTerminate();
    return 0;
}

