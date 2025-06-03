#include "Toadstool.h"

Toadstool::Toadstool(Position position) : Plant(0, 0, 12, 4, position)
{
	setSpecies("T");
}

Toadstool::Toadstool() : Plant()
{
	setSpecies("T");
}