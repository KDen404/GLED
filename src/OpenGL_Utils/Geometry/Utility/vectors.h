//
// Created by KDen404 on 07.06.24.
//

#ifndef OPENGLBASE_VECTORS_H
#define OPENGLBASE_VECTORS_H


class Vector2 {
public:
    inline Vector2(float x, float y)
    {
        m_coords = new coords(x, y);
    };

    inline ~Vector2()
    {
        delete m_coords;
    };

    inline float get_X() const
    {
        return m_coords->x;
    };

    inline float get_Y() const
    {
        return m_coords->y;
    };
private:
    struct coords{
        coords(float p_x, float p_y) : x(p_x), y(p_y) {};
        float x, y;
    };
    coords* m_coords = nullptr;
};

class Vector3 {
public:
    inline Vector3(float x, float y, float z)
    {
        m_coords = new coords(x, y, z);
    };

    inline ~Vector3()
    {
        delete m_coords;
    };

    inline float get_X() const
    {
        return m_coords->x;
    };

    inline float get_Y() const
    {
        return m_coords->y;
    };

    inline float get_Z() const
    {
        return m_coords->z;
    };
private:
    struct coords{
        coords(float p_x, float p_y, float p_z) : x(p_x), y(p_y), z(p_z) {};
        float x, y, z;
    };
    coords* m_coords = nullptr;
};

class Vector4 {

public:
    inline Vector4(float x, float y, float z, float w)
    {
        m_coords = new coords(x, y, z, w);
    };

    inline ~Vector4()
    {
        delete m_coords;
    };

    inline float get_X() const
    {
        return m_coords->x;
    };

    inline float get_Y() const
    {
        return m_coords->y;
    };

    inline float get_Z() const
    {
        return m_coords->z;
    };

    inline float get_W() const
    {
        return m_coords->w;
    };
private:
    struct coords{
        coords(float p_x, float p_y, float p_z, float p_w) : x(p_x), y(p_y), z(p_z), w(p_w) {};
        float x, y, z, w;
    };
    coords* m_coords = nullptr;
};

#endif //OPENGLBASE_VECTORS_H
