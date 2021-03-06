//
//  graph.cpp
//  Project4
//
//  Created by Bein, Doina on 4/21/18.
//  Copyright © 2018 Bein, Doina. All rights reserved.
//

#include "graph.h"
#include <list>
#include <fstream>
#include <iostream>
#include <string>

// TO BE COMPLETED WITH IMPLEMENTATIONS OF GRAPH MEMBER FUNCTIONS
Graph::Graph() // default constructor
{   
	edge = 0;
	countNodes = 100;
	load = new float[countNodes];
	visited = new bool[countNodes];
	for (int i = 0; i < countNodes; i++) {
		visited[i] = false;
	}
	array = new int*[countNodes];
	for (int a = 0; a < countNodes; a++)
	{
		array[a] = new int[countNodes];
	}

}

Graph::Graph(int rno, float rbudget) // constructor with two arguments representing the number of nodes, initial budget
{
	array = new int*[rno];
	for (int a = 0; a < rno; a++)
	{
		array[a] = new int[rno];
	}
	load = new float[rno];
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
	visited = new bool[countNodes];
	for(int i= 0; i < countNodes;i++){
		visited[i] = false;
	}
}
void Graph::addEdge(int node1, int node2)
// adds an edge between two nodes in the graph node1 and node2
{
	array[node1][node2] = 1;
	array[node2][node1] = 1;
	edge++;	
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
	ifstream myFile(fileName);
	if (myFile.is_open()) {
		myFile >> countNodes;
		myFile >> amount;
		//Graph(countNodes, amount);
		cout << "Read from file countNodes=" << countNodes << endl;
		for (int j = 0; j < countNodes; j++) {
			myFile >> load[j];
		}
		int n, m;
		while (myFile >> n >> m) {
			addEdge(n, m);
		}

		myFile.close();
	}
	else{
		throw "Could not open the file" + fileName;
	}
}
int Graph:: DFS(int startNode) //return the number of nodes visited using BFS starting at startNode and accumulating values at each node, as long as the budget remains positive
{
	if(amount > 0){
		amount = amount + load[startNode];
		visited[startNode] = true;
		for(int i = 0;i<countNodes;i++){
			if(array[startNode][i] == 1){
				if(visited[i] == false){
					n++;
					DFS(i);
				}
			}
		}
	}
	return n;
}

// return the starting node that gives a longest DFS run before running out of budget
// if there are multiple nodes with the same DFS run length, return the smallest node
int Graph:: bestStartVertex(){
	int longest = 0;
	int n = 0;
	for(int i = 0;i<countNodes;i++){
		if(DFS(i) > longest){
			longest = DFS(i);
			n = i;
		}
			
	}
	return n;

			
}
