#include <stdio.h> 
#include <conio.h>
#define MaxEdge 6 
#define Block 4
#define MaxNode 4

char Head[MaxNode][Block]={//row x colum
// i   j  0   1   2   3
/*A0*/	{'A','-','1','1'},
/*B1*/	{'B','-','2','2'},
/*C2*/	{'C','-','3','5'},
/*D3*/	{'D','-','0','NULL'},
};
char Edge[MaxEdge][2]={
// i       j  0   1   
/*0*/		{'2','B'},
/*1*/		{'5','A'},
/*2*/		{'9','C'},
/*3*/		{'7','D'},
/*4*/		{'8','B'},
/*5*/		{'6','D'},
};

void DispHead(){
	int i,j; // i=row ,j=colum
	printf("NODE...\n");
	printf("NO NAME Data Edge Pointer\n");
	for(i=0;i<MaxNode;i++){//row loop
		printf("%d   ",i+1);//number of row
		for(j=0;j<Block;j++)//colum loop
			printf("%c   ",Head[i][j]);//show node
			printf("\n");
	}//fori	
}

void DispEdge(){
	int i , j;
	printf("EDGE...\n");
	printf("NO WEIGHT NODE\n");
	for(i=0;i<MaxEdge;i++){//row loop
		printf("%d  ",i+1);//number of row
		for(j=0;j<2;j++){//colum loop
			printf("%c  ",Edge[i][j]);//show node
		}//forj
		printf("\n");
	}//fori	
}

void DispSetOfVertex(){
	int i;
	printf("\nSet of Vertex ={"); 
	for(i=0;i<MaxNode;i++){//row loop
		printf("%c",Head[i][0]);//show node name
		if(i!=MaxNode-1)
			printf(",");
	}//fori
	printf("}\n");
}

void DispSetOfEdge(){
	int i,j,AmtEdge,PT;
	printf("\nSet of Edge ={"); 
	for(i=0;i<MaxNode;i++){//row loop
		AmtEdge=Head[i][2]-48;//converse character to integer for amoung of edge 1
		PT=Head[i][3]-48;//converse character to integer for start point of array 1
		for(j=0;j<AmtEdge;j++){//loop follow by amoung of edge
			printf("(%c%c)%c,",Head[i][0],Edge[PT-1+j][1],Edge[PT-1+j][0]);//show egde and weiht
		}//forj
	}//fori
	printf("}\n");
}

int main(){
	printf("GRAPH NODE DIRECTORY REPRESENTATION METHOD\n");
	printf("=============================================\n");
	DispHead();
	DispEdge();
	DispSetOfVertex();
	DispSetOfEdge();
	getch();
	return(0);
}

