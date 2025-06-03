#include "Organism.h"
#include "World.h"
#include <iostream>

Organism::Organism(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref_param) :
    world(world_ref_param),
    power(power),
    initiative(initiative),
    liveLength(liveLength),
    powerToReproduce(powerToReproduce),
    position(position),
    species("O") {}

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