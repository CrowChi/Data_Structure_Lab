#include<stdio.h>
int Pow(int m ,int n){  
    if ( n == 0 )  //Base Criteria
        return( 1 );
    else
        return(m * Pow ( m , n-1 ));  } //Recursive 
main(){
	int  m , n ;
    scanf("%d %d",&m,&n);
    printf("ans : %d",Pow(m,n));   }
