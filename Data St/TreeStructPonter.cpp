#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MaxNode 40

struct Node
	{
		int Info;
		struct Node *lson;
		struct Node *rson;
	};
struct Node *T, *address[MaxNode];
int i, N;
char ch,namescan[100],name[100], info[MaxNode];

Node *Allocate()
	{
		struct Node *temp;
		temp = (Node*)malloc(sizeof(Node));
		return (temp);
	}
void CreateTreeNP(int n)
	{
		int i, temp, Father;
		struct Node *p, *FatherPT;
		T = NULL;
		for( i = 1 ; i <= n ; i++ )
			{
				p = Allocate();
				strcpy(info,name);
				address[i] = p;
				temp = name[i];
				p->Info = temp;
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
void PreOrder(struct Node *i)
	{
		if( i != NULL )
			{
				printf("%c ",i->Info);
				PreOrder(i->lson);
				PreOrder(i->rson);	
			}
	}
void ReversePreOrder(struct Node *i)
	{
		if( i != NULL )
			{
				printf("%c ",i->Info);
				ReversePreOrder(i->rson);
				ReversePreOrder(i->lson);
			}
	}
void InOrder(struct Node *i )
	{
		if( i != NULL )
			{
				InOrder(i->lson);
				printf("%c ",i->Info);
				InOrder(i->rson);
			}
	}
void ReverseInOrder(struct Node *i )
	{
		if( i != NULL )
			{
				ReverseInOrder(i->rson);
				printf("%c ",i->Info);
				ReverseInOrder(i->lson);
			}
	}
void PostOrder( struct Node *i )
	{
		if( i != NULL )
			{
				PostOrder(i->lson);
				PostOrder(i->rson);
				printf("%c ",i->Info);
			}
	}
void ReversePostOrder(struct Node *i )
	{
		if( i != NULL )
			{
				ReverseInOrder(i->rson);
				ReverseInOrder(i->lson);
				printf("%c ",i->Info);	
			}
	}
int scanname(){
	int lene,k;
	printf("%s","Enter Your Name : ");
	scanf("%s",namescan);
	lene = strlen(namescan);
	name[0]=' ';
	name[15]=namescan[0];
	name[7]=namescan[1];
	name[14]=namescan[2];
	name[3]=namescan[3];
	name[13]=namescan[4];
	name[6]=namescan[5];
	name[12]=namescan[6];
	name[1]=namescan[7];
	name[11]=namescan[8];
	name[5]=namescan[9];
	name[10]=namescan[10];
	name[2]=namescan[11];
	name[9]=namescan[12];
	name[4]=namescan[13];
	name[8]=namescan[14];
	return lene;	
}

int main()
	{
		N = scanname();
		CreateTreeNP(N);
		while( ch != 'E')
			{
				printf("\nPROGRAM TREE(NODE Pointer)\n");
				printf("============================\n");
				printf("N : %d \n",N);
				for( i = 0 ; i <= N ; i++ )
					printf("%c ",name[i]);
				ShowTree();
				printf("\nMENU >> %-20s %-20s %-20s\n\t%-20s %-20s %-20s \n\t%-20s ","P : PreOrder","|I : InOrder","|O : PostOrder ","1 : ReversePreOrder", "|2 : ReverseInOrder","|3 : ReversePostOrder","E : Exit");
				printf("\n--------------------------------\n");
				ch = getch();
				switch(ch)
					{
						case 'P':	printf("PRE ORDER TRAVERSAL : ");
									PreOrder(T);
									printf("\n----------------------------------\n");
									break;
						case 'I':	printf("IN ORDER TRAVERSAL : ");
									InOrder(T);
									printf("\n----------------------------------\n");
									break;
						case 'O':	printf("POST ORDER TRAVERSAL : ");
									PostOrder(T);
									printf("\n----------------------------------\n");
									break;
						case '1':	printf("REVERSE PRE ORDER TRAVERSAL : ");
									ReversePreOrder(T) ;
									printf("\n----------------------------------\n");
									break;
						case '2':	printf("REVERSE In ORDER TRAVERSAL : ");
									ReverseInOrder(T) ;
									printf("\n----------------------------------\n");
									break;
						case '3':	printf("REVERSE Post ORDER TRAVERSAL : ");
									ReversePostOrder(T) ;
									printf("\n----------------------------------\n");
									break;
					}
			}
	}
