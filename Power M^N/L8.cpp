#include<stdio.h> //use printf

int  power(int m,int n){
	int x , y ;
	if(n==0){
		printf( "...............Roll Back Point\n" ) ;
		return (1);	//back Y
	}
	else
		x=n-1;
		printf( "%d^%d = %d * %d^%d\n" , m , n , m , m , x ) ;
		
		y=power(m,x);//Power
		printf( "%d^%d = %d * %d = %d\n" , m , n , m , y , m * y ) ;
		return (m*y);//m*Power
	}

int main(){
	int m , n , x ;
	printf("M : ");
	scanf(" %d",&m);
	
	printf("N : ");
	scanf(" %d",&n);
	
	printf( "===========================\n" ) ;
	printf("M^N = M * M^(N-1)\n");
	printf( "===========================\n" ) ;
	
	x = power(m,n);//Answer
	printf( "===========================\n" ) ;
	printf("Answer = %d",x);
return 0;
}//End 
