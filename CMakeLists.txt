cmake_minimum_required(VERSION 3.26)
project(OpenGLBase)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)

set( GLFW-CMAKE-STARTER-SRC
        src/main.cpp
        src/glad.c
        src/Modules/FileLoader.h
        src/OpenGL_Utils/Geometry/Texture.h
        src/OpenGL_Utils/Geometry/Geometry.cpp
        src/OpenGL_Utils/Geometry/Geometry.h
        src/OpenGL_Utils/Geometry/Mesh.h
        src/OpenGL_Utils/Geometry/Triangle.h
        src/OpenGL_Utils/Geometry/Vertex.h
        src/OpenGL_Utils/OpenGL_Main.cpp
        src/OpenGL_Utils/OpenGL_Main.h
        src/OpenGL_Utils/OpenGL_Main.cpp
        src/OpenGL_Utils/ObjectManager.h
)

if (MSVC)
    find_package( OpenGL REQUIRED )
    include_directories( ${OPENGL_INCLUDE_DIRS} )
    set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
    set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )
    set( GLAD_GL "" )
    add_subdirectory( deps/glfw )
    option( GLFW-CMAKE-STARTER-USE-GLFW-GLAD "Use GLAD from GLFW" ON )
    if( GLFW-CMAKE-STARTER-USE-GLFW-GLAD )
        include_directories("${GLFW_SOURCE_DIR}/deps")
        set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h"
                src/OpenGL_Utils/Object.h)

    endif()
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )


    add_executable( OpenGLBase WIN32 ${GLFW-CMAKE-STARTER-SRC} ${GLAD_GL} )
    target_link_libraries( OpenGLBase ${OPENGL_LIBRARIES} glfw )
elseif (UNIX)
    add_executable(OpenGLBase ${GLFW-CMAKE-STARTER-SRC})
    target_link_libraries(OpenGLBase glfw)
endif ()


