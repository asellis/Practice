// Runs tests on the Digraph class

#include <iostream>
#include "tests.hpp"

void testAll(bool print = false)
{
	// Runs all the tests in tests.hpp
	emptyConstructor(print);
	addVertex(print);
	addEdge(print);
}

int main()
{
	// Runs testAll which will test Digraph class
	testAll(true);

	return 0;
}