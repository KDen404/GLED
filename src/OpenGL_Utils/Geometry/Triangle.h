//
// Created by KDen404 on 22.04.24.
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
    Triangle(Vertex v1, Vertex v2, Vertex v3) :
            m_Vertices(
                    {
                            v1,v2,v3
                    }) {};
    Triangle(float* v) : m_Vertices({
            Vertex(v[0],v[1],v[2]),
            Vertex(v[3],v[4],v[5]),
            Vertex(v[6],v[7],v[8])}) {};
    ~Triangle() = default;

    inline std::array<Vertex,3> getVertices()
    {
        return m_Vertices;
    };
protected:
    std::array<Vertex,3> m_Vertices;
};


#endif //OPENGLBASE_TRIANGLE_H
