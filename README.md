# KGLGE
KGLGE: Kenny's openGL Game Engine. A Game Engine &amp; API that is being made by me for my own personal program.

Mainly writing this guide for myself because I am forgetful. Might eventually release this, but right now it's not the most user friendly thing in the world.

Instalation:
//Write this at some point

Dependencies:
* OpenGL (Should already be installed on your system with your GPU)
* GLFW
* GLEW
* STB_IMAGE
* nlohmann/json


# Getting Started

To Start using this program, you must Make Classes that Inheret the following class, and the following functions:

```c++
class GameLoop{
	virtual void update();
	virtual KGLGE::GameObject* getGameObjectTypeFromID(KGLGE::Level::Body bd);

}
```

The update Function is a function that is called every frame. It is seperate from any GameObject, which can be useful in situations where it needs to access other variables, or handle global events.

The "getGameObjectTypeFromID" function is a bit more complicated, so for now just have it call its superclass version, you will add stuff to it when you add new classes -
```c++
getGameObjectTypeFromID(KGLGE::Level::Body bd){
	return KGLGE::GameLoop::getGameObjectTypeFromID(bd);
}
```
To start the program, in your runner file, you this is the general start

```c++
void runProgram(){
	//Just a neccessary initialization function for openGL, generally safe to call this before you do anything else
	KGLGE::initializeGLFW();

	//Create a Window Object
	KGLGE::Window win(width,height,"name");
	//Display the window
	win.display();

	//Create a GameLoop, passing the Window as a parameter, must have displayed the window before making the GameLoop
	KGLGE::GameLoop loop(&win);

	//Here you create any GameObjects you want initialized on the scene, by either
	//a.) create them all manually
	KGLGE::Square sq(1, 1, 1, 1, 1, 1, 1, 1);
	loop.addGameObject(&sq, 1);

	//b.) load a level
		KGLGE::Level* lvl = new KGLGE::Level;
		KGLGE::loadLevel("res/Levels/levelname.lvl", lvl);
		loop.LoadLevel(lvl);


	//At this point, if you are editing a level, then uncomment the following line
	//loop.addLevelCreator();

	//Start the loop, and have the program run itself
	loop.startLoop();

}
```

# Making New GameObjects
Lets say you want to make a new GameObject: Heres a step by step on how to do that:

For the purposes of this example, we will be making a very simple square that switches from Red to Blue when you hit the spacebar, and Back to Red When you hit the 'C' Key

```c++
class RedAndBlue : public KGLGE::GameObject{
		virtual void update() override;
		virtual Vertex* getVertexes() override;
		virtual unsigned int getNumVertex() override;
		virtual Triangle* getIndicies(unsigned int offset) override;
		virtual bool respondToKey(unsigned int key) override;
		virtual int getGameObjectID() override;
		virtual float getProperty(int propertyNum) override;
		virtual int getPropertyID(int propertyNum) override;
		virtual int getPropertySize(int propertyNum) override;
		virtual int getNumProperties() override;
		virtual unsigned int getNumTriangles() override;
}
```
The functions are used as following:
* update()
	
	* Function that is called every frame as long as the GameObject is added to the current loop
* getVertexes(), getNumVertex(), getIndicies(unsigned int offset)
	* explained below
* respondToKey(unsigned int key)
	* This function listens for key presses, lets say you for example have an object that moves up when you press the W key, and moves down when you press the S key, the code for that would be:
	```c++
	virtual bool respondToKey(unsigned int key){
		if(key == GLFW_KEY_W){
			m_y += 10;
			shouldUpdate = true;
		}
		if(key == GLFW_KEY_S){
			m_y -= 10;
			shouldUpdate = true;
		}
		return true;
	}
	```
	* Honestly the return statement isn't used for anything.