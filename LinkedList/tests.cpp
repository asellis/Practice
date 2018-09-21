// Contains Tests to run on the LinkedList class
#include "LinkedList.hpp"
#include "tests.hpp"
#include <assert.h>
#include <iostream>

void emptyConstructor(bool print)
{
	if(print)
		std::cout << "emptyConstructor";

	LinkedList<int>();
	LinkedList<int> a = LinkedList<int>();

	if(print)
		std::cout << "\tPassed" << std::endl;
}

void copyConstructor(bool print)
{
	if(print)
		std::cout << "copyConstructor";
	bool pass = true;
	try
	{
		LinkedList<int> a = LinkedList<int>();
		LinkedList<int> b = LinkedList<int>(a);
		a.addToStart(1);
		LinkedList<int> c = LinkedList<int>(a);
		pass = pass && bool(c.first() == 1);
		
	}
	catch(...)
	{
		pass = false;
	}

	if(print && pass)
		std::cout << "\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\tFailed" << std::endl;
	

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
	else if(print)
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
	else if(print)
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
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void end(bool print)
{
	if(print)
		std::cout << "end";
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

	a.addToEnd(1);
	pass = pass && bool(a.end() == 1);
	a.addToEnd(2);
	pass = pass && bool(a.end() == 2);

	LinkedList<int> b = LinkedList<int>();
	b.addToStart(0);
	pass = pass && bool(b.end() == 0);
	b.addToStart(-1);
	pass = pass && bool(b.end() == 0);

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void isEmpty(bool print)
{
	if(print)
		std::cout << "isEmpty";
	bool pass = true;
	LinkedList<int> a = LinkedList<int>();
	pass = pass && a.isEmpty();
	a.addToStart(0);
	pass = pass & !(a.isEmpty());

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void size(bool print)
{
	if(print)
		std::cout << "size";
	bool pass = true;
	LinkedList<int> a = LinkedList<int>();
	pass = pass && bool(a.size() == 0);
	a.addToStart(0);
	pass = pass && bool(a.size() == 1);
	a.addToEnd(1);
	pass = pass && bool(a.size() == 2);
	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;

}