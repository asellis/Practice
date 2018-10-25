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
#include <algorithm>
#include <functional>

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

	// Returns a vector of the edges "from" and "to" vertex numbers for a given
	// vertex as a pair
	std::vector<std::pair<int, int>> edges(int vertex) const;

	// Returns the vertex info
	VertexInfo vertexInfo(int vertex) const;

	// Returns the edge info
	EdgeInfo edgeInfo(int fromVertex, int toVertex) const;

	// Returns the shortest path to every other vertex from a start vertex
	// Returned as a map where the keys are the vertex numbers and the value
	// is the precedessor of that vertex
	// Uses Dijkstra's algorithm
	// Uses a function to compare the edge infos
	std::map<int, int> findShortestPaths(int startVertex, std::function<double(const EdgeInfo&)>
		edgeWeightFunc) const;
	

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

template <typename VertexInfo, typename EdgeInfo>
std::vector<int> Digraph<VertexInfo, EdgeInfo>::vertices() const
{
	std::vector<int> v;
	for(const auto& mapPair : vMap)
		v.push_back(mapPair.first);
	return v;
}

template <typename VertexInfo, typename EdgeInfo>
std::vector<std::pair<int, int>> Digraph<VertexInfo, EdgeInfo>::edges() const
{
	std::vector<std::pair<int, int>> e;
	for(const auto& mapPair : vMap)
	{
		for(const auto& edge : mapPair.second.edges)
		{
			if(std::find(e.begin(), e.end(), std::pair<int, int>(edge.fromVertex, edge.toVertex)) == e.end())
			{
				e.push_back(std::pair<int, int>(edge.fromVertex, edge.toVertex));
			}
		}
	}
	return e;
}

template <typename VertexInfo, typename EdgeInfo>
std::vector<std::pair<int, int>> Digraph<VertexInfo, EdgeInfo>::edges(int vertex) const
{
	std::vector<std::pair<int, int>> e;
	if(vMap.find(vertex) != vMap.end())
	{
		for(const auto& edge : vMap.at(vertex).edges)
		{
			e.push_back(std::pair<int, int>(edge.fromVertex, edge.toVertex));
		}
	}
	return e;
}

template <typename VertexInfo, typename EdgeInfo>
VertexInfo Digraph<VertexInfo, EdgeInfo>::vertexInfo(int vertex) const
{
	if(vMap.find(vertex) != vMap.end())
		return vMap.at(vertex).vinfo;
	return VertexInfo{};
}

template <typename VertexInfo, typename EdgeInfo>
EdgeInfo Digraph<VertexInfo, EdgeInfo>::edgeInfo(int fromVertex, int toVertex) const
{
	if(vMap.find(fromVertex) != vMap.end())
	{
		for(const auto& edge : vMap.at(fromVertex).edges)
			if(edge.toVertex == toVertex)
				return edge.einfo;
	}
	return EdgeInfo{};
}

template <typename VertexInfo, typename EdgeInfo>
std::map<int, int> Digraph<VertexInfo, EdgeInfo>::findShortestPaths(
	int startVertex,
	std::function<double(const EdgeInfo&)> edgeWeightFunc) const
{
	// Unoptimized

	// all items are stored in vectors where the index of one vector corresponds to
	// the same vertex of the other vectors
	std::vector<int> vertex;	// holds all the vertecies
	std::vector<bool> k;		// contains wether the shortest path for a vertex has been found
	std::vector<int> p;			// holds the previous vertex for the shortest path
								// will be -1 for none values
	std::vector<int> d;			// the evaluation/distance from start vertex
								// max int for values not yet initiallized

	// setting up the vectors with their default values
	for( const auto& m_pair : vMap)
	{
		vertex.push_back(m_pair.first);
		k.push_back(false);

		// copy the vertex into p only for the initial vertex
		if(m_pair.first == startVertex)
		{
			p.push_back(m_pair.first);
			d.push_back(0);
		}
		else
		{
			p.push_back(-1);
			d.push_back(std::numeric_limits<int>::max());
		}
	}
		
	// will keep doing the algorithm until all shortest paths are found
	while(std::find(std::begin(k), std::end(k), false) != std::end(k))
	{
		// check if all false are inf
		// if position = -1 then no more positions found

		// find the smallest d that is false and store index into position
		int smallest_d = std::numeric_limits<int>::max();
		int position = -1;
		for( int i = 0; i < vertex.size(); ++i)
		{
			if( d[i] < smallest_d & k[i]==false)
			{
				position = i;
				smallest_d = d[i];
			}

		}

		if(position == -1)
		{
			for( int i = 0; i < vertex.size(); ++i)
			{
				if( k[i]==false )
				{
					// copy vertex for those that can't be reached
					p[i]=vertex[i];
				}

			}
			break;
		}

		// mark the vertex's k value as true
		k[position] = true;

		// iterate through edges of vertex with smallest d
		for( const auto& edge : vMap.at(vertex[position]).edges )
		{
			// find position of edge to
			auto it = std::find(vertex.begin(), vertex.end(), edge.toVertex);
			int index = -1;
			if(it != vertex.end())
			{
				index = std::distance(vertex.begin(), it);
			}
			if(index != -1)
			{
				// inital case
				if(d[index] == std::numeric_limits<int>::max())
				{
					d[index] = d[position] + edgeWeightFunc(edge.einfo);
					p[index] = vertex[position];
				}
				// case if it is shorter
				else if(d[index] > d[position]+edgeWeightFunc(edge.einfo))
				{
					d[index] = d[position]+edgeWeightFunc(edge.einfo);
					p[index] = vertex[position];
				}
			}
		}
	}

	// put everything into a map
	std::map<int, int> paths;
	
	for(int i = 0; i < vertex.size(); ++i)
	{
		paths[vertex[i]] = p[i];
	}
	
    return paths;

}

#endif