#include "Plant.h"
#include <cstdlib>

Plant::Plant(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world_ref) 
	: Organism(power, initiative, liveLength, powerToReproduce, position, world_ref)
{
	setSpecies("P");
}

Plant::Plant(World& world_ref) : Organism(world_ref)
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
	Position newPosition;

	if (this->ifReproduce()){
		vector<Position> pomPositions = getVectorOfFreePositionsAround();

		if (!pomPositions.empty()){
			int randomIndex = std::rand() % pomPositions.size();
			Position newPosition = pomPositions[randomIndex];
			Organism* newPlant = this->clone(newPosition, this->world);
			this->power = this->power / 2;
			results.push_back(new Result(0, newPosition, 0, newPlant));
		}
		return results;
	}
}