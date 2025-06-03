#include "Sheep.h"

Sheep::Sheep(Position position, World world) : Animal(3, 3, 10, 6, position, world)
{
	setSpecies("S");
}

Sheep::Sheep() : Animal()
{
	setSpecies("S");
}

void Sheep::initParams(){
	this->setPower(3);
	this->setInitiative(3);
	this->setLiveLength(10);
	this->setPowerToReproduce(6);
}