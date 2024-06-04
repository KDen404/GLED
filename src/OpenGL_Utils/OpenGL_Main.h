//
// Created by KDen404 on 15.05.24.
//

#ifndef OPENGLBASE_OPENGL_MAIN_H
#define OPENGLBASE_OPENGL_MAIN_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "../Modules/FileLoader.h"
#include "../OpenGL_Utils/ObjectManager.h"

class OpenGL_Main {
public:
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static void processInput(GLFWwindow *window);

    bool WIREFRAMEMODE = true;
public:
    OpenGL_Main();
    ~OpenGL_Main();
    int init();
    void loop();


public: //settings
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

    Modules::SystemFile vertexShaderFile = Modules::SystemFile("/src/shaders/basic.vert");
    Modules::SystemFile fragmentShaderFile = Modules::SystemFile("/src/shaders/basic.frag");

private:

private: // GLFW "Global" variablen
    GLFWwindow* window;
    unsigned int shaderProgram;
    unsigned int VBO, VAO;

private: //glfw encapsulated for further understanding
    void reloadShaderProgram();
    std::vector<float> LoadVerticesFromObjects();
    std::vector<float> VerticeVectorBuffer;
    ObjectManager m_ObjectManager = ObjectManager();
};

#endif //OPENGLBASE_OPENGL_MAIN_H
