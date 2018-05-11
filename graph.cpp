//
//  graph.cpp
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#include "graph.h"
#include<list>
#include <fstream>
#include <iostream>
#include <string>

// TO BE COMPLETED WITH IMPLEMENTATIONS OF GRAPH MEMBER FUNCTIONS
Graph::Graph() // default constructor
{
	load = new int[countNodes];
}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	array = new int *[rno];
	for (int a = 0; a < rno; a++)
	{
		array[a] = new int[rno];
	}
	load = new int[rno];
	amount = rbudget;
	countNodes = rno;
	int top = 0;
	string str;
	for (int a = 0; a <= rno; a++)
	{
		load[a] = 0;
	}
	for (int a = 0; a < rno; a++)
	{
		for (int i = 0; i <= rno; i++)
		{
			array[a][i] = 0;
		}
	}


}
void Graph::addEdge(int node1, int node2)
// adds an edge between two nodes in the graph node1 and node2
{
	if (node1 < countNodes || node2 < countNodes){
		array[node1][node2] = 1;
		edge++;
	}		
}

void Graph:: setValue(int node, float rval) // sets a value for a node
{             
	if (node < countNodes)
		load[node] = rval;
}
void Graph:: setBudget(float rbu) // sets the initial budget
{
	amount = rbu;
}
int Graph:: getNSize() // return number of nodes
{
	return countNodes;
}
int Graph::getESize() // return number of edges
{
	return edge;
}
float Graph:: getBudget() // return current budget
{
	return amount;
}

float Graph:: getValue(int node) // returns the value of the node
{
	
	return load[node];
	
	
}
void Graph:: readData(string fileName) // reads data from a specified file
{
	ifstream read(fileName);
	int path = 1;
	for (int a = 0; a <= path; a++)
	{
		if (a == 0)
		{
			read >> countNodes;
		}
		if (a == 1)
		{
			read >> amount;
		}
	}
	for (int n = 2; n < countNodes + 2; n++)
	{
		read >> load[n - 2];
	}
	string j;
	int Jsum = 1;
	while (!read.eof())
	{
		getline(read, j);
		Jsum++;
	}
	int v, e;
	while (read >> v >> e)
	{
		addEdge(v, e);
	}
	read.close();

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

