#include <stdio.h> // use printf
#include <conio.h> // use getch
#include <stdlib.h> // use malloc
#define L 1 // lower bound
#define U 5 // upper bound
#define L1 1 // lower bound1
#define U1 3 // upper bound1
#define L2 1 // lower bound2
#define U2 4 // upper bound2
#define L3 1 // lower bound3
#define U3 5 // upper bound3
#define L4 1// lower bound4
#define U4 6 // upper bound4

int *BA1, *BA2, *BA3, *BA4, *p ; // base address of each dimension and moving pointer
int i,j,k,l ; //subscript of array

void create1darray()
	{ // create array 1
	int element, c, total_mem ; //variable uses
	element =(U-L+1) ; //calculate element
	c = sizeof (*BA1) ; //calculate size each block of array
	total_mem = element*c ; //calculate  total
	BA1 = (int*)malloc(total_mem) ; //memory allocate and use BA1 point its
	}
	
void A1(int i, int x)
	{ // putdata into array 1
	p=BA1+(i-L) ; //calculate pointer
	*p=x ; //put data 
	}
int readA1(int i)
	{//read data from array 1
	p=BA1+(i-L) ; //calculate pointer
	return(*p) ;//return valie in array
	}
	
//-------------------------------

void create2darray()
	{ // create array 2
	int element, c, total_mem ; //variable uses
	element = (U1-L1+1)*(U2-L2+1) ; //calculate element
	c = sizeof (*BA2) ; //calculate size each block of array
	total_mem = element*c ; //calculate  total
	BA2 = (int*)malloc(total_mem) ; //memory allocate and use BA1 point its
	}
	
