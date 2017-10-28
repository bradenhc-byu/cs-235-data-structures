#include "Fighter.h"
#pragma once

class Archer : public Fighter
{
public:
	Archer(string name, int maxHP, int strength, int speed, int magic);
	~Archer();
	int getDamage(); //equal to the Archer's speed
	void reset(); //resets Archer's speed and HP
	bool useAbility();
protected:
	int startSpeed;
};