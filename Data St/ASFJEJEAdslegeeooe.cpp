#include <stdio.h>
#include <conio.h>

#define MaxNode 6

int Z;
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
void DispSetOfEdge4(){
	int i = 0 , j = 0 ;
	char t1 , t2 , t3 ,t4 ,t5;
	printf("\nSet of Edge ={");
	while(i < MaxNode){
		t1 = NodeName[i] ;
		for(j = 0 ; j < MaxNode ; j++){
			t2 = NodeName[j] ;
			if(graph[i][j] == 1 and NodeName[j] != t1){
				for(int k = 0 ; k < MaxNode ; k++){
					t3 = NodeName[k] ;
					if(graph[j][k] == 1 and NodeName[k] != t2 and NodeName[k] != t1){
						for(int l = 0 ; l < MaxNode ; l++){
							t4 = NodeName[l] ;
							if(graph[k][l] == 1 and NodeName[l] != t3 and NodeName[l] != t2 and NodeName[l] != t1){
								for(int m = 0 ; m < MaxNode ; m++){
									t5 = NodeName[m] ;
									if(graph[l][m] == 1 and NodeName[m] != t4 and NodeName[m] != t3 and NodeName[m] != t2 and NodeName[m] != t1){
										for(int n = 0 ; n < MaxNode ; n++){
											if(graph[m][n] == 1 and NodeName[n] != t5 and NodeName[n] != t4 and NodeName[n] != t3 and NodeName[n] != t2 and NodeName[n] != t1){
												printf ("{%c,%c,%c,%c,%c,%c},",NodeName[i],NodeName[j],NodeName[k],NodeName[l],NodeName[m],NodeName[n]) ;
											}
										}
									}
								}
							}
						}
					}
				}
			}	
		}
		i++ ;
	}
	printf("}\n");
}
void DispSetOfEdge3(){
	int i = 0 , j = 0 ;
	char t1 , t2 , t3 ,t4;
	printf("\nSet of Edge ={");
	while(i < MaxNode){
		t1 = NodeName[i] ;
		for(j = 0 ; j < MaxNode ; j++){
			t2 = NodeName[j] ;
			if(graph[i][j] == 1 and NodeName[j] != t1){
				for(int k = 0 ; k < MaxNode ; k++){
					t3 = NodeName[k] ;
					if(graph[j][k] == 1 and NodeName[k] != t2 and NodeName[k] != t1){
						for(int l = 0 ; l < MaxNode ; l++){
							t4 = NodeName[l] ;
							if(graph[k][l] == 1 and NodeName[l] != t3 and NodeName[l] != t2 and NodeName[l] != t1){
								for(int m = 0 ; m < MaxNode ; m++){
									if(graph[l][m] == 1 and NodeName[m] != t4 and NodeName[m] != t3 and NodeName[m] != t2 and NodeName[m] != t1){
										printf ("{%c,%c,%c,%c,%c},",NodeName[i],NodeName[j],NodeName[k],NodeName[l],NodeName[m]) ;
									}
								}
							}
						}
					}
				}
			}	
		}
		i++ ;
	}
	printf("}\n");
}
void DispSetOfEdge2(){
	int i = 0 , j = 0 ;
	char t1 , t2 , t3 ;
	printf("\nSet of Edge ={");
	while(i < MaxNode){
		t1 = NodeName[i] ;
		for(j = 0 ; j < MaxNode ; j++){
			t2 = NodeName[j] ;
			if(graph[i][j] == 1 and NodeName[j] != t1){
				for(int k = 0 ; k < MaxNode ; k++){
					t3 = NodeName[k] ;
					if(graph[j][k] == 1 and NodeName[k] != t2 and NodeName[k] != t1){
						for(int l = 0 ; l < MaxNode ; l++){
							if(graph[k][l] == 1 and NodeName[l] != t3 and NodeName[l] != t2 and NodeName[l] != t1){
								printf ("{%c,%c,%c,%c},",NodeName[i],NodeName[j],NodeName[k],NodeName[l]) ;
							}
						}
					}
				}
			}
		}
		i++ ;
	}
	printf("}\n");
}
	
void DispSetOfEdge1(){
	int i = 0 , j = 0 ;
	char t1 , t2 , t3 ;
	printf("\nSet of Edge ={");
	while(i < MaxNode){
		t1 = NodeName[i] ;
		for(j = 0 ; j < MaxNode ; j++){
			t2 = NodeName[j] ;
			if(graph[i][j] == 1 and NodeName[j] != t1){
				for(int k = 0 ; k < MaxNode ; k++){
					t3 = NodeName[k] ;
					if(graph[j][k] == 1 and NodeName[k] != t2 and NodeName[k] != t1){
						printf ("{%c,%c,%c},",NodeName[i],NodeName[j],NodeName[k]) ;
	
						
					}
				}
			}
		}
		i++ ;
	}
	printf("}\n");
}	


void  scan(){
	printf("Enter number = ");
	scanf("%d",&Z);
	
}
int main()
	{
		printf("GRAPH (ADJACENCY MATRIX REPRESENTATION METHOD)\n");
		printf("==============================================\n");
		DispArray2D();
		DispSetOfVertex();
		scan();
		if(Z==4){
			DispSetOfEdge4();
		}
		if(Z==3){
			DispSetOfEdge3();
		}
		if(Z==2){
			DispSetOfEdge2();
		}	
		if(Z==1){
			DispSetOfEdge1();
		}
		if(Z<1||Z>4){
			printf("\nError\n");
		}
		getch();
		return(0);
	}
