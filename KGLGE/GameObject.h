#pragma once
#include "Math.hpp"
namespace KGLGE {
	struct Vertex {
		Position position;
		Position texPos;
		float texID;
	};
	struct Triangle {
		unsigned int index1;
		unsigned int index2;
		unsigned int index3;
	};
	class GameObject
	{
	public:
		bool shouldUpdate;
		GameObject() { shouldUpdate = true; }
		/// <summary>
		/// This function is called every frame
		/// </summary>
		/// <returns>Whether or not to update the visuals of this gameObject</returns>
		virtual void update() = 0;
		/// <summary>
		/// Getter for the Vertexes. Note; will go out of scope if the Vertexes are instantiated on the Stack
		/// probably best to keep it on the Heap
		/// </summary>
		/// <returns>Returns an array of vertexes that reperesent the object</returns>
		virtual Vertex* getVertexes() = 0;
		/// <summary>
		/// </summary>
		/// <returns>Number of Verticies that are returned with getVertexes()</returns>
		virtual unsigned int getNumVertex() = 0;
		/// <summary>
		/// assuming that the Indicies of the verticies, assuming that it is the only set of vertexes
		/// </summary>
		/// <returns></returns>
		virtual Triangle* getIndicies(unsigned int offset) = 0;
		virtual bool respondToKey(unsigned int key) = 0;

		/// <summary>
		/// </summary>
		/// <returns>Number of Indicies that are returned with getIndicies</returns>
		virtual unsigned int getNumTriangles() = 0;
	};
}