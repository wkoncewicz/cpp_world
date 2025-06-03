#include "Dandelion.h"

Dandelion::Dandelion(Position position, World world) : Plant(0, 0, 6, 2, position, world)
{
	setSpecies("D");
}

Dandelion::Dandelion() : Plant()
{
	setSpecies("D");
}

void Dandelion::initParams(){
	this->setPower(0);
	this->setInitiative(0);
	this->setLiveLength(6);
	this->setPowerToReproduce(2);
}