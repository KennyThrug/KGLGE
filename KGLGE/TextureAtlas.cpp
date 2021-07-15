#include "TextureAtlas.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <STB_IMAGE/stb_image.h>
#endif // !STB_IMAGE_IMPLEMENTATION

#define currentPath "D:/Github/KGLGE/KGLGE"

void KGLGE::TextureAtlas::addTextureToCache(unsigned int id) 
{
	cachedValues.push_back(id);
}

void KGLGE::TextureAtlas::createTextureAtlas(std::string SpriteIndex)
{
	std::sort(cachedValues.begin(), cachedValues.end());

	//TODO: Implement in same way as ShaderProgram's ReadProgram
	std::ifstream stream(SpriteIndex);

	std::vector<std::string> fileNames;

	std::string line;
	unsigned int count = 0;
	unsigned int num = 0;
	while (getline(stream, line) && num < cachedValues.size()) {
		if (line.c_str()[0] != '#') {
			if (count == cachedValues[num]) {
				fileNames.push_back(line);
				moveImageToFolder(line,num);
				num++;
			}
			count++;
		}
	}
	system("res\\texture-atlas-generator\\atlas_generator.exe res\\texture-atlas-generator\\textures");
	loadTexture("texture_atlas.png");

	moveAllFilesBack(fileNames);
	system("del texture_atlas.png");
}

GLuint KGLGE::TextureAtlas::loadTexture(const std::string& fileName)
{
	int w, h, bits;
	auto* pixels = stbi_load(fileName.c_str(), &w, &h, &bits, STBI_rgb_alpha);
	GLuint textureID;
	glCreateTextures(GL_TEXTURE_2D, 1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

	stbi_image_free(pixels);

	return textureID;
}

void KGLGE::TextureAtlas::moveAllFilesBack(std::vector<std::string> files)
{		
	std::string first;
	std::string last;
	for (unsigned int i = 0; i < files.size(); i++) {
		first = currentPath;
		first.append("/res/texture-atlas-generator/textures/Tex");
		first.append(std::to_string(i));
		first.append(".png");
		last = currentPath;
		last.append("/res/sprites/");
		last.append(files[i]);
		std::rename(first.c_str(), last.c_str());
	}
}

void KGLGE::TextureAtlas::moveImageToFolder(const std::string& fileName, unsigned int index)
{
	std::string first = currentPath;
	first.append("/res/sprites/");
	first.append(fileName);
	std::string last = currentPath;
	last.append("/res/texture-atlas-generator/textures/Tex");
	last.append(std::to_string(index));
	last.append(".png");
	std::rename(first.c_str(), last.c_str());
}
