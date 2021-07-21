#pragma once
#include <array>
#include <tgmath.h>
namespace KGLGE {
	static const float PI = 3.14159265358979323846f;

	struct Vector
	{
		//The magnitude (length) of the line
		float magnitude;
		//The angle, in Radians, of the line from the x axis
		float direction;
	};
	struct Position
	{
		float x;
		float y;
	};

	/// <summary>
	/// Linearly interpolates between the startVal and the EndVal by a percentage
	/// </summary>
	/// <param name="startVal">The current Value of the function</param>
	/// <param name="endVal">The destination value of the function</param>
	/// <param name="time">the time that passes</param>
	/// <returns>the interpolated value</returns>
	static float lerp(float startVal, float endVal, float time) {
		return (1 - time) * startVal + time * endVal;
	}
	/// <summary>
	/// 
	/// </summary>
	/// <param name="origin">The starting position of the vector</param>
	/// <param name="vector">The vector added to the origin</param>
	/// <returns>The position at the end of the Vector</returns>
	static Position VectorToPosition(Position origin, Vector vector) {
		float x, y;
		y = (sin(vector.direction) * vector.magnitude) / sin(PI / 2);

		x = sqrt((vector.magnitude * vector.magnitude) - (y * y));
		return { origin.x + x,origin.y + y };
	}
	static std::array<Position, 4> rotate90deg(std::array<Position, 4> arr, unsigned int numRotations) {
		std::array<Position, 4> retrn;
		for (int i = 0; i < 4; i++) {
			unsigned int temp = i + numRotations;
			if (temp >= 4)
				temp -= 4;
			retrn[temp] = arr[i];
		}
		return retrn;
	}
	/// <summary>
	/// Assuming an origin of (0,0), returns the position of the end of the vector
	/// </summary>
	/// <param name="vector">The Vector to be found</param>
	/// <returns>The position of the end of the vector</returns>
	static Position VectorToPosition(Vector vector) {
		return VectorToPosition({ 0,0 }, vector);
	}
}