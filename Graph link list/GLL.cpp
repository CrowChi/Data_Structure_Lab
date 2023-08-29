#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MaxNode 4

int graph[MaxNode][MaxNode] = {
	{0,1,0,0},
	{1,0,1,1},
	{0,1,0,1},
	{0,1,1,0}
	};
	
struct Node {
	char   info ; 
	struct Node  *next  ;
};

char NodeName[MaxNode] = {'A','B','C','D'};

struct Node *Start[MaxNode] ,*p ;

Node *Allocate() {
	struct Node *temp ;
	temp = (Node*)malloc(sizeof(Node)) ;
	return (temp) ;
} //end Allocate fn.

void CreateHead() {
	int i ;
	
	for(i = 0 ; i < MaxNode ; i++) {
		p = Allocate() ;
		p->info  = NodeName[i] ;
		p->next  = NULL ;
		Start[i] = p ;
	} //end for
} //end CreateHead fn.

void TransferToAdjacent() {
	int i ,j ;
	struct Node *Rear ;
	for(i = 0 ; i < MaxNode ; i++) {
		Rear = Start[i] ;
		for(j = 0 ; j < MaxNode ; j++) {
			if(graph[i][j] == 1) {
				p = Allocate() ;
				p->info   = NodeName[j] ;
				p->next    = NULL ;
				Rear->next = p ;
				Rear = p ;
			} //end if
		} //end for
	} //end for
} //end TransferToAdjacent fn.

void DispSetOfVertex() {
	int i ;
	
	printf("\nSet of Vertex = {") ;
	
	for(i = 0 ; i < MaxNode ; i++) {
		printf("%c",Start[i]->info) ;
		if(i != MaxNode-1) {
			printf(",") ;
		} //end if
	}	printf("}\n") ;
} //end DispSetOfVertex fn.

void DispSetOfEdge_1() {
	int i ;
	struct Node *temp ;
	
	printf("\nSet of Edge 1 = {") ;
	
	for(i = 0 ; i < MaxNode ; i++) {
		temp = Start[i] ;
		temp = temp->next ;
		while(temp != NULL) {
			printf("(%c,%c)",Start[i]->info ,temp->info) ;
			temp = temp->next ;
			if(i != MaxNode-1)
				printf(",") ;
		} //end while
	} 	printf("}\n") ;
} //end DispSetOfEdge fn.

int main() {
	printf("GRAPH (ADJACENCY LIST REPRESENTATION METHON)\n") ;
	printf("--------------------------------------------\n") ;
	
	CreateHead() ;
	DispSetOfVertex() ;
	
	TransferToAdjacent() ;
	DispSetOfEdge_1() ;

	
	getch() ;
	return 0;
}
