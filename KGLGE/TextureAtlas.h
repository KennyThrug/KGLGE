#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <filesystem>
#include <Windows.h>
#include <algorithm>
#include "ShaderProgram.h"
namespace KGLGE {
	class TextureAtlas {
	public:
		struct Texture {
			unsigned int id;
			float X_texCoord;
			float Y_texCoord;
			float X_Position;
			float Y_Position;
		};
		void addTextureToCache(unsigned int id);
		/// <summary>
		/// Creates a Texture atlas, makes the values needed for it, and loads it to the shader
		/// </summary>
		void createTextureAtlas(std::string spriteIndex);
	private:
		std::vector<unsigned int> cachedValues;
		std::vector<Texture> loadedTextures;
		GLuint loadTexture(const std::string& fileName);
		void moveImageToFolder(const std::string& fileName,unsigned int index);
		void moveAllFilesBack(std::vector<std::string> files);
	};
}