#pragma once

#include <vector>
#include <ctime>
#include "Organism.h"
#include "Dandelion.h"
#include "Grass.h"
#include "Sheep.h"
#include "Toadstool.h"
#include "Wolf.h"
#include "Result.h"

using namespace std;

class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	vector<Organism*> organisms;
	char separator = '.';

	bool isPositionOnWorld(int x, int y);
	bool isPositionFree(Position position);

public:
	Organism* getOrganismFromPosition(int x, int y);
	World(int worldX, int worldY);
	World() : World(6, 6) {};
	~World();

	int getWorldX();
	void setWorldX(int worldX);
	int getWorldY();
	void setWorldY(int worldY);

	int getTurn();
	
	void addOrganism(Organism* organism);
	vector<Position> getVectorOfFreePositionsAround(Position position);
	vector<Position> getVectorOfPositionsAround(Position position);
	vector<Organism*> filter(vector<Organism*> organisms_to_modify, Organism* organism_to_filter);
	void makeTurn();
	void makeMove(Result* result);

	void writeWorld(string fileName);
	void readWorld(string fileName);
	
	string toString();

};