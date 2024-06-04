//
// Created by KDen404 on 22.04.24.
//

#ifndef OPENGLBASE_VERTEX_H
#define OPENGLBASE_VERTEX_H


class Vertex {
public:
    static const unsigned short m_Size = 3;
    Vertex() : X(0.0f), Y(0.0f), Z(0.0f) {};
    Vertex(float x, float y, float z) : X(x), Y(y), Z(z) {};
    ~Vertex() = default;

public:
    float X, Y, Z;
};


#endif //OPENGLBASE_VERTEX_H
