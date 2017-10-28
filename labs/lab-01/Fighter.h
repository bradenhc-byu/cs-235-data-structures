#include "FighterInterface.h"
using namespace std;

//Braden Hitchcock v1.0 8/31/2012

class Fighter : public FighterInterface
{
public:
	Fighter();
	Fighter(string name, int maxHP, int strength, int speed, int magic);
	~Fighter(void);
	virtual string getName();
	virtual int getMaximumHP();
	virtual int getCurrentHP();
	virtual int getStrength();
	virtual int getSpeed();
	virtual int getMagic();
	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();
	virtual bool isSimplified();
protected:
	string name;
	int strength;
	int speed;
	int magic;
	int HP;
	int maxHP;

};



string Fighter::getName(){return name;}

int Fighter::getMaximumHP(){return maxHP;}

int Fighter::getCurrentHP(){return HP;}

int Fighter::getStrength(){return strength;}

int Fighter::getSpeed(){return speed;}

int Fighter::getMagic(){return magic;}

int Fighter::getDamage(){return maxHP-HP;}