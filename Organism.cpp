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
    species("O"),
	lifeRecord(new LifeRecord(1, -1)),
	ancestry({}) {}

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

LifeRecord* Organism::getLifeRecord(){
	return this->lifeRecord;
}

void Organism::setLifeRecord(LifeRecord* LifeRecord){
	this->lifeRecord = lifeRecord;
}

vector<LifeRecord*> Organism::getAncestry(){
	return this->ancestry;
}

void Organism::setAncestry(vector<LifeRecord*> ancestry){
	this->ancestry = ancestry;
}

vector<Result*> Organism::consequences(Organism* attackingOrganism){
	vector<Result*> results;
	if (this->power > attackingOrganism->getPower()){
		results.push_back(new Result(3, Position(-1, -1), 0, attackingOrganism));
	} else {
		results.push_back(new Result(3, Position(-1, -1), 0, this));
	}
	return results;
}

bool Organism::ifReproduce(){
	bool result = false;
	if (this->power >= this->powerToReproduce){
		result = true;
	}
	return result;
}

vector<Result*> Organism::action(){
	vector<Result*> results;
	vector<Position> birthPositions = getVectorOfFreePositionsAround();

	if (this->ifReproduce() && !birthPositions.empty()){
		int randomIndex = std::rand() % birthPositions.size();
		Position newOrganismPosition = birthPositions[randomIndex];
		Organism* newOrganism = this->clone(newOrganismPosition, this->world);
		newOrganism->getLifeRecord()->setBirthTurn(this->world.getTurn());
		vector<LifeRecord*> newAncestry = this->ancestry;
		newAncestry.push_back(this->lifeRecord);
		newOrganism->setAncestry(newAncestry);
		// cout << "My ancestors:" << endl;
		// for (LifeRecord* ancestor : newOrganism->getAncestry()){
		// 	cout << "Birth:" << endl << ancestor->getBirthTurn() << endl << "Death:" << endl << ancestor->getDeathTurn() << endl;
		// }
		this->power = this->power/2;
		results.push_back(new Result(0, newOrganismPosition, 0, newOrganism));
	}
	return results;
}

vector<Position> Organism::getVectorOfFreePositionsAround(){
	return this->world.getVectorOfFreePositionsAround(this->position);
}