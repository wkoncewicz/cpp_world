#include "Dandellion.h"

Dandellion::Dandellion(Position position) : Plant(0, 0, 6, 2, position)
{
	setSpecies("D");
}

Dandellion::Dandellion() : Plant()
{
	setSpecies("D");
}