#include "Sheep.h"


Sheep::Sheep(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref)
    : Animal(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
    setSpecies("S");
}

Sheep::Sheep(Position position, World& world_ref) : Animal(3, 3, 10, 6, position, world_ref)
{
	setSpecies("S");
}

Sheep::Sheep(World& world_ref) : Animal(world_ref)
{
	setSpecies("S");
}

Organism* Sheep::clone(Position position, World& world_ref){
	return new Sheep(position, world_ref);
}