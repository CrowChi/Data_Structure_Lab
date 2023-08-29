#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MaxData 100

int Data[MaxData] ;
int N ;

void PrepareRawData(int N){
	int i , j ;
	srand(time(NULL)) ;
	for (i = 1 ; i <= N ; i++)
		Data[i] = 65+rand()%52 ;
		
		
		if(Data[i] >= 91 && Data[i] <= 96)
        	Data[i] = Data[i] - 6 ;
		
		
		for( j = 1 ; j <= N ; j++){
			
			if (Data[j]  == Data[i] && Data[i] != NULL && j != i){
				
				printf("%d %c == %c\n",j, Data[j] , Data[i] );
				i--;
				break;
			}
	}
	
}
void DispData(int N,int out){
	int i ;
	for (i=1 ; i <= N ;i++)
		if(out >= i)
			printf ("[%2c]\t",Data[i]) ;
		else
			printf ("%2c\t",Data[i]) ;
	printf ("\n") ;
}                                          
void swap(int a,int b){
	int temp ;
	temp = Data[a] ;
	Data[a] = Data[b] ;
	Data[b] = temp ;
}
int Minimum(int j){
	int i , temp , Location ;
	Location = j ;
	temp = Data[j] ;
	for (i = j+1 ; i <= N ;i++){
		if(temp > Data[i])
			temp = Data[i] ;
			Location = i ;
	}
	return(Location) ;
}
void SelectionSort(int N){
	int i,j,Location ;
	printf ("---------------------------------\n") ;
	printf ("i     LOC     ") ;
	for (i=1 ; i <= N; i++)
		printf ("(%2d)\t",i) ;
	printf ("\n\t\t") ;
	DispData(N,0) ;
	printf ("---------------------------------\n") ;
	for(i = 1 ; i<= N ; i++){
		Location = Minimum(i) ;
		swap(i,Location) ;
		printf("(%2d)  (%2d)\t",i,Location) ;
		DispData(N,i) ;
	}
}
int main(){
	printf ("ASCENDING SELECTION SORT\n") ;
	printf ("============================================\n") ;
	N=12 ;
	PrepareRawData(N) ;
	printf ("Raw Data...") ;
	DispData(N,0) ;
	printf ("Processing Data \n") ;
	SelectionSort(N) ;
	printf ("=============================================\n") ;
	printf ("Sorted Data : ") ;
	DispData(N,N) ;
	getch() ;
	return(0) ;
}
