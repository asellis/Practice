// Contains Tests to run on the LinkedList class
#include "LinkedList.hpp"
#include "tests.hpp"
#include <assert.h>
#include <iostream>

void emptyInitializer(bool print)
{
	if(print)
		std::cout << "emptyInitializer";

	LinkedList<int>();
	LinkedList<int> a = LinkedList<int>();

	if(print)
		std::cout << "\tPassed" << std::endl;
}

void addToStart(bool print)
{
	// will check value when testing first
	if(print)
		std::cout << "addToStart";
	bool pass = true;

	LinkedList<int> a = LinkedList<int>();
	a.addToStart(1);
	a.addToStart(2);

	LinkedList<char> b = LinkedList<char>();
	b.addToStart('a');
	b.addToStart('b');

	if(print && pass)
		std::cout << "\t\tPassed" << std::endl;
	else
		std::cout << "\t\tFailed" << std::endl;
}

void addToEnd(bool print)
{
	// will check value when testing end
	if(print)
		std::cout << "addToEnd";
	bool pass = true;

	LinkedList<int> a = LinkedList<int>();
	a.addToEnd(1);
	a.addToEnd(2);
	a.addToStart(0);

	if(print && pass)
		std::cout << "\t\tPassed" << std::endl;
	else
		std::cout << "\t\tFailed" << std::endl;
}

void first(bool print)
{
	if(print)
		std::cout << "first";
	bool pass = true;

	LinkedList<int> a = LinkedList<int>();

	try
	{
		a.first();
		pass = false;
	}
	catch(...)
	{
		pass = pass && true;
	}

	a.addToStart(1);
	pass = pass && bool(a.first() == 1);
	a.addToStart(0);
	pass = pass && bool(a.first() == 0);

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else
		std::cout << "\t\t\tFailed" << std::endl;
}