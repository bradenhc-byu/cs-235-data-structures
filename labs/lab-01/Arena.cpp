#pragma once
#include "Arena.h"
using namespace std;

//Braden Hitchcock v1.0 8/31/2012

Arena::Arena() {}
Arena::~Arena() {}

bool Arena::addFighter(string info)
{
	string s;
	string c;
	int m;
	int x;
	int y;
	int z;
	string e;
	istringstream infoStream;
	infoStream.str(info);
	infoStream >> s >> c >> m >> x >> y >> z;
	if(infoStream.fail()){
		infoStream.clear();
		return false;
	}
	if(infoStream >> e)
		return false;
	if(getFighter(s) != NULL)
		return false;
	if(c == "A" || c == "C" || c == "R" && m >= 0 && x >= 0 && y >= 0 && z >= 0){
		if(c == "A")
			fighters.push_back(new Archer(s,m,x,y,z));
		if(c == "C")
			fighters.push_back(new Cleric(s,m,x,y,z));
		if(c == "R")
			fighters.push_back(new Robot(s,m,x,y,z));
		return true;
	}
	else
		return false;
}

bool Arena::removeFighter(string name)
{
	if(getFighter(name) == NULL)
		return false;
	for(int n=0;n<getSize();n++){
		if((fighters.at(n))->getName()==name){
			fighters.erase(fighters.begin()+n);
			return true;
		}
	}
	return false;
}

FighterInterface* Arena::getFighter(string name)
{
	for(int n=0;n<fighters.size();n++){
		if(fighters[n]->getName()==name)
			return (fighters[n]);
	}
	return NULL;
}

int Arena::getSize()
{
	return fighters.size();
}

vector<FighterInterface*> Arena::getFighters()
{
	return fighters;
}