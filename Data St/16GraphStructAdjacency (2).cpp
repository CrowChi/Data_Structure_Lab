#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MaxNode 4


/*
#define A  0
#define	B  1
#define	C  2
#define	D  3

*/
char NodeName[MaxNode]= {'A','B','C','D'};
int s , e ;
int graph[MaxNode][MaxNode]={
	{0,1,1,1},
	{1,0,1,1},
	{1,1,0,0},
	{1,1,0,0}
	};

struct Node
	{
		char info;
		struct Node *next;
	};

struct Node *Start[MaxNode], *p;

Node *Allocate()
	{
		struct Node *temp;
		temp = (Node*)malloc(sizeof(Node));
		return(temp);
	}
void CreateHead()
	{
		int i;
		for( i = 0 ; i < MaxNode ; i++ )
			{
				p = Allocate();
				p->info = NodeName[i];
				p->next = NULL;
				Start[i] = p;
			}
	}
void TransferToAdjacent()
	{
		int i,j;
		struct Node *Rear;
		for( i = 0 ; i < MaxNode ; i++ )
			{
				 Rear = Start[i];
				for( j = 0 ; j < MaxNode ; j++ )
					{
					if( graph[i][j] == 1 )
							{
								p = Allocate();
								p->info = NodeName[j];
								p->next = NULL;
								Rear->next = p;
								Rear = p;
							}
					}
			}
	}
void DispSetOfVertex()
	{
		int i;
		printf("\nSet of Vertex = {");
		for( i = 0 ; i < MaxNode ; i++ )
			{
				printf("%c",Start[i]->info);
				if( i != MaxNode-1 )
					printf(",");
			}
		printf("}\n");
	}
void DispSetOfEdge()
	{
		int i;
		struct Node *Temp;
		printf("\nSet of Edge ={");
	
	if(e<s){
	
		for( i = s+1 ; i > e-1; i-- )
			{
				Temp = Start[i];
				Temp = Temp->next;
				while( Temp != NULL )
					{
						printf("(%c,%c),",Start[i]->info,Temp->info);
						Temp = Temp->next;
					}
			}
		printf("}\n");
		}else{
			
			for( i = s ; i < e+1 ; i++ )
			{
				Temp = Start[i];
				Temp = Temp->next;
				while( Temp != NULL )
					{
						printf("(%c,%c),",Start[i]->info,Temp->info);
						Temp = Temp->next;
					}
			}
		printf("}\n");
			
		}
		
	}
	
	
	
	void scan(){
		
		printf("Input Start : ");
		scanf("%d",&s);
		
		printf("\nInput End : ");
		scanf("%d",&e);
		
	}
	
	
	
	
int main()
	{
		printf("GRAPH (ADJACENCY LIST REPRESENTATION METROD)\n");
		printf("============================================\n");
		scan();
		CreateHead();
		TransferToAdjacent();
		DispSetOfVertex();
		DispSetOfEdge();
		getch();
		return(0);
		
	}
