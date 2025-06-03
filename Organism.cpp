#include "Organism.h"

Organism::Organism(int power, int initiative, int liveLength, int powerToReproduce, Position position, World world)
{
	setPower(power);
	setInitiative(initiative);
	setLiveLength(liveLength);
	setPowerToReproduce(powerToReproduce);
	setPosition(position);
	setWorld(world);
	setSpecies("O");
}

int Organism::getPower()
{
	return this->power;
}

void Organism::setPower(int power)
{
	this->power = power;
}

int Organism::getInitiative(){
	return this->initiative;
}

void Organism::setInitiative(int initiative){
	this->initiative = initiative;
}

int Organism::getLiveLength(){
	return this->liveLength;
}

void Organism::setLiveLength(int liveLength){
	this->liveLength = liveLength;
}

int Organism::getPowerToReproduce(){
	return this->powerToReproduce;
}

void Organism::setPowerToReproduce(int powerToReproduce){
	this->powerToReproduce = powerToReproduce;
}

Position Organism::getPosition()
{
	return this->position;
}

void Organism::setPosition(Position position)
{
	this->position = position;
}

void Organism::setWorld(World world){
	this->world = world;
}

string Organism::toString()
{
	return "{ species: " + this->getSpecies() + 
		", power: " + to_string(getPower()) + 
		", position: " + getPosition().toString() + "}";
}

string Organism::getSpecies()
{
	return this->species;
}

void Organism::setSpecies(string spec)
{
	this->species = spec;
}

Result* Organism::consequences(Organism* attackingOrganism){
	Result* result;
	if (this->power > attackingOrganism->getPower()){
		result = new Result(3, Position(-1, -1), 0, attackingOrganism);
	} else {
		result = new Result(3, Position(-1, -1), 0, this);
	}
	return result;
}

bool Organism::ifReproduce(){
	bool result = false;
	if (this->power >= this->powerToReproduce){
		result = true;
	}
	return result;
}

vector<Position> Organism::getVectorOfFreePositionsAround(){
	return this->world.getVectorOfFreePositionsAround(this->position);
}