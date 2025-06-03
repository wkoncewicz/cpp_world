#include "Wolf.h"

Wolf::Wolf(Position position) : Animal(8, 5, 20, 16, position)
{
	setSpecies("W");
}

Wolf::Wolf() : Animal()
{
	setSpecies("W");
}