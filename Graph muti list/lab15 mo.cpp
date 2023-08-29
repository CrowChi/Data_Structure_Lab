#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MaxEdge 8
#define Block   5
#define MaxNode 5

char NodeName[MaxNode] = {'A','B','C','D','E'};

int graph[MaxEdge][Block] = {
	{'0','A','B','2','5'},
	{'0','A','C','3','5'},
	{'0','A','D','4','6'},
	{'0','A','E','-','7'},
	{'0','B','C','6','7'},
	{'0','B','D','-','8'},
	{'0','C','E','-','8'},
	{'0','D','E','-','-'},
	};

void DispArray2D() {
	int i ,j ;
	printf("   M V1 V2 E1 E2\n") ;
	for(i = 0 ; i < MaxEdge ; i++) {
		printf("%d ",i+1) ;
		for(j = 0 ; j < Block ; j++) {
			printf(" %c ",graph[i][j]) ;
		} 	printf("\n") ;
	} //end for
} //end DispArray2D fn.

void DispSetOfVertex() {
	int i ;
	printf("\nSet of Vertex = {") ;
	for(i = 0 ; i < MaxNode ; i++) {
		printf("%c",NodeName[i]) ;
		if(i != MaxNode-1) {
			printf(",") ;
		} //end if
	} printf("}\n") ;
} //end DispSetOfVertex fn.

void DispSetOfEdge_1() {
	int i ,j ;
	printf("\nSet of Edge 1 = {") ;
	for(i = 0 ; i < MaxEdge ; i++) {
		printf("(%c,%c),",graph[i][1],graph[i][2]) ;
		printf("(%c,%c)" ,graph[i][2],graph[i][1]) ;
		if(i != MaxEdge-1) {
			printf(",") ;
		} //end if
	}	printf("}\n") ;
} //end DispSetOfEdge fn.

void DispSetOfEdge_2() {
	int i ,j ,k ;
	printf("\nSet of Edge 2 = {") ;
	for(i = 0 ; i < MaxEdge ; i++) {
		j = (graph[i][4] - 48) - 1; // convert string to integer
		k = (graph[j][4] - 48) - 1;
		if (k != -4 && graph[i][2] && graph[i][1] != graph[j][2] && graph[j][1] != graph[k][2] && graph[k][1]) {
			printf("(%c,%c,%c,%c)",graph[i][1],graph[i][2],graph[j][2],graph[k][2]) ;
		} else {
			break;
		}
		if(i != MaxEdge-1) {
			printf(",") ;
		} //end if
	}	printf("}\n") ;
} //end DispSetOfEdge fn.

int main() {
	printf("GRAPH ADJACENCY MULTI-LIST REPRESENTATION METHOD\n") ;
	printf("================================================\n") ;
	
	DispArray2D() ;
	DispSetOfVertex() ;
	DispSetOfEdge_1() ;
	DispSetOfEdge_2() ;
	return 0;
} //end main fn.
