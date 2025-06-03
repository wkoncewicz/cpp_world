#pragma once
#include "Plant.h"

class Grass : public Plant
{
	public:
		Grass(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref);
		Grass(Position position, World& world_ref);
		Grass(World& world_ref);

		Organism* clone(Position position, World& world_ref);
};