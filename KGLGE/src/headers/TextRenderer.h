#pragma once
#include "Sprite.h"
#include "Square.h"
#include <string>
#include "TextureAtlas.h"
#include "LetterValues.h"
namespace KGLGE{
    class TextRenderer : public KGLGE::GameObject{
        public:
            ~TextRenderer(){

            }
            TextRenderer(KGLGE::TextureAtlas* fontAtlas);
            /**
             * @brief 
             * 
             * @param x 
             * @param y 
             * @param fontSize 
             * @param letterCode 
             * @return Position the position of the next letter to be placed
             */
            Position addText(float x, float y, float fontSize, unsigned int letterCode);
            Position addText(float x, float y, float fontSize, std::string str);

			void update() override;
			Vertex* getVertexes() override;
			unsigned int getNumVertex() override;
			Triangle* getIndicies(unsigned int offset) override;
			int getGameObjectID() override;
			float getProperty(int propertyNum) override;
			int getPropertyID(int propertyNum) override;
			int getPropertySize(int propertyNum) override;
			int getNumProperties() override;
			unsigned int getNumTriangles() override;
			virtual bool respondToKey(unsigned int key) override;
        private:
            std::vector<Vertex> verticies;
            std::vector<Triangle> tri;
            KGLGE::TextureAtlas* font;
            std::vector<KGLGE::Sprite*> letters;
    };
}