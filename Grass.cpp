#include "Grass.h"

Grass::Grass(Position position, World world) : Plant(0, 0, 6, 3, position, world)
{
	setSpecies("G");
}

Grass::Grass() : Plant()
{
	setSpecies("G");
}

void Grass::initParams(){
	this->setPower(0);
	this->setInitiative(0);
	this->setLiveLength(6);
	this->setPowerToReproduce(3);
}