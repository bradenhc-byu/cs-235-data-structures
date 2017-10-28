#pragma once
#include "Node.h"
#include "PolynomialListInterface.h"
using namespace std;

class PolynomialList : public PolynomialListInterface
{
protected:
	Node* head; //points to the head of the list
	Node* current; //points to the current Node being refernced in the list
public:
	PolynomialList();
	~PolynomialList();
	void insert(string term);
	void clear();
	string at(int index);
	int size();
	string printList();
	Node* getHead();
};