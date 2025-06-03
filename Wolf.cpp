#include "Wolf.h"

Wolf::Wolf(Position position, World world) : Animal(8, 5, 20, 16, position, world)
{
	setSpecies("W");
}

Wolf::Wolf() : Animal()
{
	setSpecies("W");
}

void Wolf::initParams(){
	this->setPower(8);
	this->setInitiative(5);
	this->setLiveLength(20);
	this->setPowerToReproduce(16);
}