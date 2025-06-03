#pragma once
#include <string>
#include <vector>
#include "Position.h"
#include "Result.h"
#include "World.h"

using namespace std;

class Organism
{
private:
	int liveLength;
	int powerToReproduce;
	string species;
public:
	Organism(int power, int initiative, int liveLength, int powerToReproduce, Position position, World world);
	Organism() : power(0), initiative(0), liveLength(0), powerToReproduce(0), position(0, 0), species("O"), world(World(0, 0)) {};

	int power;
	World world;
	int initiative;
	Position position;

	int getPower();
	void setPower(int power);
	int getInitiative();
	void setInitiative(int initiative);
	int getLiveLength();
	void setLiveLength(int liveLength);
	int getPowerToReproduce();
	void setPowerToReproduce(int powerToReproduce);
	Position getPosition();
	void setPosition(Position position);
	void setWorld(World world);
	string getSpecies();
	void setSpecies(string spec);

	string toString();

	vector<Result*> move();
	vector<Result*> action();
	Result* consequences(Organism* attackingOrganism);
	bool ifReproduce();
	vector<Position> getVectorOfFreePositionsAround();

};