#include "Fighter.h"
#pragma once
using namespace std;

//Braden Hitchcock v1.0 8/31/2012

Fighter::Fighter() {}

Fighter::Fighter(string name, int maxHP, int strength, int speed, int magic) 
{
	name = name;
	maxHP = maxHP;
	strength = strength;
	speed = speed;
	magic = magic;
	HP = maxHP;
}

Fighter::~Fighter(void) {}

void Fighter::takeDamage(int damage)
{
	int damageTaken = damage-(speed/4);
	if(damageTaken<1)
		damageTaken = 1;
	HP-=damageTaken;
}

void Fighter::reset()
{
	HP = maxHP;
}

void Fighter::regenerate()
{
	if(strength < 6)
		HP++;
	else
		HP += (1/6)*strength;
	if(HP > maxHP)
		HP = maxHP;
}

bool Fighter::useAbility()
{
	return false;
	//implemented in the sub classes Archer, Robot, and Cleric, won't run here because of virtual declaration
}

bool Fighter::isSimplified()
{
	return false;
}