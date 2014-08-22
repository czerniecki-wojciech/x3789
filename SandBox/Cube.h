#pragma once
#include "SandBoxCommonHeader.h"


class DLL_INTERFACE Cube
{
private:
	//std::atomic<short> paint_vector;
	//std::atomic<short> painted_counter;

	short paint_vector;
	short painted_counter;

	float x, y;
	float azimuth, elevation;

	Cube* cubes[6];

	inline Cube* cubeOnSide(short side){
		return NULL;
	}

	inline Cube*  opositSideCube(short side)
	{
		switch (side)
		{
		case CUBE_FRONT_SIDE:
			return cubes[1];
		case CUBE_BACK_SIDE:
			return cubes[0];
		case CUBE_UP_SIDE:
			return cubes[3];
		case CUBE_DOWN_SIDE:
			return cubes[2];
		case CUBE_LEFT_SIDE:
			return cubes[5];
		case CUBE_RIGHT_SIDE:
			return cubes[4];
		default:
			return NULL;
		}
	}

	void paintSide(short side);
public:
	void paint(short side)
	{
		if (painted_counter == 3)
			return;

		if (paint_vector & side)
			return;

		if (opositSideCube(side) == NULL)
			return;

		painted_counter++;

		paint_vector |= side;
		paintSide(side);
	}


	inline void resetPaintVector()
	{
		paint_vector = 0; 
		painted_counter = 0;
	}

	Cube() {}


	~Cube();
};

