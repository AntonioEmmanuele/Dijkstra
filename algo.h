#ifndef ALGO_H
#define ALGO_H
#include "data_struct2.h"
/* This code was created by Antonio Emmanuele only to understand better Dijkstra algo, it isn't intended for real world application */

/*
 * N is the number of nodes that have min path
 * c(x,y) x and y are neig
 * D(v) min cost from dest to x
 *
 */
 /*
 	The algo in the init fase addes just the source to min_path ad update the list of min path with the source neig
 	On every interation it finds a new min path and adds the node dest to N
 	How?
 	The algo finds  a min path from the source (Between destination that isn't in n ) to a node and update it(In fact in the first iteration it finds the neig with cheapest price)
 	Then creates new paths by the neig of the new node in N, if the Path dest isn't in D(v), the vector of imin_paths, it added them.
 	If the Dest of the new paths are in N checks if the price of the new path is lower of che old path(if it is , update the old path with the new)
 	One of the most important thing is that in every iteration we have a new node in N
 */
#define DEBUG_ALG 0
#define DEBUG_ALG2 1
typedef struct {
	unsigned int N;//Number of nodes n the min path
	Path* dv;//Must be set by number of nodes, this is the vector of paths, dv[n] means the path from the source to node n
	//dv[0] is the source
	unsigned int* taken; //This array indicates if a specific path,for a specific node is in N (0 not ,1 yes)
	//path 0 is the path for node 0 and path[5] is the path for the 5 node.
	//taken [n]==1 means that nodes n is in N and we have a min path
	unsigned int* actual_paths;//This works like taken except that if actual_paths[n]==1 means just that there is a path in the dv vector and not that
	//the destination is in n
	unsigned int num_elements;
}Algo;
//Find_Path(nodes array,number of elements,source, algo struct pointer)
int Find_Path(Node**,unsigned int,Node*,Algo*);
//removes algo
void Delete_Algo(Algo*);
#endif
