#pragma once
#include "Plant.h"

class Toadstool : public Plant
{
	public:
		Toadstool(Position position, World& world_ref);
		Toadstool(World& world_ref);

		Organism* clone(Position position, World& world_ref);
		Result* consequences(Organism* attackingOrganism);
};