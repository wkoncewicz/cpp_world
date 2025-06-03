#pragma once
#include "Position.h"

using namespace std;

class Organism;

class Result {
private:
	int action;
	Position position;
    int value;
    Organism* organism;

public:
	Result(int action, Position position, int value, Organism* organism);
	Result() : action(0), position(0, 0), value(0), organism(nullptr) {}

	int getAction();
    void setAction(int action);
    Position getPosition();
    void setPosition(Position position);
    int getValue();
    void setValue(int value);
    Organism* getOrganism();
    void setOrganism(Organism* organism);
};