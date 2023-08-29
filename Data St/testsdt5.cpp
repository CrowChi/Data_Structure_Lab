#include <stdio.h>
#include <conio.h>

#define MaxNode 6

#define A  0
#define	B  1
#define	C  2
#define	D  3
#define	E  4
#define	F  5

int graph[MaxNode][MaxNode]={
	{0,1,1,1,0,0},
	{1,0,1,0,1,0},
	{1,1,0,0,0,0},
	{1,0,0,0,1,1},
	{0,1,0,1,0,0},
	{0,0,0,1,0,0}
	};
char NodeName[MaxNode]={'A','B','C','D','E','F'};
char s , e ;
int w ;

void DispArray2D()
	{
		int i,j;
		printf("  ");
		for( j = 0 ; j <= MaxNode ; j++ )
			printf("%c ",NodeName[j]);
		printf("\n");
		for( i = 0 ; i < MaxNode; i++ )
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
void DispSetOfEdge()
	{
		int i,j;
		printf("\nSet of Edge ={");
		
		
	
		
		if(e>s){
		for( i = 0 ; i < s-e+1 ; i++ )
			for( j = 0 ; j < MaxNode ; j++ )
				{
					if( graph[i][j] == 1 )
						printf("(%c,%c),",NodeName[i],NodeName[j]);
				}
				printf("}\n");
		}else{
			for( i = 0 ; i < e-s+1 ; i++ )
				for( j = 0 ; j < MaxNode ; j++ )
				{
					if( graph[i][j] == 1 )
						printf("(%c,%c),",NodeName[i],NodeName[j]);
				}
				printf("}\n");
			
		}
				
	}
	
	void scan(){
		
		printf("Input Start : ");
		s=getche();
		
		printf("\nInput End : ");
		e=getche();
		
		
		
	}

	
	
int main()
	{
		printf("GRAPH (ADJACENCY MATRIX REPRESENTATION METHOD)\n");
		printf("==============================================\n");
		
		
		scan();
		
		
		printf("\n");	
		DispArray2D();
	//	DispSetOfVertex();
		DispSetOfEdge();
		getch();
		return(0);
	}