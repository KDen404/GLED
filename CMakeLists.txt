cmake_minimum_required(VERSION 3.26)
project(OpenGLBase)

set(CMAKE_CXX_STANDARD 23)

add_executable(OpenGLBase src/glad.c src/main.cpp)

target_link_libraries(OpenGLBase
        glfw
)