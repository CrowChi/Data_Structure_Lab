#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define MaxData 100
int Data[MaxData];
int N;

void PrepareRawData(int N){
	
	int i ;
    srand(time(NULL));
    for( i = 1 ; i <= N ; i++ ){
        Data[i] = 65 + rand()%52 ;
        if(Data[i] >= 91 && Data[i] <= 96) {
        	Data[i] = Data[i] - 6 ;
		}
    }

    
}

void DispData( int N ){
	int i;
	for( i = 1 ; i <= N ; i++ )
		printf("\t%2d",Data[i]);
	printf("\n");
}

void BubbleSort(int N){
	int i, j, temp;
	printf("-----------------------\n");
	printf(" i\t");
	for( i = 1 ; i <= N ; i++ )
		printf("<%d>\t",i);
	printf("\n");
	printf("-----------------------\n");
	for( i = 1 ; i <= N-1 ; i++ ){
		if(Data[i] < Data[i+1]){//revers 
			printf("%2d.",i+1);
			DispData(N);
			j = i;
			while( Data[j] < Data[j+1] && j != 0){//revers
				temp = Data[j+1];
				Data[j+1] = Data[j] ;  
				Data[j] = temp;
				j--;
				printf("%2d.",i+1);
				DispData(N);
			}
		}
	}
}

int main(){
	printf("ASCENDING BUBBLE SORT \n");
	printf("-----------------------\n");
	N = 12;
	PrepareRawData(N);
	printf("Raw Data ");
	DispData(N);
	printf("-----------------------\n");
	printf("Processing Data \n");
	BubbleSort(N);
	printf("-----------------------\n");
	printf("Sort Data :");
	DispData(N);
	getch();
	return 0;
}
