#include "Math.hpp"
#include <iostream>

int main() {
	KGLGE::Position pos = KGLGE::VectorToPosition({ 10,0.25f * KGLGE::PI});
	std::cout << pos.x << std::endl;
	std::cout << pos.y << std::endl;
}