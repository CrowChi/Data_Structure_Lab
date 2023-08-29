#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MaxNode 6

int graph[MaxNode][MaxNode] = {
	{0,1,1,1,0,0},
	{1,0,1,1,1,0},
	{1,1,0,0,0,0},
	{1,1,0,0,1,1},
	{0,1,0,1,0,0},
	{0,0,0,1,0,0}
	};
	
char NodeName[MaxNode] = {'A','B','C','D','E','F'};

void DispArray2D() {
	int i ,j ;
	
	printf("  ") ;
	
	for(j = 0 ; j <= MaxNode ; j++) {
		printf("%c ",NodeName[j]) ;
	} 	printf("\n") ;
	
	for(i = 0 ; i < MaxNode ; i++) {
		printf("%c ",NodeName[i]) ;
		for(j = 0 ; j < MaxNode ; j++) {
			printf("%d ",graph[i][j]) ;
		}	printf("\n") ;
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
	} 	printf("}\n") ;
} //end DispSetOfVertex fn.

void DispSetOfEdge_1() {
	int i ,j ;
	printf("\nSet of Edge 1 = {") ;
	for(i = 0 ; i < MaxNode ; i++) {
		for(j = 0 ; j < MaxNode ; j++) {
			if(graph[i][j] == 1) {
				printf("(%c,%c)",NodeName[i] ,NodeName[j]) ;
				if(i != MaxNode-1)
					printf(",") ;
			} //end if
		} //end for
	} 	printf("}\n") ;
} //end DispSetOfEdge 1 fn.

void DispSetOfEdge_2() {
	int  i ,j , k ;
	char ch = 'X' ;
	printf("\nSet of Edge 2 = {") ;
	for(i = 0 ; i < MaxNode ; i++) {
		for(j = 0 ; j < MaxNode ; j++) {
			if(graph[i][j] == 1) {
				for(k = 0 ; k < MaxNode ; k++) {
					if(graph[j][k] == 1 && k != j) {
						if(ch == 'X') {
							printf("(%c,%c,%c)",NodeName[i] ,NodeName[j] ,NodeName[k]) ;
							ch = 'O' ;
						} else {
							printf(",(%c,%c,%c)",NodeName[i] ,NodeName[j] ,NodeName[k]) ;
						} //end if
					} //end if
				} //end for
			} //end if
		} //end for
	} 	printf("}\n") ;
} //end DispSetOfEdge 2 fn.

int main() {
	printf("GRAPH (ADJACENCY MATRIX REPRESENTATION METHON)\n") ;
	printf("----------------------------------------------\n") ;
	
	DispArray2D() ;
	
	DispSetOfVertex() ;
	
	DispSetOfEdge_1() ;
	DispSetOfEdge_2() ;
	
	getch() ;
	return 0;
}

