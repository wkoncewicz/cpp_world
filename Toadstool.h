#pragma once
#include "Plant.h"

class Toadstool : public Plant
{
	public:
	Toadstool(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref);
		Toadstool(Position position, World& world_ref);
		Toadstool(World& world_ref);

		Organism* clone(Position position, World& world_ref);
		vector<Result*> consequences(Organism* attackingOrganism);
};