#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <math.h>
#define MaxNode 40//Define Max Node of Tree

struct Node {
	int info ; 
	struct Node *lson ;
	struct Node *rson ;
};

struct Node *T ,*address[MaxNode] ;
int    i  ,N ,info[MaxNode] ;
char   ch ;

Node *Allocate() {
	struct Node *temp ;
	temp = (Node*)malloc(sizeof(Node));
	return(temp) ;
}

void CreateTreeNP(int n){
	int i, temp, Father ;
	struct Node * p, *FatherPT ;
	T = NULL ;
	for(i=1;i<=n;i++){
		p=Allocate() ; //node p
		temp=1+rand()%99 ; //rendom 1-99
		info[i]=temp ;
		address[i]=p ;
		p->info=temp ;
		p->lson=NULL ;
		p->rson=NULL ;
		if(T==NULL){ //chack T=null ?
			T=p ;
		}
		else{
			Father=(i/2) ;
			FatherPT=address[Father] ;
			if(FatherPT->lson==NULL)
				FatherPT->lson=p ;
			else
				FatherPT->rson=p ;
		}
	}
}

void ShowTree( ){
	int j, level, start, end ;
	j=1 ;
	level=1 ; // start level 1
	printf("\n") ;
	while(info[j]!=NULL){
		start=pow(2,level)/2 ; //calculate Start node
		end=pow(2,level)-1 ; //calculate End node
		
		for(j=start;j<=end;j++)
			if(info[j]!=NULL){
				switch(level){
					
					case 1 : printf("%40d",info[j]) ;
						break ;
						
					case 2 : if(j==2)
								printf("%20d",info[j]) ;
							else
								printf("%40d",info[j]) ;
						break ;
					
					case 3 : if(j==4)
								printf("%10d",info[j]) ;
							else
								printf("%20d",info[j]) ;
						break ;
						
					case 4 : if(j==8)
								printf("%5d",info[j]) ;
							else
								printf("%10d",info[j]) ;
						break ;	
					
					case 5 : if(j==16)
								printf("%d",info[j]) ;
							else
								printf("%5d",info[j]) ;
						break ;		
				}
			}
		printf("\n\n") ;
		level++ ;
	}
}

void PreOrder(struct Node*i){
	if(i!=NULL)//if INFO NOT NULL 
	{ 
		printf("%d:",i->info) ; //Display INFO  
		PreOrder(i->lson); //Call left Son by PreOrder 
		PreOrder(i->rson); //Call Right Son by PreOrder
	}
}

void InOrder(struct Node*i){
	if(i!=NULL)//if INFO NOT NULL 
	{ 
		InOrder(i->lson); //Call left Son by InOrder 
		printf("%d:",i->info) ; //Display INFO  
		InOrder(i->rson); //Call Right Son by InOrder
	}
}

void PostOrder(struct Node*i){
	if(i!=NULL)//if INFO NOT NULL 
	{ 	
		PostOrder(i->lson); //Call left Son by PostOrder   
		PostOrder(i->rson); //Call Right Son by PostOrder
		printf("%d:",i->info) ; //Display INFO
	}
} 

void RePreOrder(struct Node*i){
	if(i!=NULL)//if INFO NOT NULL 
	{ 
		printf("%d:",i->info) ; //Display INFO  
		RePreOrder(i->lson); //Call left Son by RePreOrder 
		RePreOrder(i->rson); //Call Right Son by RePreOrder
	}
}

void ReInOrder(struct Node*i){
	if(i!=NULL)//if INFO NOT NULL 
	{ 
		ReInOrder(i->rson); //Call Right Son by ReInOrder
		printf("%d:",i->info) ; //Display INFO  
		ReInOrder(i->lson); //Call left Son by ReInOrder 
	}
}

void RePostOrder(struct Node*i){
	if(i!=NULL)//if INFO NOT NULL 
	{ 	
		RePostOrder(i->rson); //Call Right Son by RePostOrder
		RePostOrder(i->lson); //Call left Son by RePostOrder   
		printf("%d:",i->info) ; //Display INFO
	}
}

int main( ){
	N=7 ;
	CreateTreeNP(N) ;
	while(ch != 'e'){
		printf("\nTree Node Pointer \n") ;
		printf("\n----------------------------------------------------------------------------------------------------------------------\n") ;
		printf("N :%d\n",N) ;
		printf("Sequence Of Data :") ;
		for(i=1;i<=N;i++)
		printf("%d :",info[i]) ;
		ShowTree() ;
		printf("\n Menu P:PreOrder I:InOrder O:PostOrder J:RePreOrder K:ReInOrder L:RePostOrder E:Exit  \n") ;

		ch = getch() ;
		printf("\n----------------------------------------------------------------------------------------------------------------------\n") ;
		
		switch(ch)
		{
			case 'p' :  printf("Pre Order Traversal :") ;
						PreOrder(T) ;
						printf("\n") ;
						break ;

			case 'i' :  printf("In Order Traversal :") ;
						InOrder(T) ;
						printf("\n") ;
						break ;
			
			case 'o' :  printf("Post Order Traversal :") ;
						PostOrder(T) ;
						printf("\n") ;
						break ;
						
			case 'j' :  printf("Re Pre Order Traversal :") ;
						RePreOrder(T) ;
						printf("\n") ;
						break ;

			case 'k' :  printf("Re In Order Traversal :") ;
						ReInOrder(T) ;
						printf("\n") ;
						break ;
			
			case 'l' :  printf("Re Post Order Traversal :") ;
						RePostOrder(T) ;
						printf("\n") ;
						break ;
		}	
	}
	return(0) ;
}
