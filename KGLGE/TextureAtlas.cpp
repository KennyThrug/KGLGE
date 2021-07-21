#include "TextureAtlas.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <STB_IMAGE/stb_image.h>
#endif // !STB_IMAGE_IMPLEMENTATION

GLuint KGLGE::loadTexture(const std::string& fileName, unsigned char textureSlot)
{
	int w, h, bpp;
	return loadTexture(fileName, textureSlot, &w, &h, &bpp);
}

GLuint KGLGE::loadTexture(const std::string& fileName, unsigned char textureSlot, int* width, int* height, int* bpp)
{
	glActiveTexture(GL_TEXTURE0 + textureSlot);
	auto* pixels = stbi_load(fileName.c_str(), width, height, bpp, STBI_rgb_alpha);
	GLuint textureID;
	glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, *width, *height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	stbi_image_free(pixels);

	glActiveTexture(GL_TEXTURE0 + textureSlot);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBindTextureUnit(textureSlot, textureID);

	return textureID;
}

KGLGE::TextureAtlas::TextureAtlas(const std::string& folderPath, unsigned int layer)
	:layer(layer)
{
	KGLGE::loadTexture(folderPath + "texture.png",layer,&m_width,&m_height,&m_bpp);
	readJSon(folderPath + "metadata.json");
}

KGLGE::TextureAtlas::~TextureAtlas()
{
	for (int i = 0; i < loadedTextures.size(); i++) {
		delete loadedTextures[i];
	}
	delete& loadedTextures;
}

std::array<KGLGE::Position, 4> KGLGE::TextureAtlas::getPositionsOf(const std::string& fileName)
{
	std::array<KGLGE::Position, 4> arr{ { {0,0},{0,0},{0,0},{0,0} } };
	for (int i = 0; i < loadedTextures.size(); i++) {
		if (loadedTextures[i]->fileName == fileName) {
			arr = getPositionsOf(i);
			break;
		}
	}
	return arr;
}

std::array<KGLGE::Position, 4> KGLGE::TextureAtlas::getPositionsOf(unsigned int index)
{
	std::array<KGLGE::Position, 4> arr{ { {0,0},{0,0},{0,0},{0,0} } };

	arr[0] = { float(loadedTextures[index]->X_Position), loadedTextures[index]->Y_Position };
	arr[1] = { float(loadedTextures[index]->X_Position) + float(loadedTextures[index]->X_texSize), float(loadedTextures[index]->Y_Position) };
	arr[2] = { float(loadedTextures[index]->X_Position) + float(loadedTextures[index]->X_texSize), float(loadedTextures[index]->Y_Position) + float(loadedTextures[index]->Y_texSize) };
	arr[3] = { float(loadedTextures[index]->X_Position), float(loadedTextures[index]->Y_Position) + float(loadedTextures[index]->Y_texSize) };
	return arr;
}

void KGLGE::TextureAtlas::readJSon(const std::string& fileName)
{		
	std::string line;
	int i = 0;

	std::ifstream input;
	input.open(fileName);
	nlohmann::json j;
	input >> j;
	for (int i = 0; i < j["Metadata"].size(); i++) {
		Texture* t = new Texture;
		loadedTextures.push_back(t);
		loadedTextures[i]->fileName = j["Metadata"][i]["name"];
		loadedTextures[i]->X_Position = j["Metadata"][i]["x"];
		loadedTextures[i]->Y_Position = j["Metadata"][i]["y"];
		loadedTextures[i]->X_texSize= j["Metadata"][i]["width"];
		loadedTextures[i]->Y_texSize = j["Metadata"][i]["height"];
		normalizeTexture(i);
	}
}

void KGLGE::TextureAtlas::normalizeTexture(unsigned int index)
{
	loadedTextures[index]->X_Position = normalize(m_width, loadedTextures[index]->X_Position);
	loadedTextures[index]->X_texSize = normalize(m_width, loadedTextures[index]->X_texSize);
	loadedTextures[index]->Y_Position = normalize(m_height, loadedTextures[index]->Y_Position);
	loadedTextures[index]->Y_texSize = normalize(m_height, loadedTextures[index]->Y_texSize);
}

std::string KGLGE::TextureAtlas::getValOfLine(std::string line)
{
	std::string p;
	for (int k = line.size() - 2; line[k] == '\"'; k--) {
		p = line[k] + p;
	}
	return p;
}

float KGLGE::TextureAtlas::normalize(int max, int first)
{
	if(first == 0)
		return 0;
	return (float(first) / float(max));
}
