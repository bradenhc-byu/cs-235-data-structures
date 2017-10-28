#pragma once
#include "JosephusInterface.h"

class Josephus : public JosephusInterface
{
public:
	Josephus(void);
	~Josephus(void);
	vector<string> getNames();
	vector<string> playGame(int n, int m);
	int reportSafeIndex(int n, int m);
	void generateNames();
private:
	vector<string> names;
};