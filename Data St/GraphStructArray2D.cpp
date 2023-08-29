#include <stdio.h>
#include <conio.h>

#define MaxNode 6

int graph[MaxNode][MaxNode]={
	{0,1,1,1,0,0},
	{1,0,1,0,1,0},
	{1,1,0,0,0,0},
	{1,0,0,0,1,1},
	{0,1,0,1,0,0},
	{0,0,0,1,0,0}
	};
char NodeName[MaxNode]={'A','B','C','D','E','F'};

void DispArray2D()
	{
		int i,j;
		printf(" ");
		for( j = 0 ; j <= MaxNode ; j++ )
			printf("%c ",NodeName[j]);
		printf("\n");
		for( i = 0 ; i < MaxNode ; i++ )
			{
				printf("%c ",NodeName[i]);
				for( j = 0 ; j < MaxNode ; j++ )
					printf("%d ",graph[i][j]);
				printf("\n");
			}
	}
void DispSetOfVertex()
	{
		int i;
		printf("\nSet of Vertex = {");
		for( i = 0 ; i < MaxNode ; i++ )
			{
				printf("%c",NodeName[i]);
				if( i != MaxNode-1 )
					printf(",");
			}
		printf("}\n");
	}

void DispSetOfEdge(){
	int i = 0 , j = 0 , n = 0;
	char t1 , t2 , t3 ;
		
		
	scanf("%d",&n);
		
	printf("\nSet of Edge ={");
	
	while(i <MaxNode){
		t1 = NodeName[i] ;
		for(j = 0 ; j < MaxNode ; j++){
			t2 = NodeName[j] ;
			if(graph[i][j] == 1 and NodeName[j] != t1){
				for(int k = 0 ; k < MaxNode ; k++){
					t3 = NodeName[k] ;
					if(graph[j][k] == 1 and NodeName[k] != t2 and NodeName[k] != t1){
						for(int l = 0 ; l < MaxNode ; l++){
							if(graph[k][l] == 1 and NodeName[l] != t3 and NodeName[l] != t2 and NodeName[l] != t1){
								printf ("{%c,%c,%c,%c,%c},",NodeName[i],NodeName[j],NodeName[k],NodeName[l]) ;
							}
						}//end for l
					}
				}//end for k
			}
		}//end j
		i++ ;
	}//end while i
	printf("}\n");
}
	
int main()
	{
		printf("GRAPH (ADJACENCY MATRIX REPRESENTATION METHOD)\n");
		printf("==============================================\n");
		DispArray2D();
		DispSetOfVertex();
		DispSetOfEdge();
		getch();
		return(0);
	}
