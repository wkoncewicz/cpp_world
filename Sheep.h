#pragma once
#include "Animal.h"

using namespace std;

class Sheep : public Animal
{
	public:
		Sheep(Position position, World& world_ref);
		Sheep(World& world_ref);

		Organism* clone(Position position, World& world_ref);
};