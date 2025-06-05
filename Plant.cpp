#include "Plant.h"
#include "World.h"
#include <iostream>
#include <cstdlib>

Plant::Plant(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref) 
	: Organism(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
	setSpecies("P");
}

Plant::Plant(World& world_ref) 
	: Organism(world_ref)
{
	setSpecies("P");
}

vector<Result*> Plant::move()
{
	vector<Result*> results;
	return results;
}
