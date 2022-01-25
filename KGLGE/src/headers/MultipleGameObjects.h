#include "GameObject.h"
namespace KGLGE{
    class MultipleGameObjects : public KGLGE::GameObject{
        public:
            Vertex *getVertexes() override;
            unsigned int getNumVertex() override;
            Triangle *getIndicies(unsigned int offset) override;
            unsigned int getNumTriangles() override;

            int getGameObjectID() = 0;
            virtual void update() = 0;
            float getProperty(int propertyNum) = 0;
            int getPropertyID(int propertyNum) = 0;
            int getPropertySize(int propertyNum) = 0;
            int getNumProperties() = 0;
            virtual bool respondToKey(unsigned int key) = 0;
        protected:
            std::vector<KGLGE::GameObject*> gameObjects;
            void addGameObject(GameObject* go);
        private:
            std::vector<KGLGE::Vertex> verticies;
            std::vector<KGLGE::Triangle> tri;
    };
}