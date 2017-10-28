#include "Factory.h"
#include "Josephus.h"
//You may add #include statments here

/*
	You will MODIFY THIS DOCUMENT.
*/
//=======================================================================================
/*
	getGame()

	Creates and returns an object whose class extends JosephusInterface.
	This should be an object of a class you have created.

	Example: If you made a class called "Circle", you might say, "return new Circle();".
*/
JosephusInterface * Factory::getGame()
{
	return new Josephus();//Modify this line
}
