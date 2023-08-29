#include <stdio.h> // use printf
#include <conio.h> // use getch

#define N 5//set max Q

int Q[N] ;//perpare Q 0..N-1
int x, F=0, R=0 ; //intial front/rear
char status ='N' ;//status Narmol
char ch ; //KBD read

void insertQ(int y)//insert function
	{
		if(R==N-1)
		{
			printf("!!!Over Flow!!!\n") ;
			status = 'O' ;
		}
		else
		{
			R=R++ ;
		if(F==0)
		{
			F++ ;
		}
		Q[R]=y ; //put data into
		}
	}

int deleteQ ( ) //delete functoin
	{
	int y ;
	if (F!=0) //check Q
	{
		y=Q[F] ;
		if(F==R)
		{
			F=0 ; R=0 ;
		}
		else
			F++ ;
		return(y) ;
	}
		else
		{
			printf ("\n!!!!!!Under FloW!!!!\n") ;
			status = 'U' ;
		}
	}
void ShowAllQueue ( )//display function
	{
		int i ;
		printf("N : %d\n",N-1) ;
		printf("STATUS : %c\n",status) ;
		printf("F : %d R : %d\n",F,R) ;
		for (i=1 ; i<N ; i++)
		{
			printf("%d : %d /",i,Q[i]) ;
		}
			printf("\n============================================\n") ;
	}
int main ( )
	{
		printf("QUEUE PROGRAM\n") ;
		printf("\n----------------\n") ;
		while (status = 'N')
			{
				printf("[1]=INSERT : [2]=DELETE") ;
				ch = getch ( ) ;
				switch(ch)
				{
					case '1' :	
								printf("\nInsert Number : ") ;
								scanf("%d",&x) ;
								insertQ(x) ;
								ShowAllQueue ( ) ;
								
								break ;
								
					case '2' :  
								x=deleteQ ( ) ;
								printf("\nData From Queue = %d\n",x) ;
								ShowAllQueue ( ) ;
								
								break ;			
				}
				
			}//end while
		printf("\n") ;
		return(0) ;
	}//end main

