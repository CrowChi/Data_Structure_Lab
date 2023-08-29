#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MaxStack 40

char infix1[80]={"A+(B-(C+D))*E^2"};
char OpSt[MaxStack];
char ShowOp[MaxStack];
int SP = 0,Count = 0 ;

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
		case'+':return(1);
		case'-':return(1);
		case'*':return(2);
		case'/':return(2);
		case'^':return(4);
		case'(':return(4);
	}
}
int precedenceST(char oper){
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
	printf("POSTFIX IS : \n");
	for( i = 0 ; i <= len ; i++ ){
		ch = infix2[i];
		if(strchr("+-*/^()",ch) == 0 ){
			Count++;
			ShowOp[Count]=ch;
			printf("%d:%c\n",Count,ShowOp[Count]);
	}
		else{
			if(SP == 0)
				push(ch);
			else
				if(ch != ')'){
					if(precedenceIP(ch)>precedenceST(OpSt[SP]))
						push(ch);
					else{
							Count++;
							ShowOp[Count]=pop();
							printf("%d:%c\n",Count,ShowOp[Count]);
							//printf("%c",pop());
						while(precedenceIP(ch)<=precedenceST(OpSt[SP])&& (SP != 0)){
							Count++;
							ShowOp[Count]=pop();
							printf("%d:%c\n",Count,ShowOp[Count]);
							//printf("%c",pop());
							}
							push(ch);
						}
					}
				else{
					temp = pop();
					while((temp != '(')){
						Count++;
						ShowOp[Count]=temp;
						printf("%d:%c\n",Count,ShowOp[Count]);
						//printf("%c",temp);
						temp = pop();
					}
				}
			}
		}
		//j = SP;
		//	for( i = 0 ; i <= j ; i++ )
		//		printf("%c",pop());
}
int main(){
	
	printf("INFIX to POSTFIX CONVERSION PROGRAM\n");
	printf("===================================\n");
	infixTOpostfix(infix1);
	for(int i = 1 ; i <= 11 ; i++ )
		printf("%c",ShowOp[i]);
		
	getch();
	return(0);
}

