#pragma once
#include "Plant.h"

class Toadstool : public Plant
{
	public:
		Toadstool(int power, int initiative, int liveLength, int powerToReproduce, Position position);
		Toadstool();

};