#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
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
		/// <summary>
		/// Creates a Texture atlas, makes the values needed for it, and loads it to the shader
		/// </summary>

	private:
		std::vector<Texture> loadedTextures;
	};
}