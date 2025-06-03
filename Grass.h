#pragma once
#include "Plant.h"

class Grass : public Plant
{
	public:
		Grass(Position position, World& world_ref);
		Grass(World& world_ref);

		Organism* clone(Position position, World& world_ref);
};