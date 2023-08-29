#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MaxData 100
int Data[MaxData];
int N;

void PrepareRawData(int N){
    int i ;
    srand(time(NULL));
    for( i = 1 ; i <= N ; i++ ){
        
		Data[i] = 1 +rand()%99; //random
		
		}
    }

void DispData(int N){
	int i;
	for(i = 1 ; i <= N ; i++)
		printf("%2d	",Data[i]);
	printf("\n");
	
}

void InsertionSort(int N){
	int i, j, temp;
	printf("----------------------------------\n");
	printf("i ");
	for(i = 1 ; i <= N ; i++)
		printf("(%2d)", i);
	printf("\n");
	printf("----------------------------------\n");
	printf("%2d ", 0);
	DispData(N);//show every step sorting
	for(i = 1 ; i < N ; i++){
		
		if(Data[i+1] > Data[i]){//
			temp = Data[i+1];
			Data[i+1] = '0';
			j = i;
			
			while(temp > Data[j] && j != 0){//temp > data ?
				Data[j+1] = Data[j];
				Data[j] = '0';
				printf("%2d ", i+1);
				DispData(N);
				j = j-1;		
			}
			Data[j+1] = temp;
			printf("%2d ", i+1);
			DispData(N);			
		}
	}
}

int main(){
	printf("ASCENDING INSERTION SORT\n");
	printf("=============================");
	N = 16;
	PrepareRawData(N);
	printf("\nRaw Data...");
	DispData(N);
	printf("Processing Data..\n");
	InsertionSort(N);
	printf("-----------------------------\n");
	printf("Sorted Data : ");
	DispData(N);
	getch();
	
	return(0);
}
