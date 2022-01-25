#pragma once
#include "Sprite.h"
#include "Square.h"
#include "MultipleGameObjects.h"
#include <string>
#include "TextureAtlas.h"
#include "LetterValues.h"
namespace KGLGE
{
    class TextRenderer : public KGLGE::MultipleGameObjects
    {
    public:
        ~TextRenderer()
        {
        }
        TextRenderer(KGLGE::TextureAtlas *fontAtlas);
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
        Position addTextFromKeyCode(float x, float y, float fontSize, unsigned int keyCode, bool shift);

        void update() override;
        int getGameObjectID() override;
        float getProperty(int propertyNum) override;
        int getPropertyID(int propertyNum) override;
        int getPropertySize(int propertyNum) override;
        int getNumProperties() override;
        virtual bool respondToKey(unsigned int key) override;

    private:
        KGLGE::TextureAtlas *font;
    };
}