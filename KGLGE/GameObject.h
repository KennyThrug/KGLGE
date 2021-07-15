#pragma once
#include "Math.hpp"
namespace KGLGE {
	struct Vertex {
		Position position;
		Position texPos;
	};
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		/// <summary>
		/// Recalculates and returns an array of vertexes from the vectors provided
		/// </summary>
		/// <returns></returns>
		virtual Vertex* getVertexAtPos(unsigned int pos) = 0;
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		bool shouldUpdateVertex() {
			if (needsUpdate) {
				needsUpdate = false;
				return true;
			}
		}
		virtual void update() = 0;
		virtual unsigned int getNumVertex() = 0;
		virtual unsigned int getSizeOfVertexs() = 0;
	private:
		//x and y coordinants in a global scale (not on screen where its -1 to 1 but on your own scale
		float m_globalX;
		float m_globalY;
	protected:
		bool needsUpdate = true;
	};
}