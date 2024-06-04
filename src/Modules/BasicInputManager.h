//
// Created by KDen404 on 26.05.24.
//

#ifndef OPENGLBASE_BASICINPUTMANAGER_H
#define OPENGLBASE_BASICINPUTMANAGER_H
#include <GLFW/glfw3.h>
#include <future>

class BasicInputManager {
public:
    BasicInputManager() {

    };

    ~BasicInputManager() = default;

    inline static void loop() {
        while (!glfwWindowShouldClose(m_GLFWindow)) {
            processInput();
        }
    }

    inline static void processInput() {
        if (glfwGetKey(m_GLFWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(m_GLFWindow, true);
    }

    inline static void setGLFWWindow(GLFWwindow* window) {
        if (m_GLFWindow == nullptr) {
            m_GLFWindow = window;
        }
        else {
            throw BasicInputManagerException("GLFW window already set");
        }
    }



private:
    class BasicInputManagerException : public std::runtime_error {
    public:
        explicit BasicInputManagerException(const std::string& message) : std::runtime_error(message) {}
    };



private:
    static inline GLFWwindow* m_GLFWindow = nullptr;
};


#endif //OPENGLBASE_BASICINPUTMANAGER_H
