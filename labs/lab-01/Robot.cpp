#include "Robot.h"

Robot::Robot() {}

Robot::Robot(string name, int maxHP, int strength, int speed, int magic) :
	Fighter(name,maxHP,strength,speed,magic)
{
	energy = 2*magic;
	maxEnergy = energy;
	bonusDamage = 0;
}

Robot::~Robot() {}

int Robot::getDamage()
{
	int damage = strength+bonusDamage;
	bonusDamage = 0;
	return damage;
}

void Robot::reset()
{
	Fighter::reset();
	energy = maxEnergy;
	bonusDamage = 0;
}

bool Robot::useAbility() //Shockwave Punch
{
	if(energy >= ROBOT_ABILITY_COST){
		bonusDamage = strength*pow((double)(energy)/((double)(maxEnergy)),4);
		energy -= ROBOT_ABILITY_COST;
		return true;
	}
	else
		return false;
}