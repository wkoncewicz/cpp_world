#include "Toadstool.h"

Toadstool::Toadstool(Position position, World world) : Plant(0, 0, 12, 4, position, world)
{
	setSpecies("T");
}

Toadstool::Toadstool() : Plant()
{
	setSpecies("T");
}

void Toadstool::initParams(){
	this->setPower(0);
	this->setInitiative(0);
	this->setLiveLength(12);
	this->setPowerToReproduce(4);
}

Result* Toadstool::consequences(Organism* attackingOrganism){
	Result* result;
	if (this->power > attackingOrganism->getPower()){
		result = new Result(3, Position(-1, -1), 0, attackingOrganism);
	} else {
		result = new Result(3, Position(-1, -1), 0, attackingOrganism);
		result = new Result(3, Position(-1, -1), 0, this);
	}
	return result;
}