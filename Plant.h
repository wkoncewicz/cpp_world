#pragma once
#include "Organism.h"

class Plant : public Organism
{
	public:
		Plant(int power, int initiative, int liveLength, int powerToReproduce, Position position, World world);
		Plant();

		vector<Result> move();
		vector<Result> action();
};