#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
	{
		int info;
		struct Node *link;
	};
struct Node *H, *H1, *p, *q;
int i, j, k, n, data;
char ch;
Node *Allocate(){
	struct Node *temp;
	temp = (Node*)malloc(sizeof(Node));
	return(temp);
}
void CreateNNode(int n){
	int i, temp;
	H = NULL; H1 = NULL;
	for( i = 1 ; i <= n ; i++ ){
		p = Allocate();
		temp = 1+rand()%99;
		p->info = temp;
		if( i == 1 )
			H = p;
		else 
			H1->link = p;
		H1 = p;
		H1->link = NULL;
	}
}
void ShowAllNode(){
	printf("H = %x\n",H);
	p = H;
	i = 1;
	while(p != NULL){
		printf("%d:%x\t",i,p);
		printf("INFO : %d\t",p->info);
		printf("LINK : %x\n",p->link);
		p = p->link;
		i++;
	}
}
void InsertAfter(int data1){
	int temp;
	if(H == NULL)
		printf("Linked List have no node!!..\n");
	else{
		H1 = H;
		while(H1 != NULL){
			if(H1->info == data1){
				p = Allocate();
				printf("\nAllocate data : ");
				scanf("%d",&temp);
				p->info = temp;
				p->link = H1->link;
				H1->link = p;
			}
		H1 = H1->link;
		}
	}
}
void DeleteAfter(int data1){
	if(H == NULL)
		printf("Linked List have no node!!..\n");
	else{
		H1 = H;
		while(H1 != NULL){
			if(H1->info == data1){
				if(H1->link == NULL)
					printf("No more node from here,Can't delete it!!..\n");
				else{
					p = H1->link;
					if(p->link==NULL)
						H1->link = NULL;
					else
						H1->link = p->link;
						free(p);
				}
			}
		H1 = H1->link;
		}
	}
}
int main(){
	n = 10;
	CreateNNode(n);
	printf("PROGRAM SINGLY LINKED LIST \n");
	printf("===========================\n");
	printf("All Data in Linked List \n");
	ShowAllNode();
	ch = ' ';
	while(ch != 'E'){
		printf("MENU :[I : Insert | D : DELETE | E : EXIT]");
		ch =getch();
		switch(ch){
			case'I':	printf("\nInsert After data : ");
						scanf("%d",&data);
						InsertAfter(data);
						ShowAllNode();
						break;
			case'D':	printf("\nDelete After data : ");
						scanf("%d",&data);
						DeleteAfter(data);
						printf("\nAll Data in Linked List After Delete\n");
						ShowAllNode();
						break;
			
		}
	}
	return (0);
}

