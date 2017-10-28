#include "PolynomialList.h"
#include "PolynomialManager.h"
#include <iostream>

int main()
{
	cout << "Starting Self Test Driver" << endl;
	PolynomialList listOne;
	string term1 = "2 x ^ 5";
	string term2 = "3 x ^ 4";
	string term3 = "2 x ^ 7";
	string term4 = "5 x ^ 6";
	string term5 = "2 x ^ 2";
	string term6 = "2 y ^ 8";
	string term11 = "5 x ^ 5";
	listOne.insert(term1);
	listOne.insert(term2);
	listOne.insert(term3);
	listOne.insert(term4);
	listOne.insert(term5);
	listOne.insert(term6);
	listOne.insert(term11);
	cout << listOne.at(0) << endl;
	listOne.printList();
	PolynomialManager manager;
	manager.fillListOne(term1);
	manager.fillListOne(term2);
	manager.fillListOne(term3);
	manager.fillListOne(term4);
	manager.fillListOne(term5);
	string term7 = "8 x ^ 2";
	string term8 = "1 x ^ 3";
	string term9 = "4 x ^ 7";
	string term10 = "2 x ^ 6";
	string term12 = "3 x ^ 0";
	manager.fillListTwo(term7);
	manager.fillListTwo(term8);
	manager.fillListTwo(term9);
	manager.fillListTwo(term10);
	manager.fillListTwo(term12);
	manager.getListTwo()->printList();
	//manager.addLists();
	system("pause");
	return 0;
}