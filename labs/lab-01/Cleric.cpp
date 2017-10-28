#include "Cleric.h"


Cleric::Cleric(string name, int maxHP, int strength, int speed, int magic) :
	Fighter(name,maxHP,strength,speed,magic)
{
	maxMana = 5*magic;
	mana = maxMana;
}

Cleric::~Cleric() {}

int Cleric::getDamage()
{
	return magic;
}

void Cleric::reset()
{
	Fighter::reset();
	mana = maxMana;
}

void Cleric::regenerate()
{
	Fighter::regenerate();
	int addMana = (1/5)*magic;
	if(addMana < 1)
		addMana = 1;
	mana += addMana;
	if(mana > maxMana)
		mana = maxMana;
}

bool Cleric::useAbility() //Healing Light
{
	if(mana >= CLERIC_ABILITY_COST){
		int health = (1/3)*magic;
		if(health < 1)
			health = 1;
		HP+=health;
		if(HP>maxHP)
			HP = maxHP;
		mana-=CLERIC_ABILITY_COST;
		return true;
	}
	else
		return false;
}