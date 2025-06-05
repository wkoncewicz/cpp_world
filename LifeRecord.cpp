#include "LifeRecord.h"

LifeRecord::LifeRecord(int birthTurn, int deathTurn){
    setBirthTurn(birthTurn);
    setDeathTurn(deathTurn);
}

int LifeRecord::getBirthTurn(){
    return this->birthTurn;
}

void LifeRecord::setBirthTurn(int birthTurn){
    this->birthTurn = birthTurn;
}

int LifeRecord::getDeathTurn(){
    return this->deathTurn;
}

void LifeRecord::setDeathTurn(int deathTurn){
    this->deathTurn = deathTurn;
}