void A2RM(int i,int j, int x) 
	{ // putdata into array 2
	p=BA2+((i-L1)*(U2-L2+1)*(j-L2)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA2RM(int i,int j) 
	{//read data from array 2
	p=BA2+(i-L1)*(U2-L2+1)*(j-L2) ; //calculate pointer
	return(*p) ;//return valie in array
	} 
void A2CM(int i,int j, int x) 
	{ // putdata into array 2
	p=BA2+((j-L2)*(U2-L2+1)*(i-L1)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA2CM(int i,int j) 
	{//read data from array 2
	p=BA2+(j-L2)*(U2-L2+1)*(i-L1) ; //calculate pointer
	return(*p) ;//return valie in array
	} 
	
//---------------------------------
	
void create3darray()
	{ // create array 3
	int element, c, total_mem ; //variable uses
	element = (U1-L1+1)*(U2-L2+1)*(U3-L3+1) ; //calculate element
	c = sizeof (*BA3) ; //calculate size each block of array
	total_mem = element*c ; //calculate  total
	BA3 = (int*)malloc(total_mem) ; //memory allocate and use BA1 point its
	}
	
void A3PRC(int i,int j,int k, int x)
	{ // putdata into array 3
	p=BA3+((i-L1)*(U2-L2+1)*(U3-L3+1)+(j-L2)*(U3-L3+1)+(k-L3)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA3PRC(int i,int j,int k)
	{//read data from array 3
	p=BA3+(i-L1)*(U2-L2+1)*(U3-L3+1)+(j-L2)*(U3-L3+1)+(k-L3) ; //calculate pointer
	return(*p) ;//return valie in array
	}
	
void A3PCR(int i,int j,int k, int x)
	{ // putdata into array 3
	p=BA3+((i-L1)*(U2-L2+1)*(U3-L3+1)+(k-L3)*(U2-L2+1)+(j-L2)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA3PCR(int i,int j,int k)
	{//read data from array 3
	p=BA3+(i-L1)*(U2-L2+1)*(U3-L3+1)+(k-L3)*(U2-L2+1)+(j-L2) ; //calculate pointer
	return(*p) ;//return valie in array
	}
	
void A3RPC(int i,int j,int k, int x)
	{ // putdata into array 3
	p=BA3+((j-L2)*(U1-L1+1)*(U3-L3+1)+(i-L)*(U3-L3+1)+(k-L3)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA3RPC(int i,int j,int k)
	{//read data from array 3
	p=BA3+(j-L2)*(U1-L1+1)*(U3-L3+1)+(i-L)*(U3-L3+1)+(k-L3) ; //calculate pointer
	return(*p) ;//return valie in array
	}
	
void A3RCP(int i,int j,int k, int x)
	{ // putdata into array 3
	p=BA3+((j-L2)*(U1-L1+1)*(U3-L3+1)+(k-L3)*(U1-L1+1)+(i-L1)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA3RCP(int i,int j,int k)
	{//read data from array 3
	p=BA3+(j-L2)*(U1-L1+1)*(U3-L3+1)+(k-L3)*(U1-L1+1)+(i-L1) ; //calculate pointer
	return(*p) ;//return valie in array
	}
	
void A3CPR(int i,int j,int k, int x)
	{ // putdata into array 3
	p=BA3+((k-L3)*(U1-L1+1)*(U2-L2+1)+(i-L1)*(U2-L2+1)+(j-L2)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA3CPR(int i,int j,int k)
	{//read data from array 3
	p=BA3+(k-L3)*(U1-L1+1)*(U2-L2+1)+(i-L1)*(U2-L2+1)+(j-L2) ; //calculate pointer
	return(*p) ;//return valie in array
	}

void A3CRP(int i,int j,int k, int x)
	{ // putdata into array 3
	p=BA3+((k-L3)*(U1-L1+1)*(U2-L2+1)+(j-L2)*(U1-L1+1)+(i-L1)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA3CRP(int i,int j,int k)
	{//read data from array 3
	p=BA3+(k-L3)*(U1-L1+1)*(U2-L2+1)+(j-L2)*(U1-L1+1)+(i-L1) ; //calculate pointer
	return(*p) ;//return valie in array
	}
	
//------------------------------------

void create4darray()
	{ // create array 4
	int element, c, total_mem ; //variable uses
	element = (U1-L1+1)*(U2-L2+1)*(U3-L3+1)*(U4-L4+1) ; //calculate element
	c = sizeof (*BA4) ; //calculate size each block of array
	total_mem = element*c ; //calculate  total
	BA4 = (int*)malloc(total_mem) ; //memory allocate and use BA1 point its
	}
	
void A4(int i,int j,int k,int l, int x)
	{ // putdata into array 4
	p=BA4+((i-L1)*(U2-L2+1)*(U3-L3+1)*(U4+L4-1)+(j-L2)*(U3-L3+1)*(U4-L4+1)+(k-L3)*(U4+L4-1)+(l-L4)) ; //calculate pointer
	*p=x ; //put data 
	}
int readA4(int i,int j,int k,int l)
	{//read data from array 4
	p=BA4+(i-L1)*(U2-L2+1)*(U3-L3+1)*(U4+L4-1)+(j-L2)*(U3-L3+1)*(U4-L4+1)+(k-L3)*(U4+L4-1)+(l-L4) ; //calculate pointer
	return(*p) ;//return valie in array
	}



//------------------------------------

int main () {
	printf ("1-3 Dimension Array Function..\n") ;
	printf ("=====================================================\n") ;
	create1darray() ;
	create2darray() ;
	create3darray() ; 
	create4darray() ;
//using 1 dimention array
	i=2 ;
	A1(i,9) ;
	printf ("\nA1(%d)=%d",i,readA1(i)) ;
	printf ("\nbase address BA1 :%d",BA1) ;
	printf ("\nbase address Array :%d",p) ;
//using 2 dimention array
	i=2, j=3 ;
		A2RM(i, j, 99) ;
	printf ("\nA2RM(%d,%d)=%d",i,j,readA2RM(i,j)) ;
	printf ("\nbase address BA2 :%d",BA2) ;
	printf ("\nbase address Array :%d",p) ;
		A2CM(i, j, 99) ;
	printf ("\nA2CM(%d,%d)=%d",i,j,readA2CM(i,j)) ;
	printf ("\nbase address BA2 :%d",BA2) ;
	printf ("\nbase address Array :%d",p) ;
//using 3 dimention array
	i=3, j=4 ,k=5 ;
		A3PRC(i, j, k, 999) ;
	printf ("\nA3PRC(%d,%d,%d)=%d",i,j,k,readA3PRC(i,j,k)) ;
	printf ("\nbase address BA3 :%d",BA3) ;
	printf ("\nbase address Array :%d",p) ;
		A3PCR(i, j, k, 999) ;
	printf ("\nA3PCR(%d,%d,%d)=%d",i,j,k,readA3PCR(i,j,k)) ;
	printf ("\nbase address BA3 :%d",BA3) ;
	printf ("\nbase address Array :%d",p) ;
		A3RPC(i, j, k, 999) ;
	printf ("\nA3RPC(%d,%d,%d)=%d",i,j,k,readA3RPC(i,j,k)) ;
	printf ("\nbase address BA3 :%d",BA3) ;
	printf ("\nbase address Array :%d",p) ;
		A3CPR(i, j, k, 999) ;
	printf ("\nA3RCP(%d,%d,%d)=%d",i,j,k,readA3RCP(i,j,k)) ;
	printf ("\nbase address BA3 :%d",BA3) ;
	printf ("\nbase address Array :%d",p) ;
		A3RCP(i, j, k, 999) ;
	printf ("\nA3CPR(%d,%d,%d)=%d",i,j,k,readA3CPR(i,j,k)) ;
	printf ("\nbase address BA3 :%d",BA3) ;
	printf ("\nbase address Array :%d",p) ;
		A3CRP(i, j, k, 999) ;
	printf ("\nA3CRP(%d,%d,%d)=%d",i,j,k,readA3CRP(i,j,k)) ;
	printf ("\nbase address BA3 :%d",BA3) ;
	printf ("\nbase address Array :%d",p) ;
//using 4 dimention array
	i=3, j=4, k=5, l=6 ;
	A4(i, j, k, l, 9999) ;
	printf ("\nA4(%d,%d,%d,%d)=%d",i,j,k,l,readA4(i,j,k,l)) ;
	getch () ;//wait for KBD hit
	free(BA1) ;
	free(BA2) ;
	free(BA3) ;
	free(BA4) ;
	return(0) ;
	
}//End main
