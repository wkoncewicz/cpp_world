#include "Grass.h"

Grass::Grass(Position position) : Plant(0, 0, 6, 3, position)
{
	setSpecies("G");
}

Grass::Grass() : Plant()
{
	setSpecies("G");
}