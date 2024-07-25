//
// Created by KDen404 on 22.04.24.
//

#ifndef OPENGLBASE_MESH_H
#define OPENGLBASE_MESH_H
#include "Triangle.h"
#include "Vertex.h"
#include <vector>
using namespace std;
class  Mesh {
public:
    Mesh() : m_Triangles({Triangle()}) {};
    explicit Mesh(vector<Triangle> triangles): m_Triangles(triangles) {};
    explicit Mesh(std::vector<float> triangles) {
        for (int i = 0; i < triangles.size(); i+=9) {
            m_Triangles.push_back(Triangle(Vertex(triangles[i],triangles[i+1],triangles[i+2]),
                                            Vertex(triangles[i+3],triangles[i+4],triangles[i+5]),
                                            Vertex(triangles[i+6],triangles[i+7],triangles[i+8])));
        }
    };
    ~Mesh() = default;

    vector<Triangle> m_Triangles;

};


#endif //OPENGLBASE_MESH_H
