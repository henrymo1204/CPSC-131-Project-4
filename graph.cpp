//
//  graph.cpp
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#include "graph.h"
#include<list>
// TO BE COMPLETED WITH IMPLEMENTATIONS OF GRAPH MEMBER FUNCTIONS
Graph::Graph() // default constructor
{
	countE = 0;
	countN = 0;
}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	
	newbudget = rbudget;

		this->countN = rno;
		adj = new list<int>[rno];



}
void Graph::addEdge(int node1, int node2)
// adds an edge between two nodes in the graph node1 and node2
{
	

		adj[node1].push_back(node2);
		adj[node2].push_back(node1);
	
}
void Graph:: setValue(int node, float rval) // sets a value for a node
{             
	
}
void Graph:: setBudget(float rbu) // sets the initial budget
{
	newbudget = rbu;
}
int Graph:: getNSize() // return number of nodes
{
	return countN;
}
int Graph::getESize() // return number of edges
{
	int sum = 0;
	for (int i = 0; i < countE; i++)
		sum += adj[i].size();

	return sum / 2;
}
float Graph:: getBudget() // return current budget
{
	return newbudget;
}

float Graph:: getValue(int node) // returns the value of the node
{
	newnode = node;
	return newnode;
	
}
void Graph:: readData(string fileName) // reads data from a specified file
{

}
int Graph:: DFS(int startNode) //return the number of nodes visited using BFS starting at startNode and accumulating values at each node, as long as the budget remains positive
{
	return 0;
}

						// return the starting node that gives a longest DFS run before running out of budget
						// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph:: bestStartVertex()
{
	return 0;
}
