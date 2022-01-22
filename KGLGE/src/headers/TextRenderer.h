#pragma once
#include "Sprite.h"
#include "TextureAtlas.h"
//#include "LetterValues.h"
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
            KGLGE::TextureAtlas* font;
            std::vector<KGLGE::Sprite*> letters;
    };
}