#pragma once
#include "Plant.h"

class Toadstool : public Plant
{
	public:
		Toadstool(Position position, World world);
		Toadstool();

		void initParams();
		Result* consequences(Organism* attackingOrganism);
};