//YOU MAY NOT MODIFY THIS DOCUMENT
#pragma once
#include <string>

using namespace std;

class PolynomialListInterface
{

public:
	/*
	 * You must create a Node class that will hold each polynomial segment and will be used to create the
	 * links in your PolynomialList.
	 * Your Node will likely have 3 private variables in addition to a Node * next you may have.
	 * These 3 variables will be for the Coefficient, the Variable, and the Exponent respectively.
	 * i.e. 2x^7
	 * 		Coefficient = 2
	 * 		Variable = x
	 * 		Exponent = 7
	 */
	PolynomialListInterface(void){}
	virtual ~PolynomialListInterface(void){}
	
	/*
		insert

		A node with the given term should be inserted at the appropriate spot in the list.
		A term can be accepted only with Coefficient value > 0, and exponent value non-negative.
		If the term is invalid, do not add it to the list.
		i.e. If the given term segment is 3x^5 and your list contains 2x^8, x^4, 11x^2
			the node should be added after 2x^8. Your updated list should look like 2x^8, 3x^5, x^4, 11x^2.

	 */
	virtual void insert(string term) = 0;

	/*
		clear

		Remove all nodes from the list.
	 */
	virtual void clear() = 0;

	/*
		at

		Returns the polynomial of the node at the given index. The list begins at
		index 0.

		If the given index is out of range of the list, return "invalid";
	 */
	virtual string at(int index) = 0;

	/*
		size

		Returns the number of nodes in the list.
	 */
	virtual int size() = 0;

	/*
	 * This function should string together all of the nodes and print out the entire polynomial separated with '+' signs.
	 * If an exponent of 0 exists however, you should print only the Coefficient.
	 * i.e. list of Nodes = (2x^4)->(4x^2)->(3x^1)->(11x^0)
	 * 		printList() = return "2 x ^ 4 + 4 x ^ 2 + 3 x ^ 1 + 11 x";
	 */
	virtual string printList() = 0;

};
