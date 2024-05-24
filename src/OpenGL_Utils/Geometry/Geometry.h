//
// Created by schreibmaschine on 22.04.24.
//

#ifndef OPENGLBASE_GEOMETRY_H
#define OPENGLBASE_GEOMETRY_H
#include "../../Modules/FileLoader.h"
#include "Mesh.h"

class Geometry {
public:
    Geometry();
    Geometry(Mesh* mesh);
    ~Geometry();
    void Draw();
    inline void SetRGBA(
            float r,
            float g,
            float b,
            float alpha
            )
    {
    }

    inline void Move(
            //MovementManager o_MovementManager, TODO Implement
            float p_xEndPosition,
            float p_yEndPosition,
            float p_zEndPosition
            )
    {
        //TODO: DO SHIT
    }

    inline void Scale(
            float xScale,
            float yScale,
            float zScale
            )
    {
        m_xScale = xScale;
        m_yScale = yScale;
        m_zScale = zScale;
    }

    float GetPosition();

private:
    Mesh* m_Mesh;
    float m_xRotation, m_yRotation, m_zRotation;
    float m_xPosition, m_yPosition, m_zPosition;
    float m_xScale, m_yScale, m_zScale;
};


#endif //OPENGLBASE_GEOMETRY_H
