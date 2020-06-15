#include "data_struct.h"
/* This code was created by Antonio Emmanuele only to understand better Dijkstra algo, it isn't intended for real world application */
void Create_Node(Node* node_to_create,char name ,unsigned int number_neighbours ,struct Node**neighbours,unsigned int*neighbours_prices,unsigned int flag){
	node_to_create->flag=flag;
	if(flag==0){  //In case it is zero doesn't create neigs
		node_to_create->name=name;
#if DEBUG1
		printf("Node create without neig , name %d \n ",node_to_create->name);
#endif
	}
	else if (flag==1){
		node_to_create->name=name;
		node_to_create->number_neighbours=number_neighbours;
		node_to_create->neighbours=malloc(sizeof(Node*)*number_neighbours);
		node_to_create->neighbours_prices=malloc(sizeof(int)*number_neighbours);
		for(int i=0;i<number_neighbours;i++){
			node_to_create->neighbours[i]=neighbours[i];
			node_to_create->neighbours_prices[i]=neighbours_prices[i];
		}
#if DEBUG1
		printf("Node create whit neig , name %d \n ",node_to_create->name);
		printf("Number of neighbours ,Neighbours and prices are %d \n ",node_to_create->number_neighbours);
		for(int i=0;i<number_neighbours;i++)
			printf("Neig %c has price %d \n ",node_to_create->neighbours[i]->name,node_to_create->neighbours_prices[i]);


#endif

	}



}
//Call the same name beacause copying code from Create function
void Add_Neig(Node*node_to_creat,struct Node**neighbours ,unsigned int*neighbours_prices ,unsigned int number_neighbours ){
	if(node_to_creat->flag==1){
		free(node_to_creat->neighbours);
		free(node_to_creat->neighbours_prices);
		node_to_creat->number_neighbours=number_neighbours;
		node_to_creat->neighbours=malloc(sizeof(Node*)*number_neighbours);
		node_to_creat->neighbours_prices=malloc(sizeof(int)*number_neighbours);
		for(int i=0;i<number_neighbours;i++){
			node_to_creat->neighbours[i]=neighbours[i];
			node_to_creat->neighbours_prices[i]=neighbours_prices[i];
		}
#if DEBUG1
		printf("You had neig from init , delete old and create new");
		printf("Number of neighbours ,Neighbours and prices are %d \n ",node_to_creat->number_neighbours);
		for(int i=0;i<number_neighbours;i++)
			printf("Neig %c has price %d \n ",node_to_creat->neighbours[i]->name,node_to_creat->neighbours_prices[i]);
#endif

	}

	else if(node_to_creat->flag==0){
		node_to_creat->number_neighbours=number_neighbours;
		node_to_creat->neighbours=malloc(sizeof(Node*)*number_neighbours);
		node_to_creat->neighbours_prices=malloc(sizeof(int)*number_neighbours);
		for(int i=0;i<number_neighbours;i++){
			node_to_creat->neighbours[i]=neighbours[i];
			node_to_creat->neighbours_prices[i]=neighbours_prices[i];
		}
		node_to_creat->flag=1;
#if DEBUG1
		printf("You don't had neig from init , delete old and create new");
		printf("Number of neighbours ,Neighbours and prices are %d \n ",node_to_creat->number_neighbours);
		for(int i=0;i<number_neighbours;i++)
			printf("Neig %c has price %d \n ",node_to_creat->neighbours[i]->name,node_to_creat->neighbours_prices[i]);
#endif




	}


}
void Delete_Node(Node* node_to_del){
		if(node_to_del->flag==1){ //delete neig only if we add neig 
			free(node_to_del->neighbours);
			free(node_to_del->neighbours_prices);
			node_to_del->neighbours=0;
			node_to_del->neighbours_prices=0;
		}
}
int Find_Element(Node** array,Node* to_find,unsigned int num_elements){
	unsigned int brk=0;
	unsigned int counter=0;
	while(counter<num_elements&&brk==0){
		if(array[counter]->name==to_find->name)
			brk=1;
		else
			counter++;

	}
	if(brk==0)
		return -1;
	else
		return counter;
}
int Find_Neig(Node* node ,Node*neig){
	unsigned int brk=0;
	unsigned int counter=0;
	while(counter<node->number_neighbours&&brk==0){
		if(node->neighbours[counter]->name==neig->name)
			brk=1;
		else
			counter++;

	}
	if(brk==0)
		return -1;
	else
		return counter;

}
