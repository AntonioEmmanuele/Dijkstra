#include "stdio.h"
#include "algo.h"
#define DEBUG 0
#define DBG 0
int main(){

	Node arr[6];
	for(int i=0;i<6;i++)
		Create_Node(&arr[i],117+i,0,0,0,0);//Add neig manually
#if DEBUG
	for(int i=0;i<6;i++)
		printf("Node name %c \n ",arr[i].name);
#endif
//Creating links
//u v w x y z
//0 1 2 3 4 5
	Node* links0[3];
	Node* links1[3];
	Node* links2[4];
	Node*links3[4];
	Node* links4 [3];
	Node* links5[2];
	unsigned int link0_prices[3]={2,5,1};
	unsigned int link1_prices[3]={2,1,2} ;
	unsigned int link2_prices[4]={1,3,1,5};
	unsigned int link3_prices[4]={1,2,3,1};
	unsigned int link4_prices[3]={1,1,2};
	unsigned int link5_prices[2]={5,2};
	links0[0]=&arr[1];
	links0[1]=&arr[2];
	links0[2]=&arr[3];
	links1[0]=&arr[0];
	links1[1]=&arr[2];
	links1[2]=&arr[3];
	links2[0]=&arr[1];
	links2[1]=&arr[3];
	links2[2]=&arr[4];
	links2[3]=&arr[5];
	links3[0]=&arr[0];
	links3[1]=&arr[1];
	links3[2]=&arr[2];
	links3[3]=&arr[4];
	links4[0]=&arr[2];
	links4[1]=&arr[3];
	links4[2]=&arr[5];
	links5[0]=&arr[2];
	links5[1]=&arr[4];
	Add_Neig(&arr[0],links0,link0_prices,3);
	Add_Neig(&arr[1],links1,link1_prices,3);
	Add_Neig(&arr[2],links2,link2_prices,4);
	Add_Neig(&arr[3],links3,link3_prices,4);
	Add_Neig(&arr[4],links4,link4_prices,3);
	Add_Neig(&arr[5],links5,link5_prices,2);
#if DEBUG
	for(int i=0;i<6;i++){
		for(int j=0;j<arr[i].number_neighbours;j++)
			printf(" Node %c has neig %c with price %d \n ",arr[i].name,arr[i].neighbours[j]->name,arr[i].neighbours_prices[j]);

	}

#endif
#if DBG
	//Test for the Find Neig funct
	int n=Find_Neig(&arr[3],&arr[4]);
	int n1=Find_Neig(&arr[3],&arr[1]);
	int n2=Find_Neig(&arr[3],&arr[2]);
	printf(" [MAIN] The pos is %d %d %d \n ",n,n1,n2);
#endif
	Node* pass[6];
	Algo algo;
	for(int i=0;i<6;i++)
				pass[i]=&arr[i];
	Find_Path(pass,6,pass[0],&algo);

	for(int i=0;i<6;i++)
			Delete_Node(&arr[i]);
	Delete_Algo(&algo);
	//printf("Hello world \n ");
	return 0;
}
