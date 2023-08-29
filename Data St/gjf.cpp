#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#define MaxNode 100

int N, data[MaxNode];
char ch;

//char name1[19] = {'r','r','n','n','-','k' ,'h','u','s' ,'P','n','a','a','a','C','k','s','a','a'};
char name[19] ;

void CreateTreeNS(int n)
	{
		int i, temp;
		for( i = 1 ; i <= n ; i++ )
			{
				temp = name[i-1];
				data[i] = temp;
			}
	}
void ShowArray()
	{
		int i = 1;
		while( data[i] != NULL)
			{
				printf("[%i]%c ",i,data[i]);
				i++;
			}
			printf("\n==========================\n");
	}
void ShowTree()
	{
		int j,level,start,ends;
		j = 1;
		level = 1;
		printf("\n");
		while( data[j] != NULL)
			{
				start = pow(2,level)/2;
				ends = pow(2,level)-1;
				for( j = start ; j <= ends ; j++ )
					if( data[j] != NULL )
						{
							switch(level)
								{
									case 1 :	printf("%40c",data[j]);
												break;
									case 2 :	if( j == 2 )
													printf("%20c",data[j]);
												else
													printf("%40c",data[j]);
												break;
									case 3 :	if( j == 4 )
													printf("%10c",data[j]);
												else
													printf("%20c",data[j]);
												break;
									case 4 :	if( j == 8 )
													printf("%5c",data[j]);
												else
													printf("%10c",data[j]);
												break;
									case 5 :	if( j == 16 )
													printf("%c",data[j]);
												else
													printf("%5c",data[j]);
												break;
									
								}
						}
			printf("\n\n");
			level++;
			}
	}

void InOrder(int i)
	{
		int info,lson,rson;
		info = data[i];
		if( info != NULL )
			{

				lson = 2*i;
				rson = 2*i+1;
				InOrder(rson);
				printf("%c ",data[i]);
				InOrder(lson);
			}
	}


	

int main()
	{	
	
		//rrnn-khusPnaaaCksaa
		printf("Input : ");
		scanf("%s",&name);
			
		int value ;
		N =31;
		CreateTreeNS(N);
		while(ch = 'E')
			{
				printf("\nTREE (NODE SEQUENCE)\n");
				printf("\n======================\n");
				ShowArray();
				ShowTree();
				printf("\n MENU >> I : RevertInOrder | E : Exit");
				ch = getch();
				printf("\n======================\n");
				switch(ch)
					{
						
						case 'I':	ShowTree();
									printf("In ORDER TRAVERSAL : ");
									InOrder(1);
									printf("\n");
									break;
						
					}
			}
	}
