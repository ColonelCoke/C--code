/*
* Name: Orion Gregory
* Email: oagregory@crimson.ua.edu
* Course Section: Fall 2023 CS 201 001
* Homework #: 4
* To Compile g++ homework4.cpp
* To Run: ./a.exe <input.txt>
*/
#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <limits>
#include <queue>

using namespace std;

class Vertex {
public:
	bool visited;
	int distance;
	int previous;
	int finish;
	std::list<int> adj;
};

class Graph {
public:
	Graph(int V, int E, std::pair<int, int> *edges) {
		_V = V;
		_E = E;
		vertices = new Vertex[_V];
		for (int i = 0; i < _V; i++) {
                    vertices[i].visited = false;
                    vertices[i].distance = INT_MAX;
                    vertices[i].previous = -1;
		}
		for (int i = 0; i < _E; i++) {
		    addEdge(edges[i].first, edges[i].second);
		}
	}

	virtual ~Graph() {
		for (int i=0; i<_V; ++i) {
		    auto adj = vertices[i].adj;
		    adj.clear(); // clear list
		}

		delete[] vertices; // delete array of vertices
	}

	int V() {
		return _V;
	}

	int E() {
		return _E;
	}

	void addEdge(int u, int v) {
		vertices[u].adj.push_back(v);
	}

	std::list<int> getEdges(int u) {
		return vertices[u].adj;
	}

	int degree(int u) {
		return vertices[u].adj.size();
	}

	void bfs(int s) {
		for(int i = 0; i < _V; i++)
		{
			vertices[i].visited = false;
			vertices[i].distance = INT_MAX;
			vertices[i].previous = -1;
		}
		// set starting vertex "s" as visited, and with zero distance
		vertices[s].visited = true;
		vertices[s].distance = 0;
		vertices[s].previous = -1;
		queue<int> Q; // Queue for BFS with s as the starting vertex
		Q.push(s);
		while(Q.empty() != 1)
		{
			int u = Q.front();
			Q.pop(); // Dequeue vertex
			for(auto it : vertices[u].adj)
			{
				if(vertices[it].visited == false) // If vertex is not visited, mark as visited
				{
					vertices[it].visited = true;
					vertices[it].distance = vertices[u].distance + 1; // update distance
					vertices[it].previous = u;  // update previous
					Q.push(it); // Queues next vertex
				}
			}
		}
	}

	void dfs() {
		for(int i = 0; i < _V; i++)
		{
			vertices[i].visited = 0;
			vertices[i].previous = -1;
		}
		time = 0;
		for(int i = 0; i < _V; i++)
		{
			// If vertex has not been visited, perform DFS starting at that vertex
			if(vertices[i].visited == 0)
			{
				dfs_visit(i);
			}
		}
	}

	void dfs_visit(int u) {
		time++;
		vertices[u].distance = time; 
		vertices[u].visited = 1; // marks starting vertex as visited
		for(auto it : vertices[u].adj) // iterates through all adjacent vertices
		{
			if(vertices[it].visited == 0)
			{
				vertices[it].previous = u; 
				dfs_visit(it); //recursively visits all adjacent vertices that have not been visited
			}
		}
		cout << u << " "; // marks current vertex as visited, and prints to terminal the value
		time++;
		vertices[u].previous = time;
	}

	void print_path(int s, int v) {
		if (v == s)
		   std::cout << s;
		else if (vertices[v].previous == -1)
		   std::cout << "not connected";
		else {
		   print_path(s,vertices[v].previous);
		   std::cout << "->" << v;
		}
	}

	std::string toString() {
		std::stringbuf buffer;
		std::ostream os(&buffer);
		os << "Vertices = " << _V << ", Edges = " << _E << std::endl;
		for (int i = 0; i < _V; ++i) {
		    os << i << "(" << degree(i) << "): ";
		    for (const auto& l : vertices[i].adj) 
			os << l << " ";
		    os << std::endl;
		}

		return buffer.str();
	}
private:
	int _V; // no. of vertices
	int _E; // no. of edges
	Vertex *vertices; // array of vertices

	int time; // This was used in the psuedocode given to us, but I did not see it implemented here, so I added it
};

#endif
