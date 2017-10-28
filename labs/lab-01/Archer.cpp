#include "Archer.h"


Archer::Archer(string name, int maxHP, int strength, int speed, int magic) : 
	Fighter(name,maxHP,strength,speed,magic)
{
	startSpeed = speed;
}

Archer::~Archer(void) {}

int Archer::getDamage()
{
	return speed;
}

void Archer::reset()
{
	speed = startSpeed;
	Fighter::reset();
}

bool Archer::useAbility() //Quickstep
{
	speed++;
	return true;
}