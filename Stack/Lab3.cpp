#include <stdio.h> //use pirintf
#include <conio.h> //use getch
#define Maxstack 6 //set max stack

int stack[Maxstack] ; //use Declare stack 0..5
int x ; //tempolary
int sp = Maxstack ; 
char status = 'N' ; //initial 
char ch ;

void Push (int x)
	{
	if (sp==1)
		{
			printf("!!Over Flow!!") ;
			status='0' ; //status stack over flow
		}
	else
		{
			sp=sp-1 ; //revers
			stack[sp]=x ;
		}
	}
int PoP ( )
	{
	int x ;
	if (sp != Maxstack) //check stack
		{
		x=stack[sp] ; //get data from stack
		sp++ ;
		return(x) ;
		}
	else
		{
		printf("\n!!Under Flow!!\n") ;
		status = 'u' ;//set stack under flow
		}	
	}
void showallstack ( )
	{
	int i ;
	printf(" N : %d\n ",Maxstack-1) ;
	printf("status : %c\n",status) ;
	printf (" sp : %d\n",sp) ;
	for (i=1 ; i<Maxstack ; i++)
		{
	printf("%d:%d ",i ,stack[i]) ;
		}
	printf("\n==================================\n") ;
	}
int main()
	{
	printf("           Stack Program\n") ;
	printf("=====================================\n") ;
	while (status = 'n')
	{
		printf("[1] = Push : 2 = [PoP]") ;
		ch = getch ( ) ;
		switch(ch)
		{
			case '1' :  printf ("\nEnter Number :") ;
						scanf("%d",&x) ;
						
						Push(x) ;
						showallstack ( ) ;
						 break ;
						 
			case '2' :  x = PoP ( ) ;
						printf("\nData :%d\n",x) ;
						
						showallstack ( ) ;
						break ;
		}
	} //end while
	printf("\n") ;
	return (0) ;
}//end main
