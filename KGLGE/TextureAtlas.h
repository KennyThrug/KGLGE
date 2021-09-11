#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <array>
#include "Math.hpp"
#include "ShaderProgram.h"
#include <json.hpp>
namespace KGLGE {
	/// <summary>
	/// Loads a texture, and sets it to a Sampler slot
	/// </summary>
	/// <param name="fileName"></param>
	/// <param name="textureSlot"></param>
	/// <returns></returns>
	GLuint loadTexture(const std::string& fileName, unsigned char textureSlot);
	GLuint loadTexture(const std::string& fileName, unsigned char textureSlot,
		int* width, int* height, int* bpp);
	class TextureAtlas {
	public:
		struct Texture {
			std::string fileName;
			float X_texSize;
			float Y_texSize;
			float X_Position;
			float Y_Position;
		};
		/// <summary>
		/// Creates a Texture atlas, makes the values needed for it, and loads it to the shader
		/// </summary>
		TextureAtlas(const std::string& folderPath,unsigned int layer);
		~TextureAtlas();
		std::array<Position,4> getPositionsOf(const std::string& fileName);
		std::array<Position, 4> getPositionsOf(unsigned int index);
		unsigned int layer;
	private:
		void readJSon(const std::string& fileName);
		void normalizeTexture(unsigned int index);
		std::string getValOfLine(std::string line);
		float normalize(int max, int first);

		int m_width, m_height, m_bpp;
		std::vector<Texture*> loadedTextures;
	};
}