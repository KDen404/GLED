#include "OpenGL_Utils/OpenGL_Main.h"

int main() {
    OpenGL_Main* app = new OpenGL_Main();
    app->init();
    app->loop();

    return 0;
}


