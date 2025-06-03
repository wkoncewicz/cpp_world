#include "Grass.h"

Grass::Grass(Position position, World& world_ref) : Plant(0, 0, 6, 3, position, world_ref)
{
	setSpecies("G");
}

Grass::Grass(World& world_ref) : Plant(world_ref)
{
	setSpecies("G");
}

Organism* Grass::clone(Position position, World& world_ref){
	return new Grass(position, world_ref);
}