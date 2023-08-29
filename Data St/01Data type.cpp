#include<stdio.h>
#include<conio.h>
#include<float.h>

char ch ;

short int s_int ;
int nor_int ;
long int long_int ;
float  sf_num ;
double d_int; 
bool logic ;

int main(){
	//CHARACTER TESTING...
	printf("CHARACTER TESTING...\n");
	printf("========================\n");
	ch ='¡';
	printf("Size of Character =%d", sizeof(ch));
	printf("\nCh =%c", ch); 
	printf("\n¡  %c",-95);
	printf("\nValue in Ch(ASCII)Invert     =%x",0xa1  );
	printf("\nValue in Ch(Signed)Invert    =%c",-95  );
	printf("\nValue iv Ch(Unsigned)Invert  =%c",4294967201 );
	printf("\n-------------------------------------------\n\n");
	printf("\nValue in Ch(ASCII)    in Haxe    =%x", ch );
	printf("\nValue in Ch(Signed)   in Decimal =%d", ch );
	printf("\nValue iv Ch(Unsigned) in Decimal =%u", ch);
	printf("\n-------------------------------------------\n\n");
	getch();
	
	//SHORT INTEGER TESTING...
	printf("SHORT INTEGER TESTING...\n");
	printf("========================\n");
	s_int=-1;
	printf("Size of Short Integer = %d" , sizeof(s_int));
	printf("\ns_int = %d" , s_int );
	printf("\nValue in s_int (In Hexa) = %x" , s_int);
	printf("\n-------------------------------------------\n\n");
	getch();
	
	//NORMAL INTEGER TESTING...
	printf("NORMAL INTEGER TESTING...\n");
	printf("========================\n");
	nor_int=-1;
	printf("Size of Normal Integer = %d" , sizeof(nor_int));
	printf("\ns_int = %d" , nor_int );
	printf("\nValue in nor_int (In Hexa) = %x" , nor_int);
	printf("\n-------------------------------------------\n\n");
	getch();
	
	//LONG INTEGER TESTING...
	printf("LONG INTEGER TESTING...\n");
	printf("========================\n");
	long_int=-1;
	printf("Size of Long Integer = %d" , sizeof(long_int));
	printf("\nlong_int = %d" , long_int );
	printf("\nValue in long_int (In Hexa) = %x" , long_int);
	printf("\n-------------------------------------------\n\n");
	getch();
	
	//FLOAT TESTING...
	printf("FLOAT TESTING...\n");
	printf("========================\n");
	sf_num=0.025;
	printf("Size of Floating Point = %d" , sizeof(sf_num));
	printf("\nSingle Precision = %f" , sf_num );
	printf("\nValue in Single Precision(In Hexa) = %x" , sf_num);
	printf("\n-------------------------------------------\n\n");
	getch();
	
	//DOUBLE TESTING...
	printf("DOUBLE Floating Point TESTING...\n");
	printf("========================\n");
	d_int=0.025;
	printf("Size of DOUBLE Floating Point = %d" , sizeof(d_int));
	printf("\nd_int = %f" , d_int );
	printf("\nValue in d_int(In Hexa) = %x" , d_int);
	printf("\n-------------------------------------------\n\n");
	getch();
	
	//BOOLEAN TESTING...
	printf("BOOLEAN TESTING...\n");
	printf("========================\n");
	logic=true;
	printf("Size of Boolean = %d" , sizeof(logic));
	printf("\nValue in Boolean(In Hexa) = %x" , logic );
	printf("\nValue in INV Boolean(In Hexa) = %x" , !logic);
	printf("\n-------------------------------------------\n\n");
	printf("END OF TESTING...\n");
	printf("\n*******************************************\n\n");
	getch();
}
