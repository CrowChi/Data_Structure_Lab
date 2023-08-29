#include<stdio.h>	// use printf
#include<conio.h>	// use getch

int Number,ans;

int Factorial(int N) //Factorial Function
{
	int x,y;
	if(N == 0)
	{
		printf("------------------------------------------------------\n");
		printf(". . . Roll Back Point . . . \n");
		printf("------------------------------------------------------\n");
		return(1);
	}
	else
	{
		x = N-1;
		printf("%2d!=%2d*%2d!\n",N,N,x);  //Display Before Recursive
		y = Factorial(x);
		printf("%2d!=%2d*%2d =%5d\n",N,N,y,y*N);  //Display After Recursive
		return(N*y);
	}	
} //END Fn. Factorial

int main()
{
	printf("RECURSIVE(FACTORIAL)PROGRAM\n");
	printf("==================================\n");
	// N = 0 ;
	while(Number!=-999)
	{
		printf("Enter Number (-999 is End) = ");
		scanf("%d",&Number);
		printf("==================================\n");
		if(Number>=0)
		{
			printf("N!=N(N-1)!\n");
			printf("==========\n");
			ans = Factorial(Number); // Recursive it self
			printf("=============================\n");
			printf("Answer N!=%d======Finsihed\n",ans);
			printf("=============================\n");
			getch();
		} // End if
	} //End while
	return(0);
} //End main
