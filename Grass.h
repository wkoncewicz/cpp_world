#pragma once
#include "Plant.h"

class Grass : public Plant
{
	public:
		Grass(int power, int initiative, int liveLength, int powerToReproduce, Position position);
		Grass();

};