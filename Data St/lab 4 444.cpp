#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
#include<math.h>

#define MaxStack 900

//A+B*(C^D)
char OpSt[MaxStack]; 
int SP=0; 
float ValPostfix[80]; 
float ValOperandST[MaxStack];



/////////////////////////////Stack////////////////////////////
void push(char oper)
	{
		if(SP == MaxStack)
			{
				printf("ERROR STACK OVER FLOW!!!...\n");
			}
		else
			{
				SP=SP+1; 
				OpSt[SP]=oper;
			}
	}
int pop()
	{
		char oper;
	
	if(SP != 0) 
		{
			oper=OpSt[SP]; 
			SP--; 
			return(oper); 
		}
	else
			printf("\nERROR STACK UNDER FLOW!!!...\n");
	}

////////////////////////////////////////////////////////////////


int precedenceIP(char oper) 
	{
		switch(oper)
			{
				case '+'	:return(3);
				case '-'	:return(3);
				case '*'	:return(2);
				case '/'	:return(2);
				case '^'	:return(1);
				case '('	:return(0);
			}
	}
	
/////////////////////////////////////////////////	
int precedenceST(char oper) 
	{
		switch(oper)
			{
				case '+'	:return(3);
				case '-'	:return(3);
				case '*'	:return(2);
				case '/'	:return(2);
				case '^'	:return(1);
				case '('	:return(4);
			}
	}
	
/////////////////////////////////////////////////
	
	
void infixTOpostfix(char infix2[80])
	{
		int i , j , len;
		char ch,temp;
		
		printf("\nINFIX :%s\n ",infix2); 
		len=strlen(infix2); 
		printf("\nINFIX Length = %d \n\n",len); 
		
		
		
		printf("POSTFIX IS :");
		for(i=0;i<=len-1;i++) 
			{
				ch=infix2[i]; 
				if(strchr("+-*/^()", ch)==0)
					printf("%c",ch); 
				else 
					{
						if(SP==0)
							push(ch); 
						else
							if(ch != ')') 
								{
									if(precedenceIP(ch)>precedenceST(OpSt[SP]))
											push(ch); 
									else
										{
											printf("%c",pop()); 
											while(precedenceIP(ch)<=precedenceST(OpSt[SP]) && (SP != 0)) 
											printf("%c",pop()); 
											push(ch); 
										}
								}
							else
								{
									temp=pop(); 
									while((temp != '('))
										{
											printf("%c",temp); 
											temp=pop(); 
										}
								}
					}
			}
		j=SP; 
		for(i=1;i<=j;i++)
		printf("%c",pop()); 	
	}

////////////////////////////////////////////////////////////////////////////

void CalPostfix(char postfix[80])
	{
		float pop1 , pop2 , value ;
		int i , len ;
		char ch ;
		len = strlen(postfix);
		printf("Postfix =%s\n" , postfix );
		for( i = 0 ; i <= len - 1 ; i++ ) //Assign data to OPERAND
			{
				ch = postfix[i] ; //Split Character for assign data
				if( strchr("+-*/^" , ch ) == 0 ) //Check Is OPENRAND?
					{
						printf( "\nAssign Number to %c : " , ch );
						scanf( "%f" , &ValPostfix[i] ); //Read data from KBD and direct to Value of OPERAND in Array
					}
			}
		for( i = 0 ; i <= len - 1 ; i++ ) //Calculate Value of POSTFIX
			{
				ch = postfix[i] ; //Split Character for prepare to STACK
				if( strchr("+-*/^" , ch ) == 0 ) //Check Is OPENRAND?
					{
						push(ValPostfix[i]); //push value of OPERAND to Stack
					}
				else
					{
						pop1 = pop(); //Pop 1st
						pop2 = pop(); //Pop 2nd
						switch(ch)
						{
							case '+' :	value = pop2 + pop1 ; //Calculate
										push(value); //Push value to Stack
										break;
							case '-' :	value = pop2 - pop1 ; //Calculate
										push(value); //Push value to Stack
										break;
							case '*' :	value = pop2 * pop1 ; //Calculate
										push(value); //Push value to Stack
										break;
							case '/' :	value = pop2 / pop1 ; //Calculate
										push(value); //Push value to Stack
										break;
							case '^' :	value = pow(pop2 , pop1) ; //Calculate
										push(value); //Push value to Stack
										break;
						}
					} //End IF
			} //End IF
		printf( "\nANS = %f" , pop() ); //Last value is ANSWER
	} //End Fn


///////////////////////////////////////////////////////////////////////////

void cheak ( char infix3[80], int n ){
	
	int s , i;
	
	for(i = 0 ; i<= n ; i++){
	
		if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == 0 )){
		
			printf("error");
		
		s = s + 1 ;
	
		break;
		
		}else 	if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == '+' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == '*' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == '/' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == '^' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == '-' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
			
		}else if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == 0 )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == '+' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == '*' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == '/' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == '^' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == '-' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		}else if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == 0 )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == '+' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == '*' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == '/' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == '^' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == '-' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		}else if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == 0 )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == '+' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == '*' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == '/' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == '^' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == '-' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		}else if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == 0 )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == '+' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == '*' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == '/' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		} else 	if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == '^' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		
		}else 	if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == '-' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
		}
		

	}

	int x = 0 , y = 0;
	
		for(i = 0 ; i<= n ; i++){
		if( infix3 [ i ] == '(' ){
			x=x+1 ;
		}
		if( infix3 [ i ]== ')'){
			y=y+1 ;
			
		}
		
		}//end for
	
		if(x!=y){
			printf("error");
			s= s+10;
		
		}


	if ( s <= 0 ){
		
		infixTOpostfix(infix3);
		
	}
	
	
	

}

////////////////////////////////////////////////////////////////////////////////

int main ()
	{

		char infix1[80];
		int i , n , s = 0 ,ch,o[80];
		
	  	
	
		printf("INFIX to POSTFIX CONVERSION PROGRAM\n");
		printf("===================================================\n");


		printf("Input Infix : ");
		scanf("%s" ,&infix1);
		
		n = strlen(infix1) ;
		
	
		cheak(infix1,n);
	
	
	/*	for( i = 0 ; i <= n ; i ++) 
		{
			ch = infix1[i]; */
//			if(strchr("+-*/^()", ch)==0){
				
/*				printf("\n%c : " ,ch);
				scanf("%d",&o[i]);
				
				
			}
		
			
		 } 
		
	*/


	CalPostfix(infix1);

		getch();
		return(0);
		
	}

/////////////////////////////////////////////////////////////////////////////
