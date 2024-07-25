//
// Created by KDen404 on 25.07.24.
//

#ifndef OPENGLBASE_FBXLOADER_H
#define OPENGLBASE_FBXLOADER_H
#include "../ObjectLoader.h"
#include "../../OpenGL_Utils/Geometry/Mesh.h"
class FBXLoader {
    FBXLoader() = delete;
public:
    virtual Object loadObject(const char *path) override
    {
        return Object(Triangle());
    }
};


#endif //OPENGLBASE_FBXLOADER_H
