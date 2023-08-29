/*Program create Tree structure by "NODE SEQUENCE Method"
Can shows the result when traversaled by
1. Pre Order 
2. In Order 
3. Post Order 
4. Can use for 
5 Level maximum of tree (N=7) 
*/

#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
#include <math.h>
#define MaxNode 100 //Define Max Node of Tree

int N, data[MaxNode] ; //Declare Array for keep data of Tree 
char ch ;
void CreateTreeNS(int n){
	  int i,temp ;
	  for(i=1;i<=n;i++){
	  temp=1+rand()%99 ; //random difference number 1..99
	  data[i]=temp ;
	}
}

void ShowArray( ){
	int i=1 ;
	while(data[i]!=NULL){
		printf("[%i]:%d | ",i,data[i]) ;
		i++ ;
	}
	printf("\n--------------------------------------------------------------------------------------------------------------------\n") ;
}

void ShowTree( ){
	int j, level, start, end ;
	j=1 ;
	level=1 ; // start level 1
	printf("\n") ;
	while(data[j]!=NULL){
		start=pow(2,level)/2 ; //calculate Start node
		end=pow(2,level)-1 ; //calculate End node
		
		for(j=start;j<=end;j++)
			if(data[j]!=NULL){
				switch(level){
					
					case 1 : printf("%40d",data[j]) ;
						break ;
						
					case 2 : if(j==2)
								printf("%20d",data[j]) ;
							else
								printf("%40d",data[j]) ;
						break ;
					
					case 3 : if(j==4)
								printf("%10d",data[j]) ;
							else
								printf("%20d",data[j]) ;
						break ;
						
					case 4 : if(j==8)
								printf("%5d",data[j]) ;
							else
								printf("%10d",data[j]) ;
						break ;	
					
					case 5 : if(j==16)
								printf("%d",data[j]) ;
							else
								printf("%5d",data[j]) ;
						break ;		
				}
			}
		printf("\n\n") ;
		level++ ;
	}
}
void PreOrder(int i){
	int info, lson, rson ;
	info=data[i] ;//Root info 
	if(info!=NULL)//if INFO NOT NULL 
	{ 
		printf("%d:",data[i]) ; //Display INFO 
		lson=2*i ; //Calculate LSON 
		rson=2*i+1 ; //Calculate RSON 
		PreOrder(lson); //Call left Son by PreOrder 
		PreOrder(rson); //Call Right Son by PreOrder
	}
}

void RePreOrder(int i){
	int info, lson, rson ;
	info=data[i] ;//Root info 
	if(info!=NULL)//if INFO NOT NULL 
	{ 
		printf("%d:",data[i]);//Display INFO 
		rson=2*i+1 ; //Calculate RSON 
		lson=2*i ; //Calculate LSON 
		RePreOrder(rson) ; //Call Right Son by RePreOrder
		RePreOrder(lson) ; //Call left Son by RePreOrder 
	}
}

void InOrder(int i){
	int info, lson, rson ; 
	info = data[i] ; //Root info 
	if(info!=NULL){ //if INFO NOT. NULL  
		lson=2*i ; //Calculate LSON 
		rson=2*i+1 ; //Calculate RSON 
		InOrder(lson) ; //Call left Son by InOrder 
		printf("%d:",data[i]);//Display INFO 
		InOrder(rson); //Call Right Son by InOrder
	}
}

void ReInOrder(int i){
	int info, lson, rson ;
	info=data[i] ;//Root info 
	if(info!=NULL)//if INFO NOT NULL 
	{ 
		rson=2*i+1 ; //Calculate RSON 
		lson=2*i ; //Calculate LSON 
		ReInOrder(rson) ; //Call Right Son by ReInOrder
		printf("%d:",data[i]);//Display INFO 
		ReInOrder(lson) ; //Call left Son by ReInOrder 
	}
}

void PostOrder(int i){
	int info, lson, rson ; 
	info = data[i] ; //Root info 
	if(info != NULL){ //if INFO NOT. NULL  
		lson=2*i ; //Calculate LSON 
		rson=2*i+1 ; //Calculate RSON 
		PostOrder(lson) ; //Call left Son by PostOrder 
		PostOrder(rson); //Call Right Son by PostOrder
		printf("%d:",data[i]);//Display INFO 
	}
}

void RePostOrder(int i){
	int info, lson, rson ;
	info=data[i] ;//Root info 
	if(info!=NULL)//if INFO NOT NULL 
	{ 
		rson=2*i+1 ; //Calculate RSON 
		lson=2*i ; //Calculate LSON 
		RePostOrder(rson) ; //Call Right Son by RePostOrder 
		RePostOrder(lson) ; //Call left Son by RePostOrder
		printf("%d:",data[i]);//Display INFO
	}
}

int main( ){
	N=7 ;
	CreateTreeNS(N) ;
	while(ch != 'e'){
		printf("\nTree Node Seqience \n") ;
		printf("\n----------------------------------------------------------------------------------------------------------------------\n") ;
		ShowArray( ) ;
		ShowTree( ) ;
		printf("\n Menu P:PreOrder   I:InOrder   O:PostOrder \n") ;
		printf("\n      J:RePreOrder K:ReInOrder L:RePostOrder E:Exit \n") ;
		ch = getch() ;
		printf("\n----------------------------------------------------------------------------------------------------------------------\n") ;
		
		switch(ch)
		{
			case 'p' :  ShowTree( ) ;
						printf("Pre Order Traversal :") ;
						PreOrder(1) ;
						printf("\n") ;
						break ;
						
			case 'j' :  ShowTree( ) ;
						printf("Re Pre Order Traversal :") ;
						RePreOrder(1) ;
						printf("\n") ;
						break ;

			case 'i' :  ShowTree( ) ;
						printf("In Order Traversal :") ;
						InOrder(1) ;
						printf("\n") ;
						break ;
			
			case 'k' :  ShowTree( ) ;
						printf("Re In Order Traversal :") ;
						ReInOrder(1) ;
						printf("\n") ;
						break ;
						
			case 'o' :  ShowTree( ) ;
						printf("Post Order Traversal :") ;
						PostOrder(1) ;
						printf("\n") ;
						break ;
						
			case 'l' :  ShowTree( ) ;
						printf("Re Post Order Traversal :") ;
						RePostOrder(1) ;
						printf("\n") ;
						break ;
		}	
	}
	return(0) ;
}
