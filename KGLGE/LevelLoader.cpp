#include "LevelLoader.h"

void KGLGE::addCharsToBuffer(std::vector<char>* buffer, char* chars, int size)
{
	for (int i = 0; i < size; i++) {
		buffer->push_back(chars[i]);
	}
}

int getIntFromFile(unsigned char *buffer, int pointer) {
	char value[sizeof(int)];
	for (int i = 0; i < sizeof(int); i++) {
		value[i] = buffer[pointer+i];
	}
	return atof(value);
}
float getFloatFromFile(unsigned char* buffer, int pointer) {
	char value[sizeof(int)];
	for (int i = 0; i < sizeof(int); i++) {
		value[i] = buffer[pointer + i];
	}
	return atof(value);
}
void getCharFromFile(unsigned char *buffer, int pointer, int numBytes,char* dest) {
	std::vector<char> value;
	for (int i = 0; i < sizeof(char) * numBytes; i++) {
		value.push_back(buffer[pointer + i]);
	}
	memcpy(dest, value.data(), sizeof(char) * numBytes);
}

void KGLGE::loadLevel(const std::string& fileName, Level* lvl)
{
	std::ifstream input(fileName, std::ios::binary);

	// copies all data into buffer
	std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});

	unsigned char* bufferPointer = buffer.data();
	int arrow = 0; //pointer that runs through the char array

	//Number of TextureAtlas's
	lvl->numTextureAtlas = getIntFromFile((bufferPointer), arrow);
	arrow += sizeof(int);
	int count = 0;
	std::string curString = "";
	for (;;) {
		if (count == lvl->numTextureAtlas) {
			break;
		}
		else if (bufferPointer[arrow] == '\n') {
			lvl->atlasNames.push_back(curString);
			curString = "";
			count++;
			arrow++;
			lvl->layer.push_back(getIntFromFile(bufferPointer, arrow));
			arrow += sizeof(int) - 1;
		}
		else {
			curString += (bufferPointer[arrow]);
		}
		arrow += 1;
	}

	lvl->numObjects = getIntFromFile((bufferPointer), arrow); //number of Objects
	arrow += sizeof(int);
	//Go through all objects in level
	for (int i = 0; i < lvl->numObjects; i++) {
		lvl->body.push_back(KGLGE::Level::Body());
		//id of object
		lvl->body[i].id = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		//layer of object
		lvl->body[i].layer = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		//number of parameters
		lvl->body[i].numParameters = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		//Go through all Parameters
		for (int j = 0; j < lvl->body[i].numParameters; j++) {
			lvl->body[i].parameters.push_back(KGLGE::Level::Parameters());
			//type of parameter
			lvl->body[i].parameters[j].typeOfParameter = getIntFromFile(bufferPointer, arrow);
			arrow += sizeof(int);

			//parameter
			lvl->body[i].parameters[j].data = getFloatFromFile(bufferPointer, arrow);
			arrow += sizeof(float);
		}
	}
	lvl->numHandlers = getIntFromFile(bufferPointer, arrow);
	arrow += sizeof(int);
	for (int i = 0; i < lvl->numHandlers;i++) {
		lvl->handlers.push_back(KGLGE::KeyHandler());
		lvl->handlers[i].pressOnce = bufferPointer[arrow] == 't' ? true : false;
		arrow++;
		lvl->handlers[i].layer = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		lvl->handlers[i].num = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		lvl->handlers[i].key = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);
	}
	//Properties
	lvl->numProperties = getIntFromFile(bufferPointer, arrow);
	arrow += sizeof(int);
	for (int i = 0; i < lvl->numProperties; i++) {
		lvl->properties.push_back(KGLGE::GameObjectLocation());
		lvl->properties[i].layer = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		lvl->properties[i].location = getIntFromFile(bufferPointer, arrow);
		arrow += sizeof(int);

		lvl->propertyKey.push_back(getIntFromFile(bufferPointer, arrow));
		arrow += sizeof(int);
	}
}

