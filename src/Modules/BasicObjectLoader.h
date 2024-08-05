//
// Created by KDen404 on 25.07.24.
//

#ifndef OPENGLBASE_BASICOBJECTLOADER_H
#define OPENGLBASE_BASICOBJECTLOADER_H

#include "../OpenGL_Utils/Object.h"
#include <exception>
#include "FileLoader.h"

namespace EngineExceptions {
    class EmptyFileFormat_Exception : public std::exception {
    public:
        char* what () {
            return "Use a child class of BasicObjectLoader to load an object.";
            //if you read this you are really unlucky
        }
    };
}


class BasicObjectLoader {
    BasicObjectLoader() = default;
    ~BasicObjectLoader()
    {
        delete m_File;
    };
public:
    virtual Object loadObject(const char *path)
    {
        throw EngineExceptions::EmptyFileFormat_Exception();
    }
protected:
    Modules::SystemFile *m_File;
};



#endif //OPENGLBASE_BASICOBJECTLOADER_H
