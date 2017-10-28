#include "PolynomialManager.h"
#include <sstream>
#include <iostream>


PolynomialManager::PolynomialManager()
{

}

PolynomialManager::~PolynomialManager()
{
	clearListOne();
	clearListTwo();
}

PolynomialListInterface* PolynomialManager::addLists()
{
	PolynomialListInterface* addedList = NULL;
	Node* currentOne = listOne.getHead();
	Node* currentTwo = listTwo.getHead();
	int index = 0;
	while(currentOne != NULL){
		addedList->insert(listOne.at(index));
		index++;
		currentOne = currentOne->next;
	}
	index = 0;
	while(currentTwo != NULL){
		addedList->insert(listTwo.at(index));
		index++;
		currentTwo = currentTwo->next;
	}
	addedList->printList();
	return addedList;
	//int indexOne = 0;
	//int indexTwo = 0;
	//PolynomialListInterface* addedList = NULL;
	//Node* currentOne = listOne.getHead();
	//Node* currentTwo = listTwo.getHead();
	//if(currentOne == NULL && currentTwo == NULL)
	//	return addedList;
	//while(currentOne != NULL || currentTwo != NULL){ //while the index isn't larger than than either list
	//	if(currentOne == NULL){
	//			addedList->insert(listTwo.at(indexTwo));
	//			currentTwo = currentTwo->next;
	//			indexTwo++;
	//	}
	//	else if(currentTwo == NULL){
	//			addedList->insert(listOne.at(indexOne));
	//			currentOne = currentOne->next;
	//			indexOne++;
	//	}
	//	else if(currentOne->exponent == currentTwo->exponent){
	//		int add = currentOne->coefficient + currentTwo->coefficient;
	//		string addedString = "";
	//		ostringstream convert;
	//		convert << add;
	//		addedString += convert.str();
	//		addedString += " ";
	//		addedString += currentOne->variable;
	//		addedString += " ";
	//		addedString += "^";
	//		ostringstream exconvert;
	//		string ex = "";
	//		exconvert << currentOne->exponent;
	//		ex = exconvert.str();
	//		addedString += ex;
	//		addedList->insert(addedString);
	//		indexOne++;
	//		indexTwo++;
	//		currentOne = currentOne->next;
	//		currentTwo = currentTwo->next;
	//	}
	//	else if(currentOne->exponent < currentTwo->exponent){
	//		addedList->insert(listTwo.at(indexTwo));
	//		indexTwo++;
	//		currentTwo = currentTwo->next;
	//	}
	//	else if(currentTwo->exponent < currentOne->exponent){
	//		addedList->insert(listOne.at(indexOne));
	//		indexOne++;
	//		currentOne = currentOne->next;
	//	}
	//}
	//cout << addedList << endl;
	//return addedList;
}

PolynomialListInterface* PolynomialManager::subtractLists()
{
	int indexOne = 0;
	int indexTwo = 0;
	PolynomialListInterface* subtractedList = NULL;
	Node* currentOne = listOne.getHead();
	Node* currentTwo = listTwo.getHead();
	if(currentOne == NULL && currentTwo == NULL)
		return subtractedList;
	while(currentOne != NULL || currentTwo != NULL){ //while the index isn't larger than than either list
		if(currentOne == NULL){
				subtractedList->insert(listTwo.at(indexTwo));
				currentTwo = currentTwo->next;
				indexTwo++;
		}
		else if(currentTwo == NULL){
				subtractedList->insert(listOne.at(indexOne));
				currentOne = currentOne->next;
				indexOne++;
		}
		else if(currentOne->exponent == currentTwo->exponent){
			int add = currentTwo->coefficient - currentOne->coefficient;
			string addedString = "";
			ostringstream convert;
			convert << add;
			addedString += convert.str();
			addedString += " ";
			addedString += currentOne->variable;
			addedString += " ";
			addedString += "^";
			addedString += currentOne->exponent;
			subtractedList->insert(addedString);
			indexOne++;
			indexTwo++;
			currentOne = currentOne->next;
			currentTwo = currentTwo->next;
		}
		else if(currentOne->exponent < currentTwo->exponent){
			subtractedList->insert(listTwo.at(indexTwo));
			indexTwo++;
			currentTwo = currentTwo->next;
		}
		else if(currentTwo->exponent < currentOne->exponent){
			subtractedList->insert(listOne.at(indexOne));
			indexOne++;
			currentOne = currentOne->next;
		}
	}
	return subtractedList;
}

void PolynomialManager::fillListOne(string term)
{
	istringstream checker(term);
	char c;
	checker >> c;
	if(!isdigit(c)){ //check to see if coefficient is an implied 1
		string modified = "1 ";
		modified += term; //add a 1 to the term
		listOne.insert(modified);
	}
	else
		listOne.insert(term);
}

void PolynomialManager::fillListTwo(string term)
{
	istringstream checker(term);
	char c;
	checker >> c;
	if(!isdigit(c)){ //check to see if coefficient is an implied 1
		string modified = "1 ";
		modified += term; //add a 1 to the term
		listTwo.insert(modified);
	}
	else
		listTwo.insert(term);
}

void PolynomialManager::clearListOne()
{
	listOne.clear();
}

void PolynomialManager:: clearListTwo()
{
	listTwo.clear();
}

PolynomialListInterface* PolynomialManager::getListOne()
{
	PolynomialList* list = NULL;
	list = &listOne;
	return list;
}

PolynomialListInterface* PolynomialManager::getListTwo()
{
	PolynomialList* list = NULL;
	list = &listTwo;
	return list;
}