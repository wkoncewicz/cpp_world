#include "World.h"
#include <fstream>
#include <algorithm>
#include <iostream>

World::~World() {
    for (Organism* org : organisms) {
		delete org->getLifeRecord();
        delete org;
    }
    organisms.clear();
}

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
	vector<Organism*> new_organisms;

	std::sort(organisms.begin(), organisms.end(), [](const Organism* a, const Organism* b) {
        if (!a && !b) return false;
        if (!a) return false;
        if (!b) return true;
        
        return a->initiative > b->initiative;
    });
	
	int counter = 0;
	for (Organism* org : organisms){
		if (org == nullptr){
			cout << "alert" << endl;
		} else {
			cout << counter++ << "-" <<org << endl;
		}
		if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
			results = org->move();
			for (Result* r : results){
				makeMove(r);
			}
			if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
				results = org->action();
				// cout <<"asdad" << endl; //Wypisuje sie
				for (Result* r : results){
					makeMove(r);
				}
			}
		}
	}

	for (auto& org : organisms){
		org->setLiveLength(org->getLiveLength() - 1);
		org->setPower(org->getPower() + 1);
		if (org->getLiveLength() < 1 && isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
			cout << org->getSpecies() << " died of age at " << org->getPosition().toString() << endl;
			makeMove(new Result(3, Position(-1, -1), 0, org));
		}
	}

	new_organisms.clear();
	for (auto& org : organisms){
		if (isPositionOnWorld(org->getPosition().getX(), org->getPosition().getY())){
			new_organisms.push_back(org);
		} else {
			delete org;
		}
	}

	this->organisms = new_organisms;
	std::sort(organisms.begin(), organisms.end(), [](const Organism* a, const Organism* b) {
        if (!a && !b) return false;
        if (!a) return false;
        if (!b) return true;
        
        return a->initiative > b->initiative;
    });
	new_organisms.clear();

	this->turn++;
}

void World::makeMove(Result* result){
	int action = result->getAction();
	if (action == 0){
		cout << "Adres przy action" << result->getOrganism() << endl;
		this->organisms.push_back((result->getOrganism()));
	} else if (action == 1){
		result->getOrganism()->setPower(result->getValue());
	} else if (action == 2){
		result->getOrganism()->setPosition(result->getPosition());
	} else if (action == 3){
		Organism* organism = result->getOrganism();
		organism->getLifeRecord()->setDeathTurn(this->turn);
		organism->setPosition(result->getPosition());
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
			data = this->organisms[i]->getInitiative();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i]->getLiveLength();
			my_file.write((char*)&data, sizeof(int));
			data = this->organisms[i]->getPowerToReproduce();
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
        vector<Organism*> new_organisms;
        for (int i = 0; i < orgs_size; i++) {
            int power;
            my_file.read((char*)&result, sizeof(int));
            power = (int)result;
            int initiative;
            my_file.read((char*)&result, sizeof(int));
            initiative = (int)result;
            int liveLength;
            my_file.read((char*)&result, sizeof(int));
            liveLength = (int)result;
            int powerToReproduce;
            my_file.read((char*)&result, sizeof(int));
            powerToReproduce = (int)result;

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

            Organism* org = nullptr; // Initialize org once

            if (species == "D"){
                org = new Dandelion(power, initiative, liveLength, powerToReproduce, pos, *this);
            } else if (species == "G"){
                org = new Grass(power, initiative, liveLength, powerToReproduce, pos, *this);
            } else if (species == "S"){
                org = new Sheep(power, initiative, liveLength, powerToReproduce, pos, *this);
            } else if (species == "T"){
                org = new Toadstool(power, initiative, liveLength, powerToReproduce, pos, *this);
            } else if (species == "W"){
                org = new Wolf(power, initiative, liveLength, powerToReproduce, pos, *this);
            }

            if (org != nullptr){
                // You likely don't need to set the species here again if it's already handled by the constructor
                // org->setSpecies(species);
                new_organisms.push_back(org);
            } else {
                cerr << "Error: Unknown species type '" << species << "' found in save file." << endl;
            }
        }
        // It's good practice to clear existing organisms to avoid memory leaks
        // if this->organisms already contains pointers to dynamically allocated objects
        for (Organism* old_org : this->organisms) {
            delete old_org;
        }
        this->organisms.clear();

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
			if (org) {
				spec = org->getSpecies();
				result += spec;
			} else {
				result += separator;
}
		};
		result += "\n";
	}
	return result;
}