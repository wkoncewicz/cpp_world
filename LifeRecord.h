#pragma once

class LifeRecord {
private:
	int birthTurn;
	int deathTurn;

public:
	LifeRecord(int birthTurn, int deathTurn);
	LifeRecord() : birthTurn(0), deathTurn(-1) {}

	int getBirthTurn();
	void setBirthTurn(int birthTurn);
	int getDeathTurn();
	void setDeathTurn(int deathTurn);
};