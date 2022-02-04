#include "../headers/LevelCreator.h"
	KGLGE::LevelCreator::LevelCreator() {
		addGameObject(bg);
		hideWindow();
	}

	//Calls the update Function of all interior objects
	void KGLGE::LevelCreator::update(){
		bg->update();
	}

	//The Following Five Functions are useless, because there shouldn't be a situation in which I am saving this object. It should Only be made at runtime
	float KGLGE::LevelCreator::getProperty(int propertyNum){return 0;}
	int KGLGE::LevelCreator::getPropertyID(int propertyNum){return 0;}
	int KGLGE::LevelCreator::getPropertySize(int propertyNum){return 0;}
	int KGLGE::LevelCreator::getNumProperties(){return 0;}
	int KGLGE::LevelCreator::getGameObjectID(){return 0;}

	bool KGLGE::LevelCreator::respondToKey(unsigned int key){
		if(key == GLFW_KEY_F){
			if(isVisable){
				hideWindow();
			}
			else{
				createWindow();
			}
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
	
	void KGLGE::LevelCreator::hideWindow(){
		bg->m_Width = 0;
		bg->m_Height = 0;
	}