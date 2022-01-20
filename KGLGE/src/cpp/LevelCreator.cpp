#include "../headers/LevelCreator.h"
	KGLGE::LevelCreator::LevelCreator() {

	}

	//Calls the update Function of all interior objects
	void KGLGE::LevelCreator::update(){
		bg->update();
	}
	//Gets the Vertex of all Interior Objects
	KGLGE::Vertex* KGLGE::LevelCreator::getVertexes(){
		return bg->getVertexes();
	}
	//Gets the NumVertex of All Interior Objects
	unsigned int KGLGE::LevelCreator::getNumVertex(){
		return bg->getNumVertex();
	}
	//I think you get the gist by now, however this one also will make a mock object if it is supposed to be invisable and will display nothing
	KGLGE::Triangle* KGLGE::LevelCreator::getIndicies(unsigned int offset){
		if(!isVisable){
			std::vector<KGLGE::Triangle> temp;
			for(int i = 0; i < getNumTriangles(); i++){
				temp.push_back({0,0,0});
			}
			return temp.data();
		}
		return bg->getIndicies(offset);
	}
	unsigned int KGLGE::LevelCreator::getNumTriangles(){
		return bg->getNumTriangles();
	}

	//The Following Five Functions are useless, because there shouldn't be a situation in which I am saving this object. It should Only be made at runtime
	float KGLGE::LevelCreator::getProperty(int propertyNum){return 0;}
	int KGLGE::LevelCreator::getPropertyID(int propertyNum){return 0;}
	int KGLGE::LevelCreator::getPropertySize(int propertyNum){return 0;}
	int KGLGE::LevelCreator::getNumProperties(){return 0;}
	int KGLGE::LevelCreator::getGameObjectID(){return 0;}

	bool KGLGE::LevelCreator::respondToKey(unsigned int key){
		if(key == GLFW_KEY_F){
			createWindow();
			isVisable = !isVisable;
			shouldUpdate = true;
		}
		return false;
	}
	void KGLGE::LevelCreator::createWindow(){
		//TODO: Make The Background object fit nicely in the center of the screen.
		float width = allGameObjects->windowSize.max_x - allGameObjects->windowSize.min_x;
		float height = allGameObjects->windowSize.max_y - allGameObjects->windowSize.min_y;

		bg->m_x = allGameObjects->windowSize.min_x + (height / 3.0f);
		bg->m_y = allGameObjects->windowSize.min_y + (height / 3.0f);
		bg->m_Width = width / 3.0f;
		bg->m_Height = height / 3.0f;
	}