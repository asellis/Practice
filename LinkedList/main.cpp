/*
This file is for testing the Linked List implementation.  Declaration and
definition are both in the header file to avoid template issues.
*/

#include <iostream>
#include "LinkedList.hpp"
#include "tests.hpp"

void testAll(bool print = false)
{
	emptyConstructor(print);
	copyConstructor(print);
	addToStart(print);
	addToEnd(print);
	removeFromStart(print);
	removeFromEnd(print);
	first(print);
	end(print);
	valueAt(print);
	addAt(print);
	removeAt(print);
	isEmpty(print);
	size(print);
}

int main()
{
	testAll(true);


	return 0;
}