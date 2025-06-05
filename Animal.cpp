#include "Animal.h"
#include "World.h"
#include <cstdlib>
#include <iostream>

Animal::Animal(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref)
    : Organism(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
    setSpecies("A");
    setLastPosition(position);
}

Animal::Animal(World& world_ref)
    : Organism(world_ref)
{
    setSpecies("A");
	this->setLastPosition(this->getPosition());
}

Position Animal::getLastPosition(){
	return this->lastPosition;
}

void Animal::setLastPosition(Position lastPosition){
	this->lastPosition = lastPosition;
}

vector<Result*> Animal::move(){
	vector<Result*> results;
	vector<Position> pomPositions = getVectorOfPositionsAround();
	Position newPosition;

	if (!pomPositions.empty()){
		int randomIndex = std::rand() % pomPositions.size();
		newPosition = pomPositions[randomIndex];
		results.push_back(new Result(2, newPosition, 0, this));
		this->lastPosition = this->position;
		Organism* metOrganism = this->world.getOrganismFromPosition(newPosition.getX(), newPosition.getY());
		if (metOrganism){
			vector<Result*> consequences = metOrganism->consequences(this);
			results.insert(results.end(), consequences.begin(), consequences.end());
		}
	}
	return results;
}

vector<Position> Animal::getVectorOfPositionsAround(){
	return this->world.getVectorOfPositionsAround(this->position);
}
