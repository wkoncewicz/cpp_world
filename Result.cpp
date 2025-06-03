#include "Result.h"

Result::Result(int action, Position position, int value, Organism* organism)
{
	setAction(action);
	setPosition(position);
    setValue(value);
    setOrganism(organism);
}

int Result::getAction()
{
	return this->action;
}

void Result::setAction(int action)
{
	this->action = action;
}

Position Result::getPosition()
{
	return this->position;
}

void Result::setPosition(Position position)
{
	this->position = position;
}

int Result::getValue()
{
	return this->value;
}

void Result::setValue(int value)
{
	this->value = value;
}

Organism* Result::getOrganism()
{
	return this->organism;
}

void Result::setOrganism(Organism* organism)
{
	this->organism = organism;
}