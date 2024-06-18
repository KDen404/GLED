//
// Created by KDen404 on 24.05.24.
//

#ifndef OPENGLBASE_OBJECT_H
#define OPENGLBASE_OBJECT_H
#include "Geometry/Mesh.h"
#include "Geometry/Triangle.h"
#include "Geometry/Utility/vectors.h"

class Object {
private:
    Mesh test_cube_mesh = Mesh(
            {
                    Triangle(
                            Vertex(-0.25f,-0.25f,-0.25f),
                            Vertex(-0.25f,-0.25f, 0.25f),
                            Vertex(-0.25f, 0.25f, 0.25f)),

                    Triangle(
                            Vertex(0.25f, 0.25f,-0.25f),
                            Vertex(-0.25f,-0.25f,-0.25f),
                            Vertex(-0.25f, 0.25f,-0.25f)),

                    Triangle(
                            Vertex(0.25f,-0.25f, 0.25f),
                            Vertex(-0.25f,-0.25f,-0.25f),
                            Vertex(0.25f,-0.25f,-0.25f)),

                    Triangle(
                            Vertex(0.25f, 0.25f,-0.25f),
                            Vertex(0.25f,-0.25f,-0.25f),
                            Vertex(-0.25f,-0.25f,-0.25f)),

                    Triangle(
                            Vertex(-0.25f,-0.25f,-0.25f),
                            Vertex(-0.25f, 0.25f, 0.25f),
                            Vertex(-0.25f, 0.25f,-0.25f)),

                    Triangle(
                            Vertex(0.25f,-0.25f, 0.25f),
                            Vertex(-0.25f,-0.25f, 0.25f),
                            Vertex(-0.25f,-0.25f,-0.25f)),

                    Triangle(
                            Vertex(-0.25f, 0.25f, 0.25f),
                            Vertex(-0.25f,-0.25f, 0.25f),
                            Vertex(0.25f,-0.25f, 0.25f)),

                    Triangle(
                            Vertex(0.25f, 0.25f, 0.25f),
                            Vertex(0.25f,-0.25f,-0.25f),
                            Vertex(0.25f, 0.25f,-0.25f)),

                    Triangle(
                            Vertex(0.25f,-0.25f,-0.25f),
                            Vertex(0.25f, 0.25f, 0.25f),
                            Vertex(0.25f,-0.25f, 0.25f)),

                    Triangle(
                            Vertex(0.25f, 0.25f, 0.25f),
                            Vertex(0.25f, 0.25f,-0.25f),
                            Vertex(-0.25f, 0.25f,-0.25f)),

                    Triangle(
                            Vertex(0.25f, 0.25f, 0.25f),
                            Vertex(-0.25f, 0.25f,-0.25f),
                            Vertex(-0.25f, 0.25f, 0.25f)),

                    Triangle(
                            Vertex(0.25f, 0.25f, 0.25f),
                            Vertex(-0.25f, 0.25f, 0.25f),
                            Vertex(0.25f,-0.25f, 0.25f))


            });

public:
    inline Object() : m_Mesh(test_cube_mesh){};
    inline Object(Mesh mesh) : m_Mesh(mesh){};
    inline ~Object() = default;

    inline Mesh getMesh()
    {
        return m_Mesh;
    };

    inline void setMesh(Mesh mesh)
    {
        m_Mesh = mesh;
    };

    inline void setGlobalPosition(Vector3 position)
    {
        m_xGlobalPosition = position.get_X();
        m_yGlobalPosition = position.get_Y();
        m_zGlobalPosition = position.get_Z();
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
