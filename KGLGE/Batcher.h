#pragma once
#include "Math.hpp"
#include "GameObject.h"
#include "ShaderProgram.h"
/// <summary>
/// Solid state machine where using addToBatcher edits wherever the pointer is currently pointed to
/// countingVar determines where the pointer is
/// 
/// </summary>
namespace KGLGE {
	class Batcher
	{
	public:
		Batcher(ShaderProgram* shader) : p_Shader(shader){}
		void increaseCounter(unsigned int count) { m_Vertex_pointer += count; }
		void increaseIndex(unsigned int count) { m_Index_pointer += count; }
		void resetCounters() { m_Vertex_pointer = 0; m_Index_pointer = 0; }
		void paint();		
		void setValues(Vertex* verticies, unsigned int numVerticies,Triangle* indicies, unsigned int numTriangles);

		unsigned int getVertexPointer() { return m_Vertex_pointer; };
		unsigned int getIndexPointer() { return m_Index_pointer; };
	private:
		ShaderProgram* p_Shader;
		unsigned int m_Vertex_pointer = 0;
		unsigned int m_Index_pointer = 0;
	};
}

