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
	weight = new int[nodes];
}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	array = new int *[rno];
	for (int i = 0; i < rno; i++)
	{
		array[i] = new int[rno];
	}
	weight = new int[rno];
	budget = rbudget;
	nodes = rno;
	int top = 0;
	string str;
	for (int i = 0; i <= rno; i++)
	{
		weight[i] = 0;
	}
	for (int i = 0; i < rno; i++)
	{
		for (int j = 0; j <= rno; j++)
		{
			array[i][j] = 0;
		}
	}


}
void Graph::addEdge(int node1, int node2)
// adds an edge between two nodes in the graph node1 and node2
{
	if (node1 < nodes || node2 < nodes)
		array[node1][node2] = 1;

			
}
void Graph:: setValue(int node, float rval) // sets a value for a node
{             
	if (node < nodes)
		weight[node] = rval;
}
void Graph:: setBudget(float rbu) // sets the initial budget
{
	budget = rbu;
}
int Graph:: getNSize() // return number of nodes
{
	return nodes;
}
int Graph::getESize() // return number of edges
{
	int edge = 0;
	for (int i = 0; i < nodes; i++)
	{
		for (int j = 0; j <= nodes; j++)
		{
			if (array[i][j] == 0.)
				edge++;
		}
	}
		return edge;
}
float Graph:: getBudget() // return current budget
{
	return budget;
}

float Graph:: getValue(int node) // returns the value of the node
{
	
	return weight[node];
	return 0;
	
}
void Graph:: readData(string fileName) // reads data from a specified file
{
	ifstream read("smallgraph.txt");
	int lines = 1;
	for (int i = 0; i <= lines; i++)
	{
		if (i == 0)
		{
			read >> nodes;
		}
		if (i == 1)
		{
			read >> budget;
		}
	}
	for (int i = 2; i < nodes + 2; i++)
	{
		read >> weight[i - 2];
	}
	string s;
	int sTotal = 1;
	while (!read.eof())
	{
		getline(read, s);
		sTotal++;
	}
	int n, m;
	//int c1[sTotal - nodes];
	//int c2[sTotal - nodes];
	int i = 1;
	while (read >> n >> m)
	{
		addEdge(n, m);
		i++;
	}
	read.close();

}
int Graph:: DFS(int startNode) //return the number of nodes visited using BFS starting at startNode and accumulating values at each node, as long as the budget remains positive
{

	int n = 1;
	int v = startNode;
	int k = 1;
	for (int j = nodes; j >= 0; j--)
	{
		if (array[v][j] != 0)
		{
			//    stk[top]=j;
			if (budget>0)
			{
				budget = budget - weight[v];
				n++;
				v = j;
			}
		}
	}
	return n;
}

// return the starting node that gives a longest DFS run before running out of budget
// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph:: bestStartVertex()
{
	int n = 1;
	int lastnode = 2;
	int nod = 0;
	int k = 1;
	for (int v = 0; v<nodes; v++)
	{
		for (int j = nodes; j >= 0; j--)
		{
			if (array[v][j] != 0)
			{
				//stk[top]=j;
				if (budget>0)
				{
					budget = budget - weight[v];
					n++;
					v = j;
				}
			}
		}
		if (n>lastnode)
		{
			lastnode = n;
			nod = v;
		}
		n = 1;
	}
	return nod;
}
