#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MaxNode 40



char name[20];
/// revetpost	


//Chanakarn-Prasansuk
//kuas-kananranhCasrP

struct Node
	{
		int info;
		struct Node *lson;
		struct Node *rson;
	};
struct Node *T, *address[MaxNode];
int i, N, info[MaxNode];
char ch;



Node *Allocate()
	{
		struct Node *temp;
		temp = (Node*)malloc(sizeof(Node));
		return (temp);
	}
	
	
	
void CreateTreeNP(int n)
	{
		int i, temp ;
		int  Father;
		struct Node *p, *FatherPT;
		int a[999]={2,3,4,5};
		T = NULL;
		for( i = 1 ; i <= n ; i++ )
			{
				p = Allocate();
				temp = name[i-1];
				info[i] = temp;
				address[i] = p;
				p->info = temp;
				p->lson = NULL;
				p->rson = NULL;
				if( T == NULL )
					{
						T = p;
					}
				else
					{
						Father = (i/2);
						FatherPT = address[Father];
						if( FatherPT->lson == NULL )
								FatherPT->lson = p;
						else
								FatherPT->rson = p;
					}
			}
	}
void ShowTree()
	{
		int j, level, start, ends;
		j = 1;
		level = 1;
		printf("\n");
		while( info[j] != NULL )
			{
				start = pow(2,level)/2;
				ends = pow(2,level)-1;
				for( j = start ; j <= ends ; j++ )
					if( info[j] != NULL )
						{
							switch( level )
								{
									case 1 :printf("%40c",info[j]);
											break;
									case 2 :if( j == 2 )
												printf("%20c",info[j]);
											else
												printf("%40c",info[j]);
											break;
									case 3 :if( j == 4 )
												printf("%10c",info[j]);
											else
												printf("%20c",info[j]);
											break;
									case 4 :if( j == 8 )
												printf("%5c",info[j]);
											else
												printf("%10c",info[j]);
											break;
									case 5 :if( j == 16 )
												printf("%c",info[j]);
											else
												printf("%5c",info[j]);
											break;
								}	
						}	
			printf("\n");
			level++;
			}
	}
void sort (int info[MaxNode]) {
	int i , j ,temp = 0 ;
	for(i = 1 ; i <= N ; i++) {
		for(j = 1 ; j <= N ; j++) {
			if(info[i] >= info[j]) {
				temp = info[i]  ;
				info[i] = info[j] ;
				info[j] = temp ;
			}
		}
	}	
}


void RevertPostOrder( struct Node *i )
	{
		if( i != NULL )
			
			{
			
				RevertPostOrder(i->rson);
			
				RevertPostOrder(i->lson);
			
				printf("%c ",i->info);
			
			
			}
			
			
	}


int main()
	{
		printf("\nPROGRAM TREE(NODE Pointer)\n");
		printf("==========k==================\n");
		
		printf("Input your name : ");
		scanf("%s",&name);
		N = strlen(name);
		CreateTreeNP(N);
		
		
		while( ch != 'E')
			{
			
				printf("N : %d \n",N);
				for( i = 1 ; i <= N ; i++ )
					printf("%c ",info[i]);
				ShowTree();
				printf("\nMENU >> | O : RevertPostOrder | E : Exit \n");
				printf("\n--------------------------------\n");
				ch = getch();
				switch(ch)
					{
									
						case 'O':	printf("REVERT POST ORDER TRAVERSAL : ");
									RevertPostOrder(T);
									printf("\n----------------------------------\n");
									break;
					}
					getch();
			}
	}
