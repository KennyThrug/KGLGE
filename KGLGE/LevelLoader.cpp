#include "LevelLoader.h"

KGLGE::GameObject* KGLGE::Level::getGameObjectTypeFromID(KGLGE::Level::Body bd)
{
	//Puts all the data in an array thats easier to use
	float temp[64];
	for (int i = 0; i < bd.numParameters; i++) {
		temp[i] = bd.parameters[i].data;
	}

	switch (bd.id) {
	case 0: //Square
		return new Square(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7]);
		break;
	case 1: //Sprite

		break;
	case 2: //image
		break;
	case 3: //TextureAtlas
		break;
	}
}

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
}

void KGLGE::saveLevel(const std::string& fileName, Level lvl)
{
	std::vector<char> fullBuffer;
	char buffer[64];
	sprintf_s(buffer, "%i", lvl.numObjects);
	addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

	for (int i = 0; i < lvl.numObjects; i++) {
		sprintf_s(buffer, "%i", lvl.body[i].id);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf_s(buffer, "%i", lvl.body[i].layer);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		sprintf_s(buffer, "%i", lvl.body[i].numParameters);
		addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

		for (int j = 0; j < lvl.body[i].numParameters; j++) {
			sprintf_s(buffer, "%i", lvl.body[i].parameters[j].typeOfParameter);
			addCharsToBuffer(&fullBuffer, buffer, sizeof(int));

			sprintf_s(buffer, "%f", lvl.body[i].parameters[j].data);
			addCharsToBuffer(&fullBuffer, buffer, sizeof(float));
		}
	}

	std::ofstream file(fileName, std::ios::binary);
	file.write(fullBuffer.data(), fullBuffer.size());
}

KGLGE::Level KGLGE::convertAllGameObjectsToLevel(AllGameObjects* all)
{
	Level lvl;
	int numGameObjects = 0;
	int numParameters = 0;
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
	lvl.numObjects = numGameObjects;
	return lvl;
}
