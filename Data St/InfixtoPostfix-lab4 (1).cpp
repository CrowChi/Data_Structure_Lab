#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MaxStack 40

char infix1[80]={"A+B*(C^D*E/F)-G"};
char OpSt[MaxStack];
char SumOp[MaxStack];
int SP = 0 ;

void push(char oper){
	if(SP == MaxStack){
		printf("ERROR STACK OVER FLOW!!!...\n");
	}
	else{
		SP = SP+1;
		OpSt[SP] = oper;
	}
}
int pop(){
	char oper;
	if(SP != 0){
		oper = OpSt[SP];
		SP--;
		return(oper);
	}
	else
		printf("\nERROR STACK UNDER FLOW!!!...\n");
}
int precedenceIP(char oper){
	switch(oper){
		case'+':return(3);
		case'-':return(3);
		case'*':return(2);
		case'/':return(2);
		case'^':return(1);
		case'(':return(1);
	}
}
int precedenceST(char oper){
	switch(oper){
		case'+':return(2);
		case'-':return(2);
		case'*':return(3);
		case'/':return(3);
		case'^':return(4);
		case'(':return(1);
	}
}

int changeIP(char oper){
	switch(oper){
		case'+':return(1);
		case'-':return(1);
		case'*':return(2);
		case'/':return(2);
		case'^':return(4);
		case'(':return(4);
	}
}

int changeST(char oper){
	switch(oper){
		case'+':return(1);
		case'-':return(1);
		case'*':return(2);
		case'/':return(2);
		case'^':return(3);
		case'(':return(0); 
	}
}
void infixTOpostfix(char infix2[80]){
	int i, j, len;
	char ch, temp;
	printf("INFIX :%s\n",infix2);
	len = strlen(infix2);
	printf("Infix Length =%d\n",len);
	printf("POSTFIX IS : ");
	for( i = 0 ; i <= len ; i++ ){
		ch = infix2[i];
		if(strchr("+-*/^()",ch) == 0 )
			printf("%c",ch);
		else{
			if(SP == 0){
				push(ch);
			}
			else
				if(ch != ')'){
					if( precedenceIP(changeIP(ch)) > precedenceST(changeST(OpSt[SP])) ){
							push(ch);
					}else{
						printf("%c",pop());
						while(precedenceIP(changeIP(ch)) <= precedenceST(changeST(OpSt[SP])) && (SP != 0))
							printf("%c",pop());
							push(ch);
					}
				}else{
					temp = pop();
					while((temp != '(')){
						printf("%c",temp);
						temp = pop();
					}
				}
			}
		}
		j = SP;
		for( i = 1 ; i >= 1 ; i++ );
			printf("%c",pop());
}
int main(){
	printf("INFIX to POSTFIX CONVERSION PROGRAM\n");
	printf("===================================\n");
	infixTOpostfix(infix1);
	getch();
	return(0);
}

