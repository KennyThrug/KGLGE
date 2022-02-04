#include "../headers/TextRenderer.h"
KGLGE::TextRenderer::TextRenderer(KGLGE::TextureAtlas* fontAtlas) : font(fontAtlas) {

}
KGLGE::Position KGLGE::TextRenderer::addText(float x, float y, float fontSize, unsigned int letterCode){
    if(letterCode != KGLGE_Space){
        KGLGE::Sprite* letter = new KGLGE::Sprite(font,x,y,fontSize,fontSize,letterCode,2);
        addGameObject(letter);
    }
    
    return {x + (fontSize * 1.1f), y};
}
KGLGE::Position KGLGE::TextRenderer::addText(float x, float y, float fontSize, std::string str){
    float letter_x = x;
    float letter_y = y;
    for(int i = 0; i < str.size();i++){
        letter_x = addText(letter_x,letter_y,fontSize,convertCharToInt(str[i])).x;
        if(letter_x + fontSize >= allGameObjects->windowSize.max_x){
            letter_x = x;
            letter_y -= (fontSize * 1.5f);
        }
        else if(letter_x + fontSize <= allGameObjects->windowSize.min_x){
            letter_x = x;
            letter_y -= (fontSize * 1.5f);
        }
    }
    return {letter_x, letter_y};
}
KGLGE::Position KGLGE::TextRenderer::addTextFromKeyCode(float x, float y, float fontSize, unsigned int keyCode, bool shift){
    return addText(x,y,fontSize,convertKeyToLetter(keyCode,shift));
}
void KGLGE::TextRenderer::update(){

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
bool KGLGE::TextRenderer::respondToKey(unsigned int key){
    return false;
}