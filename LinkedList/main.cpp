/*
This file is for testing the Linked List implementation.  Declaration and
definition are both in the header file to avoid template issues.
*/

#include <iostream>
#include "LinkedList.hpp"
#include "tests.hpp"

void testAll(bool print = false)
{
	emptyInitializer(print);
	addToStart(print);
	addToEnd(print);
	first(print);
}

int main()
{
	testAll(true);


	return 0;
}