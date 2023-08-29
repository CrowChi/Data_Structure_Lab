#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>


#define MaxData 100


int Data[MaxData];
int N,key,Times;
bool result;


struct Node{
	int info;
	struct Node*lson,*rson;//Declare pointer node
};
struct Node*Start[MaxData],*Root,*p ;



Node*Allocate(){
	struct Node*temp;
	temp = (Node*)malloc(sizeof(Node));
	return(temp);
}
bool Duplicate(int i,int Data1){//Check Duplication Data
	int j;
	for( j = 1 ; j <= i ; j++ )
		if( Data1 == Data[j] )
			return(true);
	return(false);
}
void PrepareRawKey(int N){
	int i,temp;
	srand(time(NULL));
	for( i = 0 ; i < N ; i++ ){
		temp = (rand()%89)+10;//random difference number 10..99
		while(Duplicate(i-1,temp))
			temp = (rand()%89)+10;//random again
		Data[i] = temp;
	 }
}
void DispKey(int N){
	int i;
	for( i = 0 ; i < N ; i++ )
		printf("(%2d) ",i);//show Subscript i
	printf("\n");
	for( i = 0 ; i < N ; i++ )
		printf("   %2d ",Data[i]);//Show Data[]
	printf("\n");
}
void CreateBST(int N){
	int i;
	bool Finish;
	struct Node*T1,*p;
	p = Allocate(); //new node
	p->info = Data[0];
	p->lson = NULL;
	p->rson = NULL;
	Root = p;
	for( i = 0 ; i < N ; i++ ){
		T1 = Root;
		p = Allocate();
		p->info = Data[i];
		p->lson = NULL;
		p->rson = NULL;
		Finish = false;
		while(!Finish){
			if(Data[i] > T1->info)//Add left Node
				if(T1->lson == NULL){
					T1->lson = p;
					Finish =true;
				}
				else
					T1 = T1->lson;//Skip to Left Son
			else
				if(T1->rson == NULL){
					T1->rson = p;
					Finish = true;
				}else
					T1 = T1->rson;//Skip to Right Son
		}
	}
}
void InOrder(struct Node*i){
	if(i!=NULL){
		InOrder(i->lson);
		printf("%2d   ",i->info);
		InOrder(i->rson);
	}
}
bool SearchBST(int key){
	struct Node*T1;
	Times=0;
	T1=Root;
	while(T1!=NULL){
		Times++;
		if(key == T1->info)
			return(true);
		else
			if(key > T1->info)
				T1 = T1->lson;
			else
				T1 = T1->rson; 
	}
	return(false);
}
int main(){
	printf("BINARY SEARCH TREE\n");
	printf("------------------------------\n");
	N = 15;
	PrepareRawKey(N);
	CreateBST(N);
	while(key!=-999){
		printf("Raw Key : ");
		DispKey(N);
		printf("------------------------------\n");
		printf("In Order : ");
		InOrder(Root);
		printf("\n------------------------------\n");
		printf("\nEnter Key for Search (-999 for EXIT)=");
		scanf("%d",&key);
		if(key != -999 ){
			result=SearchBST(key);
			printf("Searching Time : %d\n",Times);
			printf("Result...");
			if(result)
				printf("FOUND\n");
			else{
				Beep(600,600);
				printf("NOT FOUND!!\n");
			}
			printf("-------------------------------Searching Finished\n");
			}
		}
		return(0);
}
