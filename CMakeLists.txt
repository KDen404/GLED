cmake_minimum_required(VERSION 3.26)
project(OpenGLBase)

set(CMAKE_CXX_STANDARD 23)
include_directories(include)
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
        set( GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h" )
    endif()
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup" )
    set( GLFW-CMAKE-STARTER-SRC
            src/main.cpp
            src/glad.c
    )

    add_executable( OpenGLBase WIN32 ${GLFW-CMAKE-STARTER-SRC} ${GLAD_GL} )
    target_link_libraries( OpenGLBase ${OPENGL_LIBRARIES} glfw )
elseif (UNIX)
    add_executable(OpenGLBase src/main.cpp src/glad.c)
    target_link_libraries(OpenGLBase glfw)
endif ()


