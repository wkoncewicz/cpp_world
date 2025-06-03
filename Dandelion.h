#pragma once
#include "Plant.h"

class Dandelion : public Plant
{
	public:
		Dandelion(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref);
		Dandelion(Position position, World& world_ref);
		Dandelion(World& world_ref);

		Organism* clone(Position position, World& world_ref);
};