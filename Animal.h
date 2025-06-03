#pragma once
#include "Organism.h"

using namespace std;

class Animal : public Organism
{
	public:
		Animal(int power, int initiative, int liveLength, int powerToReproduce, Position position, World world);
		Animal();

		Position lastPosition;

		Position getLastPosition();
		void setLastPosition(Position lastPosition);
		vector<Position> getVectorOfPositionsAround();
		vector<Result*> action();
		vector<Result*> move();
};