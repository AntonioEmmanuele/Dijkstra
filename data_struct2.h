#ifndef DATA_STRUCT2_H
#define DATA_STRUCT2_H
#include "data_struct.h"
#define DEBUG2 0
/* This code was created by Antonio Emmanuele only to understand better Dijkstra algo, it isn't intended for real world application */

typedef struct{
	Node** nodes; //nodes in the path
	unsigned int number_nodes;
	unsigned int total_cost;
}Path;// We need this because the algo works in term of paths
// It has an array of nodes , the nodes in the path(0 the source and number_nodes-1 the destination)
//Create_Path(array of nodes in the path, number of nodes, flag, Path struct that we need to init)
//we need flag because for the algo the first path is the source itself so we need to init total cost to zero 
void Create_Path(Node**,unsigned int,unsigned int ,Path* );
//Deallocates path
void Delete_Path(Path*);
//this funct is  one of the most important for the algo
//Given an a path this funct creates a new path, just adding a new node, a new destination
//Create_From_Path(Original_Path,New Destination , source,New path variable)
// The variable source is useless, I added it for some future implementation 
//THIS FUNCTION DOESN'T check if the new node is actually a neig of the last node in the origin path
void Create_From_Path(Path*,Node*,unsigned int ,Path*); 
#endif
