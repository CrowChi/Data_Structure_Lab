#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define l 1
#define u 5
#define l1 1
#define u1 3
#define l2 1
#define u2 4
#define l3 1
#define u3 5

int *BA3,*P ;
int i,j,k ;

void Create3DArray()
{
    int element , c , total_mem ;
    element = (u1 - l1 + 1)*(u2 - l2 + 1)*(u3 - l3 + 1) ;
    c = sizeof(*BA3) ;
    total_mem = element * c ;
    BA3 = (int*)malloc(total_mem) ; 
    
}//end function

void A3PCR(int i , int j, int k)
{
    P = BA3 + ((i - l1)*(u2 - l2 +1)*(u3 - l3 +1)+(j - l2)*(u3 - l3 + 1)+(k - l3)) ;
    printf("\nDimention Array Function (PRC) = %x",P); 
    
}//end function

void A3PRC(int i , int j, int k)
{
    P = BA3 + ( i - l1 )*( u2 - l2 + 1 )*( u3 - l3 + 1 )+( k - l3 )*( u2 - l2 + 1 )+( j - l2 ) ;
    printf("\nDimention Array Function (PCR) = %x",P); 
    
}//end function

void A3RPC(int i , int j, int k)
{
    P = BA3 + ( i - l2 )*( u1 - l1 + 1 )*( u3 - l3 + 1 )+( i - l1 )*( u3 - l3 + 1 )+( k - l3 ) ;
    printf("\nDimention Array Function (RPC) = %x",P); 
    
}//end function

void A3RCP(int i , int j, int k)
{
    P = BA3 + ( j - l2 )*( u1 - l1 + 1 )*( u3 - l3 + 1 )+( k - l3 )*( u1 - l1 + 1 )+( i - l1 ) ;
    printf("\nDimention Array Function (RCP) = %x",P); 
    
}//end function

void A3CPR(int i , int j, int k)
{
    P = BA3 + ( k - l3 )*( u1 - l1 + 1 )*( u2 - l2 + 1 )+( i - l1 )*( u2 - l2 + 1 )+( j - l2 ) ;
    printf("\nDimention Array Function (CPR) = %x",P); 
    
}//end function

void A3CRP(int i , int j, int k)
{
    P = BA3 + ( k - l3 )*( u1 - l1 + 1 )*( u2 - l2 + 1 )+( j - l2 )*( u1 - l1 + 1 )+( i - l1 ) ;
    printf("\nDimention Array Function (CRP) = %x",P); 
    
}//end function

int main()
{
    int input = 0 ;
    i = 3 ; j = 4 ; k = 5 ;
    Create3DArray() ;
    printf("Select Calculation Method\n1 : Plane Row Column\n2 : Plane Column Row\n3 : Row Plane Column\n4 : Row Plane Column\n5 : Column Plane Row\n6 : Column Row Plane\n: ") ;
	scanf("%d",&input);
    switch( input ){
        case 1 :
		{
    	printf("Baseaddress = ") ;
    	printf("%x",BA3);
		A3PCR(i,j,k);
    	free(BA3);
    	break;
    	}
    	case 2 :
		{
    	printf("Baseaddress = ") ;
    	printf("%x",BA3);
		A3PRC(i,j,k);
    	free(BA3);
    	break;
		}
		case 3 :
		{
    	printf("Baseaddress = ") ;
    	printf("%x",BA3);
		A3RPC(i,j,k);
    	free(BA3);
    	break;
		}
		case 4 :
		{
    	printf("Baseaddress = ") ;
    	printf("%x",BA3);
		A3RCP(i,j,k);
    	free(BA3);
    	break;
		}
		case 5 :
		{
    	printf("Baseaddress = ") ;
    	printf("%x",BA3);
		A3CPR(i,j,k);
    	free(BA3);
    	break;
		}
		case 6 :
		{
    	printf("Baseaddress = ") ;
    	printf("%x",BA3);
		A3CRP(i,j,k);
    	free(BA3);
    	break;
		}
    }
    return 0 ;
    
}//end function