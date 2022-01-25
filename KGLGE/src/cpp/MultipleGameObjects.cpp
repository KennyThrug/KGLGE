#include "../headers/MultipleGameObjects.h"

void KGLGE::MultipleGameObjects::addGameObject(GameObject* go){
    gameObjects.push_back(go);
    shouldUpdate = true;
}

KGLGE::Vertex* KGLGE::MultipleGameObjects::getVertexes(){
    verticies.clear();
    for(int i = 0; i < gameObjects.size(); i++){
        int numVertex = gameObjects[i]->getNumVertex();
        for(int j = 0; j < numVertex; j++){
            verticies.push_back(gameObjects[i]->getVertexes()[j]);
        }
    }
    return verticies.data();
}
unsigned int KGLGE::MultipleGameObjects::getNumVertex(){
    unsigned int numVertex = 0;
    for(int i = 0; i < gameObjects.size(); i++){
        numVertex += gameObjects[i]->getNumVertex();
    }
    return numVertex;
}
KGLGE::Triangle* KGLGE::MultipleGameObjects::getIndicies(unsigned int offset){
    tri.clear();
    unsigned int off = offset;
    for(int i = 0; i < gameObjects.size(); i++){
        int numTriangles = gameObjects[i]->getNumTriangles();
        Triangle* triangle = gameObjects[i]->getIndicies(off);
        for(int j = 0; j < numTriangles; j++){
            tri.push_back(triangle[j]);
        }
        off += gameObjects[i]->getNumVertex();
    }
    return tri.data();
}
unsigned int KGLGE::MultipleGameObjects::getNumTriangles(){
    unsigned int numTri = 0;
    for(int i = 0; i < gameObjects.size(); i++){
        numTri += gameObjects[i]->getNumTriangles();
    }
    return numTri;
}