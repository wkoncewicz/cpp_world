#include "Toadstool.h"
#include <iostream>

Toadstool::Toadstool(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref)
    : Plant(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
    setSpecies("T");
}

Toadstool::Toadstool(Position position, World& world_ref) : Plant(0, 0, 12, 4, position, world_ref)
{
	setSpecies("T");
}

Toadstool::Toadstool(World& world_ref) : Plant(world_ref)
{
	setSpecies("T");
}

Organism* Toadstool::clone(Position position, World& world_ref){
	return new Toadstool(position, world_ref);
}

vector<Result*> Toadstool::consequences(Organism* attackingOrganism){
	vector<Result*> results;
	if (this->power > attackingOrganism->getPower()){
		results.push_back(new Result(3, Position(-1, -1), 0, attackingOrganism));
	} else {
		results.push_back(new Result(3, Position(-1, -1), 0, attackingOrganism));
		results.push_back(new Result(3, Position(-1, -1), 0, this));
	}
	return results;
}