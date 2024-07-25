//
// Created by KDen404 on 25.07.24.
//

#ifndef OPENGLBASE_OBJECTLOADER_H
#define OPENGLBASE_OBJECTLOADER_H

#include "../OpenGL_Utils/Object.h"
#include <exception>

namespace EngineExceptions {
    class EmptyFileFormat_Exception : public std::exception {
    public:
        char * what () {
            return "Use a child class of ObjectLoader to load an object.";
            //if you read this you are really unlucky
        }
    };
}


class ObjectLoader {
    ObjectLoader() = delete;
public:
    virtual Object loadObject(const char *path)
    {
        throw EngineExceptions::EmptyFileFormat_Exception();
    }
};



#endif //OPENGLBASE_OBJECTLOADER_H
