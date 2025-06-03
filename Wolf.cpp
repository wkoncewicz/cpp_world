#include "Wolf.h"

Wolf::Wolf(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref)
    : Animal(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
    setSpecies("W");
}

Wolf::Wolf(Position position, World& world_ref) : Animal(8, 5, 20, 16, position, world_ref)
{
	setSpecies("W");
}

Wolf::Wolf(World& world_ref) : Animal(world_ref)
{
	setSpecies("W");
}

Organism* Wolf::clone(Position position, World& world_ref){
	return new Wolf(position, world_ref);
}