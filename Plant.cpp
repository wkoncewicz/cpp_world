#include "Plant.h"
#include <cstdlib>

Plant::Plant(int power, int initiative, int liveLength, int powerToReproduce, Position position, World world) : Organism(power, initiative, liveLength, powerToReproduce, position, world)
{
	setSpecies("P");
}

Plant::Plant() : Organism()
{
	setSpecies("P");
}

vector<Result> Plant::move()
{
	vector<Result> results;
	return results;
}

vector<Result> Plant::action(){
	vector<Result> results;
	Plant newPlant;
	Position newPosition;

	if (this->ifReproduce()){
		vector<Position> pomPositions = getVectorOfFreePositionsAround();

		if (!pomPositions.empty()){
			int randomIndex = std::rand() % pomPositions.size();
			Position newPosition = pomPositions[randomIndex];
			Plant* newPlant = this;
			newPlant->initParams();
			newPlant->setPosition(newPosition);
			this->power = this->power / 2;
			results.push_back(Result(0, newPosition, 0, newPlant));
		}
		return results;
	}
}