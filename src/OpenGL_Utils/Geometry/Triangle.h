//
// Created by schreibmaschine on 22.04.24.
//

#ifndef OPENGLBASE_TRIANGLE_H
#define OPENGLBASE_TRIANGLE_H
#include "Vertex.h"

class Triangle {
public:
    static const unsigned short Size = 9;
    Triangle() :
    m_Vertices(
            {
                Vertex(-0.5f, -0.5f, 0.0f),
                Vertex(0.5f, -0.5f, 0.0f),
                Vertex(0.0f, 0.5f, 0.0f)
            }) {};
    Triangle(Vertex& v1, Vertex& v2, Vertex& v3) :
    m_Vertices(
            {
                v1,v2,v3
            }) {};
    ~Triangle() = default;

    inline std::array<Vertex,3> getVertices()
    {
        return m_Vertices;
    };
protected:
    std::array<Vertex,3> m_Vertices;
};


#endif //OPENGLBASE_TRIANGLE_H
