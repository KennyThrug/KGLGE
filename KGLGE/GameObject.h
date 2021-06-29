#pragma once
class GameObject {
public:
	float * getArray();
	virtual void update() = 0;
private:
	float x, y, z;
	float tex;
};