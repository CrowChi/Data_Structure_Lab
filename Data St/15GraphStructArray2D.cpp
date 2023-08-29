#include <stdio.h>
#include <conio.h>


int DispArray2D(int MaxNode , char NodeName[26])
	{
		
		int graph[MaxNode][MaxNode];
		
		int i,j;
		printf("  ");
		for( j = 0 ; j <= MaxNode -1; j++ )
			printf("%c ",NodeName[j]);
		printf("\n");
		
		for( i = 0 ; i < MaxNode ; i++ )
			{	
				for( j = 0 ; j < MaxNode ; j++ )
				{
					if( i + 1 == j){
					graph[i][j]=1;
					}else{
					graph[i][j]=0;
					}
					
					
				}
			}
		for( i = 0 ; i < MaxNode ; i++ )
			{
			
				printf("%c ",NodeName[i]);
				
				for( j = 0 ; j < MaxNode ; j++ )
				{
					
				
					printf("%d ",graph[i][j]);
				
				}
			printf("\n");
			}
					
//		DispSetOfEdge(MaxNode , NodeName, graph[MaxNode][MaxNode]);	
				
}
			
			
			
			
	


void DispSetOfVertex( int MaxNode , char NodeName[26])
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
void DispSetOfEdge(int MaxNode , char NodeName[26] )
	{
		
		int graph[MaxNode][MaxNode];
		
		int i,j;
		
		
			for( i = 0 ; i < MaxNode ; i++ )
			{	
				for( j = 0 ; j < MaxNode ; j++ )
				{
					if( i + 1 == j){
					graph[i][j]=1;
					}else{
					graph[i][j]=0;
					}
					
					
				}
			}
		printf("\nSet of Edge ={");
		for( i = 0 ; i < MaxNode ; i++ )
			for( j = 0 ; j < MaxNode ; j++ )
				{
					if( graph[i][j] == 1 )
						printf("(%c,%c),",NodeName[i],NodeName[j]);
				}
				printf("}\n");
	}


int main()
	{
		
		
		int MaxNode ;
		printf("GRAPH (ADJACENCY MATRIX REPRESENTATION METHOD)\n");
		printf("==============================================\n");
		
		
		printf("Input Node : ");
		scanf("%d",&MaxNode);
		
		
		
		
		char NodeName[MaxNode];
		for(int i = 0 ; i <= MaxNode - 1 ; i ++)
		{
			NodeName[i] = 65 + i ;			
		}
		
	
				
		
		DispArray2D( MaxNode , NodeName);	
		DispSetOfVertex( MaxNode , NodeName );
		DispSetOfEdge( MaxNode , NodeName );
		getch();
		return(0);
	}
