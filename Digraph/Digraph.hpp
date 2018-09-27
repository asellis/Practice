/*
Contains the code for a Directed Graph
Vertecies are stored as integers
Function definitions in header file to avoid trouble using type template
All vertecies are stored in a map (vMap).  Each vertex contains information
about it's outgoing edges.
*/

#ifndef DIGRAPH_HPP
#define DIGRAPH_HPP

#include <list>
#include <map>
#include <utility>
#include <vector>

// Class Error
class DigraphException
{

};

// Structure for edges which conect vertecies together
// Contains EdgeInfo (i.e. distance to the vertex)
template <typename EdgeInfo>
struct DigraphEdge
{
	int fromVertex;
	int toVertex;
	EdgeInfo einfo;
};

// Structure for the vertex of a class
// Contains all the outgoing edges from the vertex
template <typename VertexInfo, typename EdgeInfo>
struct DigraphVertex
{
	VertexInfo vinfo;
	std::list<DigraphEdge<EdgeInfo>> edges;
};

// Class Declaration
template <typename VertexInfo, typename EdgeInfo>
class Digraph
{
public:
	// Default Contructor
	Digraph();

	// Destructor
	~Digraph();

	// Adds a vertex to the Digraph with a given vertex number and vertex info
	void addVertex(int vertex, const VertexInfo& vinfo);

	// Adds an edge from a vertex to another vertex with edge info
	// Both from and to vertecies must already exist
	void addEdge(int fromVertex, int toVertex, const EdgeInfo& einfo);

	// Returns all the vertex numbers as a vector
	std::vector<int> vertices() const;

	// Returns a vector of all the "from" and "to" vertex numbers as a pair
	std::vector<std::pair<int, int>> edges() const;

	// Returns a vector of the "from" and "to" vertex numbers for a given
	// vertex as a pair
	std::vector<std::pair<int, int>> edges(int vertex) const;

	

private:
	// A map with all the vertices
	std::map<int, DigraphVertex<VertexInfo, EdgeInfo>> vMap;

};




// Class Definition
template <typename VertexInfo, typename EdgeInfo>
Digraph<VertexInfo, EdgeInfo>::Digraph()
{
}

template <typename VertexInfo, typename EdgeInfo>
Digraph<VertexInfo, EdgeInfo>::~Digraph()
{
}

template <typename VertexInfo, typename EdgeInfo>
void Digraph<VertexInfo, EdgeInfo>::addVertex(int vertex, const VertexInfo& vinfo)
{
	// create new vertex if it is not already in map
	if(vMap.find(vertex) == vMap.end())
	{
		vMap[vertex] = DigraphVertex<VertexInfo, EdgeInfo>();
		vMap[vertex].vinfo = vinfo;
	}
	else
		throw DigraphException();
}

template <typename VertexInfo, typename EdgeInfo>
void Digraph<VertexInfo, EdgeInfo>::addEdge(int fromVertex, int toVertex, const EdgeInfo& einfo)
{
	if((vMap.find(fromVertex) != vMap.end()) && (vMap.find(toVertex) != vMap.end()))
	{
		bool edgeExists = false;
		for(const auto& edge : vMap[fromVertex].edges)
		{
			if(edge.toVertex == toVertex)
				edgeExists = true;
		}
		if(!edgeExists)
		{
			DigraphEdge<EdgeInfo> temp = DigraphEdge<EdgeInfo>();
			temp.fromVertex = fromVertex;
			temp.toVertex = toVertex;
			temp.einfo = einfo;
			vMap[fromVertex].edges.push_back(temp);
		}
	}
	else
		throw DigraphException();

}

#endif