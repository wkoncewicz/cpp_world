#include "World.h"
#include <fstream>
#include <algorithm>
#include <iostream>

Organism* World::getOrganismFromPosition(int x, int y)
{	
	for (Organism* org : organisms)
		if (org->getPosition().getX() == x && org->getPosition().getY() == y)
			return org;
	return nullptr;
}

bool World::isPositionOnWorld(int x, int y)
{
	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}

bool World::isPositionFree(Position position) {
	if (this->getOrganismFromPosition(position.getX(), position.getY())){
		return false;
	}
	return true;
}

vector<Position> World::getVectorOfFreePositionsAround(Position position)
{	
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for(int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) && 
				isPositionOnWorld(pos_x + x, pos_y + y)) {
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	auto iter = remove_if(result.begin(), result.end(),
		[this](Position pos) {return !isPositionFree(pos); });
	result.erase(iter, result.end());

	return result;
}

vector<Position> World::getVectorOfPositionsAround(Position position){
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for(int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) && 
				isPositionOnWorld(pos_x + x, pos_y + y)) {
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	return result;
}

World::World(int worldX, int worldY)
{
	setWorldX(worldX);
	setWorldY(worldY);
}

int World::getWorldX()
{
	return this->worldX;
}

void World::setWorldX(int worldX)
{
	this->worldX = worldX;
}

int World::getWorldY()
{
	return this->worldY;
}

void World::setWorldY(int worldY)
{
	this->worldY = worldY;
}

int World::getTurn()
{
	return this->turn;
}

void World::addOrganism(Organism* organism)
{
	this->organisms.push_back(organism);
}

vector<Organism*> World::filter(vector<Organism*> organisms_to_modify, Organism* organism_to_filter){
	vector<Organism*> new_organisms;
	for (Organism* org : organisms_to_modify){
		if (org != organism_to_filter){
			new_organisms.push_back(org);
		}
	}
	return new_organisms;
}

void World::makeTurn()
{
	vector<Result*> results;
	vector<Result*> new_results;
	vector<Organism*> new_organisms;
	
	for (auto& org : organisms){
		if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
			new_results = org->move();
			results.insert(results.end(), new_results.begin(), new_results.end());
			if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
				new_results = org->action();
				results.insert(results.end(), new_results.begin(), new_results.end());
			}
		}
	}
	for (Result* r : results){
		makeMove(r);
	}

	for (auto& org : organisms){
		if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
			new_organisms.push_back(org);
		}
	}
	this->organisms = new_organisms;

	for (auto& org : organisms){
		org->setLiveLength(org->getLiveLength() - 1);
		org->setPower(org->getPower() + 1);
		if (org->getLiveLength() < 1){
			cout << org->getSpecies() << "died of age at" << org->getPosition().toString();
		}
	}
	
	new_organisms.clear();
	for (auto& org : organisms){
		if (org->getLiveLength() > 0){
			new_organisms.push_back(org);
		}
	}
	this->organisms = new_organisms;

	new_organisms.clear();
	for (auto& org : newOrganisms){
		if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
			new_organisms.push_back(org);
		}
	}

	organisms.insert(organisms.end(), newOrganisms.begin(), newOrganisms.end());
	std::sort(organisms.begin(), organisms.end(), [](const Organism& a, const Organism& b) {
    	return a.initiative > b.initiative;
	});
	newOrganisms.clear();

	turn++;
}

void World::makeMove(Result* result){
	int action = result->getAction();
	if (action == 0){
		this->newOrganisms.push_back((result->getOrganism()));
	} else if (action == 1){
		result->getOrganism()->setPower(result->getValue());
	} else if (action == 2){
		result->getOrganism()->setPosition(result->getPosition());
	} else if (action == 3){
		Organism* organism = result->getOrganism();
		vector<Organism*> filtered = filter(newOrganisms, organism);
		this->newOrganisms = filtered;
		filtered = filter(organisms, organism);
		this->organisms = filtered;
		delete organism;
	}
	delete result;
}

void World::writeWorld(string fileName)
{
	fstream my_file;
	my_file.open(fileName, ios::out | ios::binary);
	if (my_file.is_open()) {
		my_file.write((char*)&this->worldX, sizeof(int));
		my_file.write((char*)&this->worldY, sizeof(int));
		my_file.write((char*)&this->turn, sizeof(int));
		int orgs_size = this->organisms.size();
		my_file.write((char*)&orgs_size, sizeof(int));
		for (int i = 0; i < orgs_size; i++) {
			int data;
			data = this->organisms[i]->getPower();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i]->getPosition().getX();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i]->getPosition().getY();
			my_file.write((char*)&data, sizeof(int));
			string s_data = this->organisms[i]->getSpecies();
			int s_size = s_data.size();
			my_file.write((char*)&s_size, sizeof(int));
			my_file.write(s_data.data(), s_data.size());
		}
		my_file.close();
	}
}

void World::readWorld(string fileName)
{
	fstream my_file;
	my_file.open(fileName, ios::in | ios::binary);
	if (my_file.is_open()) {
		int result;
		my_file.read((char*)&result, sizeof(int));
		this->worldX = (int)result;
		my_file.read((char*)&result, sizeof(int));
		this->worldY = (int)result;
		my_file.read((char*)&result, sizeof(int));
		this->turn = (int)result;
		my_file.read((char*)&result, sizeof(int));
		int orgs_size = (int)result;
		vector<Organism> new_organisms;
		for (int i = 0; i < orgs_size; i++) {
			int power;
			my_file.read((char*)&result, sizeof(int));
			power = (int)result;

			int pos_x;
			my_file.read((char*)&result, sizeof(int));
			pos_x = (int)result;
			int pos_y;
			my_file.read((char*)&result, sizeof(int));
			pos_y = (int)result;
			Position pos{ pos_x, pos_y };
			
			int s_size;
			my_file.read((char*)&result, sizeof(int));
			s_size = (int)result;

			string species;
			species.resize(s_size);
			my_file.read((char*)&species[0], s_size);
			
			Organism org(power, pos);
			org.setSpecies(species);
			new_organisms.push_back(org);
		}
		this->organisms = new_organisms;
		my_file.close();
	}
}

string World::toString()
{
	string result = "\nturn: " + to_string(getTurn()) + "\n";
	string spec;

	for (int wY = 0; wY < getWorldY(); ++wY) {
		for (int wX = 0; wX < getWorldX(); ++wX) {
			Organism* org = getOrganismFromPosition(wX, wY);
			spec = org->getSpecies();
			if (spec != "")
				result += spec;
			else
				result += separator;
		};
		result += "\n";
	}
	return result;
}