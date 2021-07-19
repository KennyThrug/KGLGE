#pragma once
#include "GameObject.h"
namespace KGLGE {
    class DummyTwo :
        public GameObject
    {
    public:
        DummyTwo();
        // Inherited via GameObject
        bool update() override;
        Vertex* getVertexes() override;
        unsigned int getNumVertex() override;
        Triangle* getIndicies(unsigned int offset) override;
        unsigned int getNumTriangles() override;

    private:
        Triangle ind[2];
        Vertex vert[4];

        // Inherited via GameObject
        virtual bool respondToKey(unsigned int key) override;
    };

}