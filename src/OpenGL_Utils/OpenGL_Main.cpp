//
// Created by KDen404 on 15.05.24.
//

#include "OpenGL_Main.h"
#include "../OpenGL_Utils/Geometry/Vertex.h"
#include "../OpenGL_Utils/ObjectManager.h"
#include "../Modules/BasicInputManager.h"

bool HELLO_TRIANGLE = false;

OpenGL_Main::OpenGL_Main() {
    ObjectManager();
    BasicInputManager();
    BasicInputManager::setGLFWWindow(window);

}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void OpenGL_Main::processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this cfallback function executes
// ---------------------------------------------------------------------------------------------
void OpenGL_Main::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

int OpenGL_Main::init() {


    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__ //Apple sucks
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);

    try {
        if (window == NULL)
        {
            throw std::runtime_error("Failed to create GLFW window");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    try {
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }


    reloadShaderProgram();



    //possible break to load geometry objects into VBO??



    VerticeVectorBuffer = LoadVerticesFromObjects();


    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------

    //Create Vertex Buffer Objects
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);


    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(VerticeVectorBuffer.size() * sizeof(VerticeVectorBuffer[0])), VerticeVectorBuffer.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0,
                          3 ,
                          GL_FLOAT,
                          GL_FALSE,
                          sizeof(VerticeVectorBuffer[0]) * 3,
                          0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);


    // uncomment this call to draw in wireframe polygons.
    if (WIREFRAMEMODE)
    {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    return 0;
}

void OpenGL_Main::reloadShaderProgram() {
    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    char *vertexShaderSource = vertexShaderFile.FileBuffer;
    char *fragmentShaderSource = fragmentShaderFile.FileBuffer;
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void OpenGL_Main::loop() {
    // render loop
    // -----------
    for (glBindVertexArray(VAO);!glfwWindowShouldClose(window);)
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // draw our first triangle
        glUseProgram(shaderProgram);
        glDrawArrays(GL_TRIANGLES, 0, VerticeVectorBuffer.size()/3.f);
        // glBindVertexArray(0); // no need to unbind it every time

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

OpenGL_Main::~OpenGL_Main() {
    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
}

std::vector<float> OpenGL_Main::LoadVerticesFromObjects() {
    std::vector<float> vertices;
    auto ObjectList_shared_ptr = m_ObjectManager.getObjectList();
    for (auto object : *ObjectList_shared_ptr)
    {
        for (Triangle triangle : object->getMesh().m_Triangles)
        {
            for (Vertex vertex : triangle.getVertices())
            {
                vertices.push_back(vertex.X);
                vertices.push_back(vertex.Y);
                vertices.push_back(vertex.Z);
            }
        }
    }
    return vertices;
}
