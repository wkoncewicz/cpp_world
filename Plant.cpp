#include "Plant.h"
#include "World.h"
#include <iostream>
#include <cstdlib>

Plant::Plant(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref) 
	: Organism(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
	setSpecies("P");
}

Plant::Plant(World& world_ref) 
	: Organism(world_ref)
{
	setSpecies("P");
}

vector<Result*> Plant::move()
{
	vector<Result*> results;
	return results;
}

vector<Result*> Plant::action(){
	vector<Result*> results;
	vector<Position> birthPositions = getVectorOfFreePositionsAround();

	if (this->ifReproduce() && !birthPositions.empty()){
		int randomIndex = std::rand() % birthPositions.size();
		Position newPlantPosition = birthPositions[randomIndex];
		Organism* newPlant = this->clone(newPlantPosition, this->world);
		this->power = this->power/2;
		results.push_back(new Result(0, newPlantPosition, 0, newPlant));
	}
	return results;
}