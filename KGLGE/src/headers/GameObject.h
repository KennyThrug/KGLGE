#pragma once
#include <stack>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Math.hpp"
#include <vector>
#include <string>

namespace KGLGE {

	//Number of layers total
#define NumLayers 6

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
		void addProperty(int prop) {
			properties.push_back(prop);
		}
		bool removeProperty(int prop) {
			for (int i = 0; i < properties.size(); i++) {
				if (properties[i] == prop) {
					properties.erase(i + properties.begin());
					return true;
				}
			}
			return false;
		}
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

		virtual int getGameObjectID() = 0;
		virtual float getProperty(int propertyNum) = 0;
		virtual int getPropertyID(int propertyNum) = 0;
		/// <summary>
		/// Get Size of the data of the property in bytes
		/// </summary>
		/// <param name="propertyNum"></param>
		/// <returns></returns>
		virtual int getPropertySize(int propertyNum) = 0;
		virtual int getNumProperties() = 0;

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
		void setAllGameObjects(AllGameObjects* all) { allGameObjects = all; }
		std::vector<int> properties;
	protected:
		AllGameObjects* allGameObjects;
	};


	struct GameObjectLocation {
		int layer;
		int location;
	};
	struct KeyHandler {
		unsigned int key;
		unsigned int layer;
		unsigned int num;
		bool pressOnce;
	};
	class AllGameObjects {

	public:
		std::vector<KeyHandler> handlers;
		GameObjectLocation addGameObject(GameObject* obj, unsigned int layer) {
			if (stk[layer].empty()) {
				gameObjects[layer].push_back(obj);
				m_numGameObjects[layer]++;
				return { (int)layer, m_numGameObjects[layer] - 1 };
			}
			else {
				int re = stk[layer].top();
				delete gameObjects[layer][re];
				gameObjects[layer][re] = obj;
				stk[layer].pop();
				m_numGameObjects[layer]++;
				return { (int)layer, re };
			}
			return {-1,-1};
		}
		void removeGameObject(unsigned int layer, unsigned int index) {
			gameObjects[layer][index]->deleted = true;
			stk[layer].push(index);
			m_numGameObjects[layer]--;
		}
		GameObject* getGameObject(int layer, int location) {
			return gameObjects[layer][location];
		}
		GameObject* getGameObject(GameObjectLocation location) {
			return getGameObject(location.layer, location.location);
		}
		unsigned int getNumGameObjects(int layer) {
			return m_numGameObjects[layer];
		}
		void addProperty(GameObjectLocation location, int prop) {
			getGameObject(location)->addProperty(prop);
			for (int i = 0; i < properties.size(); i++) {
				if (propertykey[i] == prop) {
					properties[i].push_back(location);
					return;
				}
			}
			std::vector<GameObjectLocation> temp;
			propertykey.push_back(prop);
			temp.push_back(location);
			properties.push_back(temp);
		}
		void addProperty(int layer, int location, int prop) {
			addProperty({ layer,location }, prop);
		}
		std::vector<GameObjectLocation> getAllObjectsWithProperty(int prop) {
			for (int i = 0; i < propertykey.size(); i++) {
				if (propertykey[i] == prop) {
					return properties[i];
				}
			}
			return std::vector<GameObjectLocation>();
		}
		unsigned int getNumberTextureAtlas() {
			return atlasFiles.size();
		}
		std::string getAtlasPath(unsigned int index) {
			return atlasFiles[index];
		}
		int getAtlasLayer(unsigned int index) {
			return atlasLayers[index];
		}
		void addAtlas(std::string filePath, int layer) {
			atlasFiles.push_back(filePath);
			atlasLayers.push_back(layer);
		}
		void removeAtlas(int index) {
			atlasLayers.erase(atlasLayers.begin() + index);
			atlasFiles.erase(atlasFiles.begin() + index);
		}
		std::vector<int> propertykey;
		std::vector<std::vector<GameObjectLocation>> properties;
	private:
		std::vector<std::string> atlasFiles;
		std::vector<int> atlasLayers;
		std::stack<int> stk[NumLayers];

	protected:
		std::array<std::vector<GameObject*>, NumLayers> gameObjects;
		unsigned char m_numGameObjects[NumLayers];
	};
}

