#include "algo.h"
/* This code was created by Antonio Emmanuele only to understand better Dijkstra algo, it isn't intended for real world application */

static int  Init(Node**,unsigned int,Node*,Algo*);
static int Init(Node** nodes,unsigned int number_elements,Node* source,Algo *algo){
		int position=Find_Element(nodes,source,number_elements); //find the source position
		if(position<0){
#if DEBUG_ALG
			printf("Don' t find the el \n");
			return -1;
#endif

		}

		//Let' start building vectors
		algo->num_elements=number_elements;
		algo->dv=malloc(sizeof(Path)*number_elements);
		algo->taken=malloc(sizeof(int)*number_elements);
		algo->actual_paths=malloc(sizeof(int)*number_elements);
		//Add first node to dv
		for(int i=0;i<number_elements;i++){
			if(i==position){
				algo->taken[i]=1;
				algo->actual_paths[i]=1;
				Create_Path(&nodes[position],1,0,&algo->dv[position]);
			}
			else{
				algo->taken[i]=0;
				algo->actual_paths[i]=0;
			}
		}
		algo->N=1;
#if		DEBUG_ALG
		printf("Middle  of the initialization, the Node %c is the source , number of min path is %d and have this elements in dv \n ",algo->dv[position].nodes[0]->name, algo->N);
		for(int i=0;i<number_elements;i++){
			printf("%d %d \n",algo->taken[i],algo->actual_paths[i]);

		}

#endif
		//update
		//Number of neig of the shortest

		unsigned int in_path=algo->dv[position].number_nodes-1;//location in the path of the last element (the destination, in this case the source)
		unsigned int num_neig=algo->dv[position].nodes[in_path]->number_neighbours;//number of neig of the destination
		Node* pointers[num_neig]; //neighbours pointers
		Path help[number_elements]; //use it to create new paths from the previous cheapest path
		unsigned int help_vector[number_elements];// we can have every neig , so we need a state vect just like in actual_paths and taken
		for(int i=0;i<number_elements;i++)
			help_vector[i]=0;
		int pos=0;
		for(int i=0;i<num_neig;i++){
			pointers[i]=algo->dv[position].nodes[in_path]->neighbours[i];//have nodes
			pos=Find_Element(nodes,pointers[i],number_elements);//find nodes position in the array
			Create_From_Path(&algo->dv[position],nodes[pos],0,&help[pos]);//create a new path from the to source to a specitic neig
			help_vector[pos]=1;//we have the path to that neig
#if DEBUG_ALG
			printf("neig pos %d \n ", pos);
#endif
		}
		for(int i=0;i<number_elements;i++){
			if(help_vector[i]==1)
				algo->actual_paths[i]=1;//update actual paths

		}
#if DEBUG_ALG
		printf("Position of the new elements \n");
		for(int i=0;i<number_elements;i++){
			if(algo->actual_paths[i]==1)
				printf("%d \n",i);


		}
		printf("Neig are %d \n ",num_neig);
		for(int i=0;i<num_neig;i++){
			printf("%c \n ",pointers[i]->name);
		}

#endif

for(int i=0;i<number_elements;i++){
	if(algo->taken[i]==0&&algo->actual_paths[i]==1&&algo->taken[i]==0)
		algo->dv[i]=help[i]; //If there is no path
	else if (algo->taken[i]==1&& algo->actual_paths[i]==1&&algo->taken[i]==0){
		if(algo->dv[i].total_cost>help[i].total_cost)
			algo->dv[i]=help[i]; //If it has better price update
	}


}
#if		DEBUG_ALG
		printf("End of the initialization, the Node %c is the source , number of min path is %d and have this elements in dv \n ",algo->dv[position].nodes[0]->name, algo->N);
		for(int i=0;i<number_elements;i++){
			if(algo->actual_paths[i]==1)
				printf("%d   %c  \n ",i,algo->dv[i].nodes[algo->dv[i].number_nodes-1]->name);

		}

#endif

		return position;
}
static void Cycle(Algo*  , int ,Node**);
static void Cycle(Algo* algo , int source_position,Node**nodes){
	unsigned num_elements=algo->num_elements;
	while(algo->N<num_elements){// cycle must continue untill find all nodes
		//Find the cheapest
		unsigned int cheapest_position;
		unsigned int first_int=1;
		for(int i=0;i<num_elements;i++){
			if(algo->actual_paths[i]==1&& i!=source_position&&algo->taken[i]==0){ //Node that is not the source, that I find previously and that is not in N
				if(first_int==1){
					cheapest_position=i;
					first_int=0;
				}
				else {
					if(algo->dv[i].total_cost<algo->dv[cheapest_position].total_cost)
						cheapest_position=i;
				}
			}
		}

#if DEBUG_ALG2
		printf("The cheapest link is %c \n  ", algo->dv[cheapest_position].nodes[algo->dv[cheapest_position].number_nodes-1]->name);
		printf("%d \n ",cheapest_position);
#endif
		//ADD X to N , update taken vector
		algo->N++;
		algo->taken[cheapest_position]=1;
#if DEBUG_ALG2
		printf("Min path find is %d \n ",algo->N);
#endif
		//Update Dv vector and restart the cycle
		unsigned int in_path=algo->dv[cheapest_position].number_nodes-1; //position of the destination
		unsigned int num_neig=algo->dv[cheapest_position].nodes[in_path]->number_neighbours; //Old name
		Node* pointers[num_neig];
		Path help[num_elements];
		unsigned int help_vector[num_elements];
		for(int i=0;i<num_elements;i++)
			help_vector[i]=0;
		int pos=0;
		for(int i=0;i<num_neig;i++){
			pointers[i]=algo->dv[cheapest_position].nodes[in_path]->neighbours[i];
			pos=Find_Element(nodes,pointers[i],num_elements);
			if(pos!=source_position)// Don't need a path for source, we just have the cheapest(from source to source)
					Create_From_Path(&algo->dv[cheapest_position],nodes[pos],cheapest_position,&help[pos]);

			help_vector[pos]=1;
		}

		for(int i=0;i<num_elements;i++){
			if(algo->actual_paths[i]==0&&help_vector[i]==1){
				algo->dv[i]=help[i]; //If there is no path
				algo->actual_paths[i]=1;
			}
			else if (algo->actual_paths[i]==1&& help_vector[i]==1){
				if(algo->dv[i].total_cost>help[i].total_cost)
					algo->dv[i]=help[i]; //If it has better price update
				}
			}

#if DEBUG_ALG2
		printf(" End of interation dv number and costs are \n ");
		for(int i=0;i<num_elements;i++){
			if(algo->actual_paths[i]==1)
				printf("Number %d name %c , total cost %d \n ",i,algo->dv[i].nodes[algo->dv[i].number_nodes-1]->name,algo->dv[i].total_cost);
		}
#endif

	}
}

int Find_Path(Node** nodes,unsigned int number_elements,Node* source,Algo *algo){
	int pos=Init(nodes,number_elements,source,algo);
	printf("The position is %d \n ", pos);
#if DEBUG_ALG
	printf("The position is %d \n ", pos);
#endif
	if(pos<0)
		return -1;
	Cycle(algo,pos,nodes);

	return 0;
}
void Delete_Algo(Algo*algo){
		free(algo->actual_paths);
		for(int i=0;i<algo->num_elements;i++)
			  Delete_Path(&algo->dv[i]);
		free(algo->taken);
}
