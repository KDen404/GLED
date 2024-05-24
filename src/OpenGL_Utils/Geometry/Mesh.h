//
// Created by schreibmaschine on 22.04.24.
//

#ifndef OPENGLBASE_MESH_H
#define OPENGLBASE_MESH_H
#include "Triangle.h"
#include <vector>
using namespace std;
class Mesh {
public:
    Mesh() : m_Triangles({Triangle()}) {};
    explicit Mesh(vector<Triangle> &triangles): m_Triangles(triangles) {};
    ~Mesh() = default;

    vector<Triangle> m_Triangles;

};


#endif //OPENGLBASE_MESH_H
