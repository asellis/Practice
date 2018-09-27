// Test functions for the Digraph class
// When print is set to true the test will print
// if it passed or failed
#ifndef TESTS_HPP
#define TESTS_HPP
#include "Digraph.hpp"

// Auto adds stuff to a digraph of ints
void fillDigraph(Digraph<int, int> graph);

// Tests empty construction
void emptyConstructor(bool print=false);

// Tests adding a vertex
void addVertex(bool print = false);

// Tests adding an edge
void addEdge(bool print = false);




#endif