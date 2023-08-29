#include <stdio.h>
#include <conio.h>
#define MaxEdge 8
#define Block 5
#define MaxNode 5
char NodeName[5] = {'A','B','C','D','E'};
char graph[MaxEdge][Block] = {
	{'0','A','B','2','5'},
	{'0','A','C','3','5'},
	{'0','A','D','4','6'},
	{'0','A','E','-','7'},
	{'0','B','C','6','7'},
	{'0','B','D','-','8'},
	{'0','C','E','-','8'},
	{'0','D','E','-','-'}
	};
void DispArray2D(){
		int i,j;
		printf("   M V1 V2 E1 E2 \n");
		for( i = 0 ; i < MaxEdge ; i++ )
			{
				printf("%d  ",i+1);
				for( j = 0 ; j < Block ; j++ )
					printf("%c  ",graph[i][j]);
				printf("\n");
			}
}
void DispSetOfVertex(){
	int i;
	printf("\nSet of Vertex = {");
	for( i = 0 ; i < MaxNode ; i++ ){
		printf("%c ",NodeName[i]);
		if( i != MaxNode-1 )
			printf(",");
		}
	printf("}\n");
}
void DispSetOfEdge(){
	int i,j;
	printf("\nSet of Edge ={");
	for( i = 0 ; i < MaxEdge ; i++ ){
		printf("(%c,%c),",graph[i][1],graph[i][2]);
		printf("(%c,%c),",graph[i][2],graph[i][1]);
	}
	printf("}\n");
}
int main(){
	printf("GRAPH ADJACENCY MULTI-LIST REPRESENTATION METHOD\n");
	printf("================================================\n");
	DispArray2D();
	DispSetOfVertex();
	DispSetOfEdge();
	getch();
	return 0;
}
