//
// Created by schreibmaschine on 24.05.24.
//

#ifndef OPENGLBASE_OBJECT_H
#define OPENGLBASE_OBJECT_H
#include "Geometry/Mesh.h"
#include "Geometry/Triangle.h"

class Object {
public:
    inline Object() : m_Mesh(Mesh()) {};
    inline ~Object() = default;

    inline Mesh getMesh()
    {
        return m_Mesh;
    };

private:
    Mesh m_Mesh;
    float m_xGlobalPosition, m_yGlobalPosition, m_zGlobalPosition;
    float m_xLocalPosition, m_yLocalPosition, m_zLocalPosition;

    float m_xScale, m_yScale, m_zScale;

    float m_xGlobalRotation, m_yGlobalRotation, m_zGlobalRotation;
    float m_xLocalRotation, m_yLocalRotation, m_zLocalRotation;

};


#endif //OPENGLBASE_OBJECT_H