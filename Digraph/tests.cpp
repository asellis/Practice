// Test functions for the Digraph class

#include "Digraph.hpp"
#include "tests.hpp"
#include <iostream>
#include <algorithm>


void fillDigraph(Digraph<int, int> &graph)
{
	/*
	Turns the graph into the following
	\ down
	/ up
	- straight

					Distance to end
	1 -	2 - 4 		shortest
	  \       \
        3 - 5 - 7	2nd shortest
          \   /
            6		3rd shortest
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

void getVertecies(bool print)
{
	if(print)
		std::cout << "getVertecies";
	bool pass = true;
	Digraph<int, int> a = Digraph<int, int>();
	fillDigraph(a);
	std::vector<int> v = a.vertices();
	pass = pass && bool(v.size()==7) && bool(std::find(v.begin(), v.end(), 4) != v.end());

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void getEdges(bool print)
{
	if(print)
		std::cout << "getEdges";
	bool pass = true;
	Digraph<int, int> a = Digraph<int, int>();
	fillDigraph(a);
	std::vector<std::pair<int, int>> v = a.edges();
	pass = pass && bool(v.size()==8) && bool(std::find(v.begin(), v.end(), std::pair<int, int>(4, 7)) != v.end());

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void getEdge(bool print)
{
	if(print)
		std::cout << "getEdge";
	bool pass = true;
	Digraph<int, int> a = Digraph<int, int>();
	fillDigraph(a);
	std::vector<std::pair<int, int>> v = a.edges(1);
	pass = pass && bool(v.size()==2) && bool(std::find(v.begin(), v.end(), std::pair<int, int>(1, 3)) != v.end());

	if(print && pass)
		std::cout << "\t\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\t\tFailed" << std::endl;
}

void getVertexInfo(bool print)
{
	if(print)
		std::cout << "getVertexInfo";
	bool pass = true;
	Digraph<int, int> a = Digraph<int, int>();
	fillDigraph(a);
	pass = pass && bool(a.vertexInfo(1) == 1) && bool(a.vertexInfo(2) == 2);

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

void getEdgeInfo(bool print)
{
	if(print)
		std::cout << "getEdgeInfo";
	bool pass = true;
	Digraph<int, int> a = Digraph<int, int>();
	fillDigraph(a);
	pass = pass && bool(a.edgeInfo(1,2) == 1) && bool(a.edgeInfo(6,7) == 8);

	if(print && pass)
		std::cout << "\t\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\t\tFailed" << std::endl;
}

double convertEdgeInfo(int eInfo)
{
	return static_cast<double>(eInfo);
}

void shortestDistance(bool print)
{
	if(print)
		std::cout << "shortestDistance";
	bool pass = true;
	Digraph<int, int> a = Digraph<int, int>();
	fillDigraph(a);
	std::map<int, int> v = a.findShortestPaths(1, convertEdgeInfo);
	pass = pass && bool(v[7] == 4) && bool(v[6] == 3) && bool(v[1] = 1);

	if(print && pass)
		std::cout << "\t\tPassed" << std::endl;
	else if(print)
		std::cout << "\t\tFailed" << std::endl;	
}