void KGLGE::saveLevel(const std::string& fileName, Level lvl)
{
	std::vector<char> fullBuffer;
	char buffer[64];

	//Texture Atlas Stuff
	sprintf(buffer, "%i", lvl.numTextureAtlas);
	addCharsToBuffer(&fullBuffer, buffer, sizeof(int));
	for (int i = 0; i < lvl.numTextureAtlas; i++) {
		const char* charRepString = lvl.atlasNames[i].c_str();
		for (int j = 0; j < lvl.atlasNames[i].size(); j++) {
			fullBuffer.push_back(charRepString[j]);
		}
		fullBuffer.push_back('\n');
		sprintf(buffer, "%i", lvl.layer[i]);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));
	}

	//Game Object Stuff
	sprintf(buffer, "%i", lvl.numObjects);
	addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

	for (int i = 0; i < lvl.numObjects; i++) {
		sprintf(buffer, "%i", lvl.body[i].id);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf(buffer, "%i", lvl.body[i].layer);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf(buffer, "%i", lvl.body[i].numParameters);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		for (int j = 0; j < lvl.body[i].numParameters; j++) {
			sprintf(buffer, "%i", lvl.body[i].parameters[j].typeOfParameter);
			addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

			sprintf(buffer, "%f", lvl.body[i].parameters[j].data);
			addCharsToBuffer(&fullBuffer, buffer, sizeof(float));
		}
	}
	sprintf(buffer, "%i", lvl.numHandlers);
	addCharsToBuffer(&fullBuffer, buffer, sizeof(int));
	for (int i = 0; i < lvl.numHandlers; i++) {
		fullBuffer.push_back(lvl.handlers[i].pressOnce ? 't' : 'f');

		sprintf(buffer, "%i", lvl.handlers[i].layer);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf(buffer, "%i", lvl.handlers[i].num);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf(buffer, "%i", lvl.handlers[i].key);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));
	}
	//Properties

	sprintf(buffer, "%i", lvl.numProperties);
	addCharsToBuffer(&fullBuffer, buffer, sizeof(int));
	for (int i = 0; i < lvl.numProperties; i++) {
		sprintf(buffer, "%i", lvl.properties[i].layer);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf(buffer, "%i", lvl.properties[i].location);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf(buffer, "%i", lvl.propertyKey[i]);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));
	}
	std::ofstream file(fileName, std::ios::binary);
	file.write(fullBuffer.data(), fullBuffer.size());
}

KGLGE::Level KGLGE::convertAllGameObjectsToLevel(AllGameObjects* all)
{
	Level lvl;
	int numGameObjects = 0;
	int numParameters = 0;
	lvl.numTextureAtlas = all->getNumberTextureAtlas();
	for (int i = 0; i < lvl.numTextureAtlas; i++) {
		lvl.atlasNames.push_back(all->getAtlasPath(i));
		lvl.layer.push_back(all->getAtlasLayer(i));
	}

	for (int i = 0; i < NumLayers; i++) {
		for (int j = 0; j < all->getNumGameObjects(i); j++) {
			KGLGE::Level::Body bd = {
				all->getGameObject(i, j)->getGameObjectID(),
				i,
				all->getGameObject(i, j)->getNumProperties(),
				std::vector<KGLGE::Level::Parameters>()
			};
			lvl.body.push_back(bd);
			for (int k = 0; k < lvl.body[lvl.body.size()-1].numParameters; k++) {
				KGLGE::Level::Parameters param = {
					all->getGameObject(i,j)->getPropertyID(k),
					all->getGameObject(i,j)->getProperty(k)
				};

				lvl.body[lvl.body.size() - 1].parameters.push_back(param);
			}
			numGameObjects++;
		}
	}
	lvl.numHandlers = all->handlers.size();
	for (int i = 0; i < lvl.numHandlers; i++) {
		lvl.handlers.push_back(all->handlers[i]);
	}
	lvl.numProperties = 0;
	for (int i = 0; i < all->properties.size(); i++) {
		for (int j = 0; j < all->properties[i].size(); j++) {
			lvl.properties.push_back(GameObjectLocation());
			lvl.properties[lvl.numProperties].layer = all->properties[i][j].layer;
			lvl.properties[lvl.numProperties].location = all->properties[i][j].location;
			lvl.propertyKey.push_back(all->propertykey[i]);
			lvl.numProperties++;
		}
	}
	lvl.numObjects = numGameObjects;
	return lvl;
}
