#include "Fighter.h"
#pragma once

class Cleric : public Fighter
{
public:
	Cleric(string name, int maxHP, int strength, int speed, int magic);
	~Cleric();
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
protected:
	int maxMana;
	int mana;
};