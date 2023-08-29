/*Program ASCENDING SELECTION SORT can...
	1.Random raw data into 1D Array
	2.Sorting and display detail of each step result
	3.Display final result
	4.modified to DESCENDING
*/	

#include <stdio.h>    //use printf
#include <conio.h>    //use getch
#include <stdlib.h>   //use random
#include <time.h>     //use time

#define MaxData 100	  // define max data

int Data[MaxData] ;
int N ;

void PrepareRawData( int N )
	{
		int i ;
	    srand(time(NULL)) ;	//for random by difference number in rand()
	    for( i = 1 ; i <= N ; i++ )
			Data[i] = 1+rand()%99 ; //random difference number between 1-99
	}//end Prepare Raw Data

void DispData( int N , int out ) //show Data in array 2 format
	{
		int i ;
		for ( i=1 ; i<=N ; i++ )
			if( out >= i )	
				printf( " [%2d] ", Data[i] ) ; //show output
			else
				printf( "   %2d ", Data[i] ) ; //show normal data
		printf( "\n" ) ;
	}//end Display data
	
void swap( int a, int b )
	{
		int temp ;
		temp = Data[a] ; 
		Data[a] = Data[b] ;
		Data[b] = temp ;
	}//end swap
	
int Maximum( int j ) //find Minimum data in data[] betweem j .. n
	{
		int i, temp, Location ;
		Location = j ; //set frist Location
		temp = Data[j] ; // set begin value
			for( i=j+1 ; i<=N ; i++ )
				{
					if( temp < Data[i] )	//if( temp > Data[i] )
						{//if data more than temp
							temp = Data[i] ; //chang new minimum data
							Location = i ; //let point new Location
						}//end if
				}//end for
			return(Location) ; // return address of minimum data
	} //end Fn.
	
void SelectionSort( int N )
	{
		int i, j, Location ;
		printf( "=====================================================================================\n" ) ;
		printf( "  i   LOC |" ) ;
		for( i=1 ; i<= N ; i++ )
			printf( " (%2d) " , i ) ;	//loop for show number 1...N
		printf("\n         ") ;
		DispData( N, 0 ) ; // show start data and every changing
		printf( "=====================================================================================\n" ) ;
		for( i=1 ; i<=N ; i++ )	//loop for find maximum
			{
				Location = Maximum(i) ; //Find Minimum Location between i .. N
				swap(i,Location) ;	
				printf( "(%2d) (%2d) |", i, Location ) ; //show Location of array
				DispData(N,i) ; // show every step sorting 
			}//end for
	} // end Fn.

int main()
	{
		printf("ASCENDING SELECTION SORT\n") ;
		printf("=====================================================================================\n") ;
		N = 16 ; //change amount of N here
		PrepareRawData(N) ;
		printf("Raw Data...") ;
		DispData(N,0) ;
		printf("Processing Data...\n") ;
		SelectionSort(N) ;
		printf("=====================================================================================\n") ;
		printf("Sorted Data :") ;
		DispData(N,N) ; //Sorted Data
		getch() ;
		return(0) ;
	} // End Main
