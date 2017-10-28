#include "Fighter.h"
#include <cmath>
#pragma once

class Robot : public Fighter
{
public:
	Robot();
	Robot(string name, int maxHP, int strength, int speed, int magic);
	~Robot();
	int getDamage(); //equals strength plus damage from special ability
	void reset(); //restores energy and zeros bonus damage
	bool useAbility();
protected:
	int energy;
	int bonusDamage;
	int maxEnergy;
};