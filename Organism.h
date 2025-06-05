#pragma once
#include <string>
#include <vector>
#include "Position.h"
#include "Result.h"
#include "LifeRecord.h"

using namespace std;

class World;

class Organism
{
private:
	int liveLength;
	int powerToReproduce;
	string species;
	LifeRecord* lifeRecord;
	vector<LifeRecord*> ancestry;

public:
	Organism(int power, int initiative, int liveLength, int powerToReproduce, Position position, World& world);
	Organism(World& world_ref) : power(0), initiative(0), liveLength(0), powerToReproduce(0), position(0,0), species("O"), world(world_ref) {};

	int power;
	World& world;
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
	string getSpecies();
	void setSpecies(string spec);
	LifeRecord* getLifeRecord();
	void setLifeRecord(LifeRecord* LifeRecord);
	vector<LifeRecord*> getAncestry();
	void setAncestry(vector<LifeRecord*> ancestry);

	virtual Organism* clone(Position position, World& world) = 0;
	string toString();
	virtual vector<Result*> move() = 0;
	vector<Result*> action();
	vector<Result*> consequences(Organism* attackingOrganism);
	bool ifReproduce();
	vector<Position> getVectorOfFreePositionsAround();

};