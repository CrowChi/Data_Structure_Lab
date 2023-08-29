#include<stdio.h>  //use printf
#include<conio.h>  //use getch
#include<stdlib.h> //use random
#include<time.h>   //use time
#include<windows.h>//use sound

#define MaxData 100
#define Lo 1 //define Lo=1

int Data[MaxData];
int N,M,key,Addr,Times;
bool result ;

struct Node//declear structure of node
{
	int info ;
	struct Node*link;
};

struct Node*Start[MaxData],*H1,*p;//declear pointer node

Node*Allocate()//allocate 1 node from storage pool
{
	struct Node*temp;
	temp = (Node*)malloc(sizeof(Node)) ;
	return (temp);
}

bool Duplicate(int i,int Data1)//check duplication data
{
	int j;
	for(j=0;j<=i;j++)
		if(Data1==Data[j])
			return(true);
		return(false);
}

void PrepareRawKey(int N)
{
	int i,j,temp;
	srand(time(NULL));//for differance number in rand()
	for(i=0; i<N; i++)
	{
		temp=(rand()%990)+9;//10..99
		while(Duplicate(i-1,temp))//loop if stil duplicate
			temp=(rand()%990)+9;//random again
			Data[i]=temp ;//keep new number
	}		
}

void DispKey(int N)
{
	int i;
	struct Node*p;
	for(i=1; i<N; i++)
		printf("%2d ",Data[i]);//show data that addr i
	printf("\n");
}

void CreateHead(int Head)
{
	int i ;
	struct Node*p;
	for(i=1; i<=Head; i++)//count by number of head
	{
		p=Allocate();
		p->info=NULL;//let info = null
		p->link=NULL;//let next=null
		Start[i]=p;//let start first node
	}
}

void CreateHashTable(int N)
{
	int i;
	struct Node*H1 ,*p;
	for(i=0; i<N; i++)
	{
		Addr = Data[i]%M+Lo;//cal addr of key addr=Kmod M+10
		H1=Start[Addr];//h1 shee start[addr]
		if(H1->info == NULL)//if head node
			H1->info=Data[i];//data addr i save in info's h1 shee
		else 
		{
			while (H1->link!=NULL)
				H1=H1->link;//shee next until = null
			p=Allocate();//add new node that p shee
			p->info=Data[i];//info that p shee save data addr i
			p->link=NULL;//link's p shee = null
			H1->link=p;//link's h1 shee p
		}
	}
}

void DispHashTable()
{
	int i,j;
	struct Node*H1;
	for(i=1; i<=M;i++)
	{
		H1=Start[i];//h1 shee start addr i
		printf("\n Address %2d : ",i);
		while(H1!=NULL)//not null do below
		{
			printf("%3d ",H1->info);//show legg that info's h1 shee
			H1=H1->link ;//skip next node
		}
	}
	printf("\n");
}

bool SearchHash(int key)
 {
 	struct Node*H1;
 	Addr=key%M+Lo;//cal addr of key
 	H1=Start[Addr];//h1 shee start addr taht addr
 	Times = 0;
 	while(H1!=NULL)//not null do below
 	{
 		Times++;//add counter times
 		if(H1->info==key)//if info's h1 shee = key
 			return(true);//found
 		else//!=
 			H1=H1->link;//skip next node
	 }
	 return (false);//not found
 }
 
 int main()
 {
 	printf("HAHING SEARCH(DYNAMIC) CHAINING\n");
 	printf("_________________________________________\n");
 	N=80;
 	M=N*0.2;
 	PrepareRawKey(N); 
 	printf(">>>Raw key : \n");
 	DispKey(N);//raw key
 	printf("__________________________________________\n");
 	CreateHead(M);//creat head node
 	CreateHashTable(N);
	while(key!=-999)
 	{
 		DispHashTable();
 		printf("____________________________________\n");
 		printf("Enter key for Search(-999 for EXIT)==");
 		scanf("%d",&key);//read key from KBD
 		if(key !=-999)
 		{
 			result = SearchHash(key);
 			printf("key Address : %d \n",Addr);
 			printf("Searchiing Time :%d\n ", Times);
 			printf("Result....\n");
 			if(result)
 				printf(">>FOUND\n");//if found
 			else 
 				{
 					Beep(600,600);
 					printf(">>>NOT FOUND!!!!\n");//if not found
				 }
				 printf("______________________________-Searching Finished\n");
		 }
	 }
 	return 0 ;
 }
