#pragma once
#include "Plant.h"

class Grass : public Plant
{
	public:
		Grass(Position position, World world);
		Grass();

		void initParams();
};