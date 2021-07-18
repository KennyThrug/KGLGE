#pragma once
#include "GameObject.h"
namespace KGLGE {
    class DummyTwo :
        public GameObject
    {
    public:
        // Inherited via GameObject
        bool update() override;
        Vertex* getVertexes() override;
        unsigned int getNumVertex() override;
        Triangle* getIndicies() override;
        unsigned int getNumTriangles() override;

    private:
        Triangle ind[2];
        Vertex vert[4];
    };

}