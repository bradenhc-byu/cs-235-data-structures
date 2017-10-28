#include "PolynomialList.h"
#include <iostream>
#include <string>
#include <sstream>

PolynomialList::PolynomialList()
{
	head = NULL;
	current = NULL;
}

PolynomialList::~PolynomialList()
{
	clear();
}

void PolynomialList::insert(string term)
{
	istringstream tokens(term);
	int coefficient;
	char variable;
	int exponent;
	char carrot;
	tokens >> coefficient >> variable >> carrot >> exponent;
	if(carrot != '^' || variable != 'x' || coefficient < 0 || exponent < 0){ //if entry is invalid, return
		cout << "ERROR: Invalid Entry" << endl;
		return;
	}
	Node* poly = new Node(coefficient, variable, exponent, NULL); //create new poly node
	current = head;
	if(head == NULL){ //if it is the first poly in the list, add it to the head
		head = poly;
		return;
	}
	if(poly->exponent > head->exponent){ //if the poly exponent is greater than the head exponent, insert at head
			poly->next = head;
			head = poly;
			return;
	}
	while(current->next != NULL){
		if(poly->exponent == current->exponent){ //if both exponents are equal
			current->coefficient = poly->coefficient + current->coefficient; //add coefficients
			delete poly; //delete the new polynomial that is no longer needed to free space
			return;
		}
		if(poly->exponent < current->exponent && poly->exponent > current->next->exponent){ //if the new exponent is < the new exponent and > the next node's exponent, insert
			poly->next = current->next;
			current->next = poly;
			return;
		}
	current = current->next;
	}
	current->next = poly; //if the poly has not been inserted, add to end of list
}

void PolynomialList::clear()
{
	current = head;
	while(current != NULL){
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
		delete nextNode;
	}
}

string PolynomialList::at(int index)
{
	string poly = "";
	current = head;
	int count = 0;
	while(current != NULL){
		if(count == index){
			ostringstream convert;
			convert << current->coefficient;
			string co = "";
			co = convert.str();
			poly += co;
			poly += " ";
			poly += current->variable;
			poly += " ";
			poly += "^";
			poly += " ";
			ostringstream exconvert;
			exconvert << current->exponent;
			string ex = "";
			ex = exconvert.str();
			poly += ex;

		}
		count++;
		current = current->next;
	}
	if(poly == "")
		return "invalid";
	else
		return poly;
}

int PolynomialList::size()
{
	int size = 0;
	current = head;
	while(current != NULL){
		size++;
		current = current->next;
	}
	return size;
}

string PolynomialList::printList()
{
	current = head;
	string print = "";
	int index = 0;
	bool first = true;
	while(index<size()){
		if(first){ //if it is the first node, add info with no space before
			istringstream checker(at(index));
			string s;
			checker >> s;
			if(s == "1" && current->exponent != 0){ //checking to see if the coefficient is 1, if it is remove the 1 
				string modified = at(index).substr(at(index).find("x"));
				print += modified;
			}
			else if(current->exponent == 0){
				ostringstream convert;
				string modified;
				convert << current->exponent;
				modified = convert.str();
				print += modified;
			}
			else{
			print += at(index);
			}
			first = false;
		}
		else{ //if is is not the first node, add info with space and plus sign before
			istringstream checker(at(index));
			string s;
			checker >> s;
			if(s == "1" && current->exponent != 0){ //checking to see if the coefficient is 1, if it is remove it
				string modified = at(index).substr(at(index).find("x"));
				print += " ";
				print += "+";
				print += " ";
				print += modified;
			} 
			else if(current->exponent == 0){
				ostringstream convert;
				string modified;
				convert << current->exponent;
				modified = convert.str();
				print += " ";
				print += "+";
				print += " ";
				print += modified;
			}
			else{
				print += " ";
				print += "+";
				print += " ";
				print += at(index);
			}
		}
		index++; //increment to next node
		current = current->next;
	}
	cout << print << endl; //display the list
	return print;
}

Node* PolynomialList::getHead()
{
	return head; //returns a node pointer to be used in PolynomialManager
}