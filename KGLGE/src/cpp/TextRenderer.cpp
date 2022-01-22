#include "../headers/TextRenderer.h"
KGLGE::TextRenderer::TextRenderer(KGLGE::TextureAtlas* fontAtlas) : font(fontAtlas) {

}
KGLGE::Position KGLGE::TextRenderer::addText(float x, float y, float fontSize, unsigned int letterCode){
    KGLGE::Sprite* letter = new KGLGE::Sprite(font,x,y,fontSize,fontSize,letterCode,0);
    //KGLGE::Square* letter = new KGLGE::Square(x,y,fontSize,fontSize,1,0,0,1);
    letters.push_back(letter);
    shouldUpdate = true;
    return {x + (fontSize * 1.25f), y};
}
void KGLGE::TextRenderer::update(){

}
KGLGE::Vertex* KGLGE::TextRenderer::getVertexes(){
    verticies.clear();
    for(int i = 0; i < letters.size(); i++){
        int numVertex = letters[i]->getNumVertex();
        for(int j = 0; j < numVertex; j++){
            verticies.push_back(letters[i]->getVertexes()[j]);
        }
    }
    return verticies.data();
}
unsigned int KGLGE::TextRenderer::getNumVertex(){
    unsigned int numVertex = 0;
    for(int i = 0; i < letters.size(); i++){
        numVertex += letters[i]->getNumVertex();
    }
    return numVertex;
}
KGLGE::Triangle* KGLGE::TextRenderer::getIndicies(unsigned int offset){
    tri.clear();
    unsigned int off = offset;
    for(int i = 0; i < letters.size(); i++){
        int numTriangles = letters[i]->getNumTriangles();
        Triangle* triangle = letters[i]->getIndicies(off);
        for(int j = 0; j < numTriangles; j++){
            tri.push_back(triangle[j]);
        }
        off += letters[i]->getNumVertex();
    }
    return tri.data();
}
int KGLGE::TextRenderer::getGameObjectID(){
    return 0;
}
float KGLGE::TextRenderer::getProperty(int propertyNum){
    return 0;
}
int KGLGE::TextRenderer::getPropertyID(int propertyNum){
    return 0;
}

int KGLGE::TextRenderer::getPropertySize(int propertyNum){
    return 0;
}
int KGLGE::TextRenderer::getNumProperties(){
    return 0;
}
unsigned int KGLGE::TextRenderer::getNumTriangles(){
    unsigned int numTri = 0;
    for(int i = 0; i < letters.size(); i++){
        numTri += letters[i]->getNumTriangles();
    }
    return numTri;
}
bool KGLGE::TextRenderer::respondToKey(unsigned int key){
    if(key == GLFW_KEY_Q){
        addText(curLocation,0,0.1f,curLetter);
        curLocation += 0.15f;
        curLetter++;
        shouldUpdate = true;
    }
}