//
// Created by schreibmaschine on 24.05.24.
//

#ifndef OPENGLBASE_OBJECTMANAGER_H
#define OPENGLBASE_OBJECTMANAGER_H

#include <vector>

#include "Geometry/Mesh.h"
#include "Object.h"
#include <utility>
using namespace std;

class ObjectManager {
public:
    ObjectManager()
    {
        m_ObjectList.push_back(Object());
    };
    ~ObjectManager() = default;
    //static void addObject();
    //static void purgeObject();
    inline static shared_ptr<vector<Object>> getObjectList()
    {
        return make_shared<vector<Object>>(m_ObjectList);
    }
    //static void updateObjects();

private:
    inline static vector<Object> m_ObjectList = {};

};


#endif //OPENGLBASE_OBJECTMANAGER_H
