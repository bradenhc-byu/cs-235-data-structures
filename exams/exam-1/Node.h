#ifndef NODE_H_
#define NODE_H_

struct Node{
	int coefficient; //coefficient of the input
	char variable; //variable of the input, should be x
	int exponent; //exponent that input is raised to
	Node* next; //creates a pointer to the next node in list
	//Constructor
	Node(int coeff, char var, int exp, Node* nextPtr) :
	coefficient(coeff), variable(var), exponent(exp), next(nextPtr) {}
};

#endif