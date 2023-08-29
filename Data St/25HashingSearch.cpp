#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MaxData 100
#define Lo 1

int Data[MaxData];
int N,M,key,Addr,Times;
bool result;
struct Node{
	int info;
	struct Node*link;
};
struct Node*Start[MaxData],*H1,*p,*H;

Node*Allocate(){
	struct Node*temp;
	temp = (Node*)malloc(sizeof(Node));
	return(temp);
}
bool Duplicate(int i,int Data1){
	int j;
	for( j = 1 ; j <= i ; j++ )
		if(Data1 == Data[j])
			return(true);
	return(false);
}
void PrepareRawKey( int N ){
	int i,temp;
	srand(time(NULL));
	for( i = 0 ; i <= N ; i++ ){
		temp = (rand()%9899999)+10000000;
		while(Duplicate(i-1,temp))
			temp = (rand()%9899999)+10000000;
		Data[i] = temp;
	}
}
void DispKey( int N ){
	int i;
	for( i = 0 ; i < N ; i++ )
		printf("%2d ",Data[i]);
	printf("\n");
}
void CreateHead( int Head ){
	int i;
	struct Node*p;
	for( i = 1 ; i <= Head ; i++ ){
		p = Allocate();
		p->info = NULL;
		p->link = NULL;
		Start[i] = p;
	}
}
void CreateHashTable( int N ){
	int i;
	struct Node *H1,*p;
	for( i = 0 ; i < N ; i++ ){
		Addr = Data[i]%M+Lo;
		
		H1 = Start[Addr];
		if( H1->info == NULL )
			H1->info = Data[i];
		else{
			while( H1->link != NULL )
				H1 = H1->link;
			p = Allocate();
			p->info = Data[i];
			p->link = NULL;
			H1->link = p;
		}
	}
}
void DispHashTable(){
	int i;
	struct Node*H1;
	for( i = 1 ; i <= M ; i++ ){
		H1 = Start[i];
		printf("\nAddress %2d : ",i);
		while( H1 != NULL ){
			printf("%3d ",H1->info);
			H1 = H1->link;
		}
	}
	printf("\n");
}
bool SearchHash( int key ){
	int temp;
	struct Node*H1;
	struct Node*H ; 
	Addr = key%M+Lo;
	H    = Start[Addr];
	H1   =  H;
	Times = 0;
	while( H1 != NULL ){
		Times++;
		if( H1->info == key ){
			
			temp       = H  -> info ;
			H  -> info = H1 -> info ;
			H1 -> info = temp ; 
				
			return(true);


	}
		else
			H1 = H1->link;
	}
	return(false);
}
int main(){
	printf("HASHING SEARCH(DYNAMIC CHAINING)\n");
	printf("======================================\n");
	N = 32;
	M = N*0.50;
	PrepareRawKey(N);
	printf("Raw key :\n");
	DispKey(N);
	printf("======================================\n");
	CreateHead(M);
	CreateHashTable(N);
	while( key != -999 ){
		DispHashTable();
		printf("======================================\n");
		printf("\nEnter key for Search(-999 for EXIT)=");
		scanf("%d",&key);
		if( key != -999 ){
			result = SearchHash( key );
			printf("Key Address : %d\n",Addr);
			printf("Searching Time : %d\n",Times);
			printf("Result....");
			if(result)
				printf("FOUND\n");
			else{
				Beep(600,600);
				printf("NOT FOUND!!\n");
			}
			printf("--------------------------Searching Finished\n");
		}
	}
	return(0);
}
