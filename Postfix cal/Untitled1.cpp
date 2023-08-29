#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

#define MaxStack 40

char postfix2[ 80 ] = { "AB+C-D/" } ;
float ValPostfix[ 80 ] ;
float ValOperandST[ MaxStack ] ;
int SP = 0 ;

void pushin( float ValOperand ) {
	if( SP == MaxStack ) printf( "\nERROR STACK OVERFLOW!!!\n" ) ;
	else {
		SP++ ;
		ValOperandST[ SP ] = ValOperand ;
	}
}

float popin() {
	float ValOperand ;
	if( SP != 0 ) {
		ValOperand = ValOperandST[ SP ] ;
		SP-- ;
		return( ValOperand ) ;
	} else printf( "\nERROR STACK UNDERFLOW!!!\n" ) ;
}

void CalPostfix( char postfix[ 80 ] ) {
	float pop1 , pop2 , value ;
	int i , len ;
	char ch ;
	len = strlen( postfix ) ;
	printf( "Postfix = %s\n" , postfix ) ;
	for( i = 0 ; i < len - 1 ; i++ ) {
		ch = postfix[ i ] ;
		if( strchr( "+-*/^" , ch ) == 0 ) {
			printf( "\nAssign Number to %c : " , ch ) ;
			scanf( "%f" , &ValPostfix[ i ] ) ;
		}
	}
	for( i = 0 ; i <= len - 1 ; i++ ) {
		ch = postfix[ i ] ;
		if( strchr( "+-*/^" , ch ) == 0 ) pushin( ValPostfix[ i ] ) ;
		else {
			pop1 = popin() ;
			pop2 = popin() ;
			switch( ch ) {
				case '+' :
					value =  pop2 + pop1 ;
					pushin( value ) ;
				break ;
				case '-' :
					value =  pop2 - pop1 ;
					pushin( value ) ;
				break ;
				case '*' :
					value =  pop2 * pop1 ;
					pushin( value ) ;
				break ;
				case '/' :
					value =  pop2 / pop1 ;
					pushin( value ) ;
				break ;
				case '^' :
					value =  pow( pop2 , pop1 ) ;
					pushin( value ) ;
				break ;
			}
		}
	}
	printf( "\nANS = %.2f" , popin() ) ;
}

int main() {
	printf( "POSTFIX CALCULATION PROGRAM\n" ) ;
	printf( "===========================\n" ) ;
	CalPostfix( postfix2 ) ;
	getch() ;
	return( 0 ) ;
}
