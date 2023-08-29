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

void DispSetOfEdge_2() {
	int i ;
	struct Node *temp1 ,*temp2,*temp3,*temp4 ;
	
	printf("\nSet of Edge 2 = {") ;
	
	for(i = 0 ; i < MaxNode ; i++) {
		int j = 0 ;
		temp1 = Start[i] ;
		temp1 = temp1->next ;
		while(temp1 != NULL) {
			while(temp1->info != Start[j]->info) {
				j++ ;
			}	
			int k = 0 ;
			temp2 = Start[j] ;
			temp2  = temp2->next ;
			while(temp2 != NULL) {
				if(temp2->info == Start[k]->info) {
					if(temp2->info != NULL) {
						temp2 = temp2->next ;
						k++ ;
					} //end if
				}
			}
					int l = 0 ;
					temp3 = Start[k] ;
					temp3  = temp3->next ;
					while(temp3 != NULL) {
						if(temp3->info == Start[l]->info) {
							if(temp3->info != NULL) {
								temp3 = temp3->next ;
								l++ ;
							}
					}
				}	
					temp4 = Start[l] ;
					temp4  = temp4->next ;
					while(temp4 != NULL) {
						if(temp4->info == Start[l]->info) {
							if(temp4->info != NULL) {
								temp4 = temp4->next ;
						}
					}
				}
				printf("(%c,%c,%c,%c,%c)",Start[i]->info ,temp1->info ,temp2->info,temp3->info,temp4->info) ;
				temp4 = temp4->next ;
				temp3 = temp3->next ;
				temp2 = temp2->next ;
				temp1 = temp1->next ;
			}
			
			if(i != MaxNode-1) {
				printf(",") ;
			} //end if
		} //end while
	} 	


int main() {
	printf("GRAPH (ADJACENCY LIST REPRESENTATION METHON)\n") ;
	printf("--------------------------------------------\n") ;
	
	CreateHead() ;
	DispSetOfVertex() ;
	
	TransferToAdjacent() ;
	DispSetOfEdge_1() ;
	DispSetOfEdge_2() ;
	
	getch() ;
	return 0;
}
