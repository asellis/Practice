// Test functions for the Digraph class

#include "Digraph.hpp"
#include "tests.hpp"
#include <iostream>


void fillDigraph(Digraph<int, int> graph)
{
	/*
	Turns the graph into the following
	\ down
	/ up
	- straight

	1 -	2 - 4 
	  \       \
        3 - 5 - 7
          \   /
            6
	*/

	// Adding vertecies
	// Each vertex will have its vertex number as its info
	graph.addVertex(1,1);
	graph.addVertex(2,2);
	graph.addVertex(3,3);
	graph.addVertex(4,4);
	graph.addVertex(5,5);
	graph.addVertex(6,6);
	graph.addVertex(7,7);

	// Adding edges
	// edge info will be the count in which they are added
	graph.addEdge(1, 2, 1);
	graph.addEdge(1, 3, 2);
	graph.addEdge(2, 4, 3);
	graph.addEdge(3, 5, 4);
	graph.addEdge(3, 6, 5);
	graph.addEdge(4, 7, 6);
	graph.addEdge(5, 7, 7);
	graph.addEdge(6, 7, 8);
}

void emptyConstructor(bool print)
{
	if(print)
		std::cout << "emptyConstructor";
	bool pass = true;
	try
	{
		Digraph<int, int> a = Digraph<int, int>();
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

void addVertex(bool print)
{
	if(print)
		std::cout << "addVertex";
	bool pass = true;
	try
	{
		Digraph<int, int> a = Digraph<int, int>();
		a.addVertex(1,1);
		a.addVertex(2,2);
	}
	catch(...)
	{
		pass = false;
	}

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void addEdge(bool print)
{
	if(print)
		std::cout << "addEdge";
	bool pass = true;
	try
	{
		Digraph<int, int> a = Digraph<int, int>();
		a.addVertex(1,1);
		a.addVertex(2,2);
		a.addEdge(1,2,1);
	}
	catch(...)
	{
		pass = false;
	}

	if(print && pass)
		std::cout << "\t\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\t\tFailed" << std::endl;
}