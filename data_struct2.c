#include "data_struct2.h"
/* This code was created by Antonio Emmanuele only to understand better Dijkstra algo, it isn't intended for real world application */

static unsigned int Calc_Total_Cost(Node**,unsigned int  );
void Create_Path(Node**nodes ,unsigned int number_nodes,unsigned int flg, Path*path){
	path->nodes=malloc(sizeof(Node*)*number_nodes);
	path->number_nodes=number_nodes;
	for(int i=0;i<number_nodes;i++)
		path->nodes[i]=nodes[i];
	if(flg==1)
		path->total_cost=Calc_Total_Cost(path->nodes,path->number_nodes);
	else
		path->total_cost=0;
#if DEBUG2
	printf("The number of noodes in the path is %d \n ",path->number_nodes);
	for(int i=0;i<number_nodes;i++)
		printf("the new path has nodes %c \n ",path->nodes[i]->name);

#endif

}
void Delete_Path(Path*path){
	free(path->nodes);

}
static unsigned int Calc_Total_Cost(Node**nodes,unsigned int num_nodes ){
	unsigned int total_cost=0;
	for(int i=0;i<num_nodes-1;i++){
		for(int j=0;j<nodes[i]->neighbours_prices[i];j++){
			if(nodes[i+1]->name==nodes[i]->neighbours[j]->name)
				total_cost=total_cost+nodes[i]->neighbours_prices[j];


		}



	}

	return total_cost;


}
void Create_From_Path(Path*origin,Node*neig,unsigned int source ,Path*new){ //source is the beginning element of the node


	new->number_nodes=origin->number_nodes+1;
	new->nodes=malloc(sizeof(Node*)*new->number_nodes);
	for(int i=0;i<new->number_nodes-1;i++){
		new->nodes[i]=origin->nodes[i];
	}
	new->nodes[new->number_nodes-1]=neig;

	int neig_pos=Find_Neig(origin->nodes[origin->number_nodes-1],neig);

	new->total_cost=origin->total_cost+origin->nodes[origin->number_nodes-1]->neighbours_prices[neig_pos];
#if DEBUG2
	printf("The number of noodes in the path is %d \n ",new->number_nodes);
	for(int i=0;i<new->number_nodes;i++)
		printf("the new path has nodes %c and the price %d \n ",new->nodes[i]->name,new->total_cost);

#endif


}
