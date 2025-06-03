#include "Dandelion.h"

Dandelion::Dandelion(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref)
    : Plant(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
    setSpecies("D");
}

Dandelion::Dandelion(Position position, World& world_ref) : Plant(0, 0, 6, 2, position, world_ref)
{
	setSpecies("D");
}

Dandelion::Dandelion(World& world_ref) : Plant(world_ref)
{
	setSpecies("D");
}

Organism* Dandelion::clone(Position position, World& world_ref){
	return new Dandelion(position, world_ref);
}