#pragma once
#include "Animal.h"

using namespace std;

class Wolf : public Animal
{
	public:
		Wolf(Position position, World& world_ref);
		Wolf(World& world_ref);

		Organism* clone(Position position, World& world_ref);
};