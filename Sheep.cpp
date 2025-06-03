#include "Sheep.h"

Sheep::Sheep(Position position) : Animal(3, 3, 10, 6, position)
{
	setSpecies("S");
}

Sheep::Sheep() : Animal()
{
	setSpecies("S");
}