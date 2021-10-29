#pragma once
#include "Math.hpp"
#include <stack>
#include <vector>
namespace KGLGE {
	class AllGameObjects;
	struct Vertex {
		Position position;
		Position texPos;
		float texID;
		float red; float green; float blue; float alpha;
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
		//Generally don't manually delete this. It will probably be bad. instead use loop.removeGameObject
		bool deleted = false;
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

		virtual float getX() { return m_x; }
		virtual float getY() { return m_y; };
		virtual float getWidth() { return m_Width; };
		virtual float getHeight() { return m_Height; };

		float m_x;
		float m_y;
		float m_Width;
		float m_Height;

		/// <summary>
		/// </summary>
		/// <returns>Number of Indicies that are returned with getIndicies</returns>
		virtual unsigned int getNumTriangles() = 0;
	protected:
		AllGameObjects* allGameObjects;
	};

	class AllGameObjects {
		struct GameObjectLocation {
			int layer;
			int location;
		};
	public:
		unsigned int addGameObject(GameObject* obj, unsigned int layer) {
			if (stk[layer].empty()) {
				gameObjects[layer].push_back(obj);
				m_numGameObjects[layer]++;
				return m_numGameObjects[layer] - 1;
			}
			else {
				int re = stk[layer].top();
				delete gameObjects[layer][re];
				gameObjects[layer][re] = obj;
				stk[layer].pop();
				m_numGameObjects[layer]++;
				return re;
			}
			return 0;
		}
		void removeGameObject(unsigned int layer, unsigned int index) {
			gameObjects[layer][index]->deleted = true;
			stk[layer].push(index);
			m_numGameObjects[layer]--;
		}
		GameObject* getGameObject(int layer, int location) {
			return gameObjects[layer][location];
		}
		unsigned int getNumGameObjects(int layer) {
			return m_numGameObjects[layer];
		}
	private:
		std::stack<int> stk[6];

	protected:
		std::array<std::vector<GameObject*>, 6> gameObjects;
		unsigned char m_numGameObjects[6];
	};
}