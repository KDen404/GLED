//
// Created by KDen404 on 25.07.24.
//

#ifndef OPENGLBASE_FBXLOADER_H
#define OPENGLBASE_FBXLOADER_H
#include "../BasicObjectLoader.h"
#include "../../OpenGL_Utils/Geometry/Mesh.h"
#include "../../../deps/FBXImport/importer/include/FBX/FBXImport.h"
#include "../../../deps/FBXImport/importer/include/FBX/TriangulateProcess.h"

class FBXLoader : public BasicObjectLoader {
    FBXLoader() = default;
public:
    virtual Object loadObject(const char *path) override
    {
        const auto &result = FBX::importFile(path, std::set<FBX::Process*>{new FBX::TriangulateProcess()});

        return Object(Mesh());
    }
};


#endif //OPENGLBASE_FBXLOADER_H
