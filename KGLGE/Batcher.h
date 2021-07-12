#pragma once
#include "Math.hpp"
#include "GameObject.h"
/// <summary>
/// Solid state machine where using addToBatcher edits wherever the pointer is currently pointed to
/// countingVar determines where the pointer is
/// 
/// </summary>
namespace KGLGE {
	class Batcher
	{
	public:
		/// <summary>
		/// Adds an object to the batcher, and then adds to the count the number of elements
		/// </summary>
		/// <param name="pos">The Position to be added</param>
		void addToBatcher(Vertex pos);
		/// <summary>
		/// Increases the count by count, used to pass by objects and not edit them
		/// </summary>
		/// <param name="count"></param>
		void addByCount(int count);
		/// <summary>
		/// Resets count to begining
		/// </summary>
		void resetCount();
		float* getValues;
	private:
		float m_values[4000];
		unsigned int m_pointer = 0;
	};
}

