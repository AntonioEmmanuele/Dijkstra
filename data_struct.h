#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include "stdio.h"
#include "stdlib.h"
#define DEBUG1 0
/* This code was created by Antonio Emmanuele only to understand better Dijkstra algo, it isn't intended for real world application */

typedef struct Node{
	char name;
	unsigned int number_neighbours;
	struct Node**neighbours;
	unsigned int* neighbours_prices;
	unsigned int flag;
}Node; // Node is an entity identified by neighbours and links to neighbours prices , I use flag to check if I've allocate neigs for the node
//Create_Node(Pointer to the node,name,number of neig,array of pointer to Neighbours ,array of neig prices, flag(if 0 don,t create neig)
void Create_Node(Node*,char,unsigned int ,struct Node**,unsigned int*,unsigned int);
//This funct add neig , in case we just add neig in the Creation  this funct deallocates previous and add new neig and prices 
//Add_Neig(Pointer to the node,neig,prices, number of neig)
// It sets also flag to 1, we need it for deallocation 
void Add_Neig(Node*,struct Node**,unsigned int*,unsigned int );
//Delete_Node(Pointer to the node)
void Delete_Node(Node*);
//Given an array of nodes, find a specific node in this array and return his location 
//Find_Element(Array_of_nodes,node to find,number_of elements
//this funct returns neg value in case it doesn't find the node 
int Find_Element(Node**,Node*,unsigned int);
//Given a specific Node this funct find the position , in the neig array , of a specific node
//Find_Neig(Node_a,neig_to_find)
//In case neig_to_find isn't a neig this funct returns neg values
int Find_Neig(Node*,Node*);



#endif
