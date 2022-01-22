#include "../headers/TextRenderer.h"
KGLGE::TextRenderer::TextRenderer(KGLGE::TextureAtlas* fontAtlas) : font(fontAtlas) {

}
KGLGE::Position KGLGE::TextRenderer::addText(float x, float y, float fontSize, unsigned int letterCode){
    KGLGE::Sprite* letter = new KGLGE::Sprite(font,x,y,fontSize,fontSize,letterCode,0);
    letters.push_back(letter);
    shouldUpdate = true;
    return {x + fontSize, y};
}
void KGLGE::TextRenderer::update(){

}
KGLGE::Vertex* KGLGE::TextRenderer::getVertexes(){
    return nullptr;
}
unsigned int KGLGE::TextRenderer::getNumVertex(){
    return 0;
}
KGLGE::Triangle* KGLGE::TextRenderer::getIndicies(unsigned int offset){
    return nullptr;
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
    return 0;
}
bool KGLGE::TextRenderer::respondToKey(unsigned int key){
    return false;   
}