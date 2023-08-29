
#include<stdio.h> //use printf()
#include<conio.h> //use getch()
#include<string.h> //use string function
#include<math.h> //use power
#define MaxStack 80	//Set Max Operator Stack

char postfix1[80] ;
float ValPostfix[80]; //keep value of Postfix here
float ValOperandST[MaxStack]; //Operator stack size
int SP = 0; //Initial SP = 0


char infix1[80] ; 
char OpSt[MaxStack];  

void push(char oper)//PUSH Function
	{
		if(SP == MaxStack)//Chack Stack FULL?
			{
				printf("ERROR STACK OVER FLOW!!!...\n");
			}
		else
			{
				SP=SP+1; //Increase SP
				OpSt[SP]=oper; //Put data into Stack
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
	
	
	
float popcal()//POP Function
	{
		float ValOperand ;
		if(SP != 0) //Check Stack NOT EMPTY?
			{
				ValOperand = ValOperandST[SP] ; //Get data from Stack
				SP-- ; //Decrease SP
				return(ValOperand); //Return data
			}
		else
			printf( "\nERROR STACK UNDER FLOW!!!...\n" );
	}
	
void pushcal(float ValOperand) //PUSH Function
	{
		if( SP == MaxStack ) // Chrck Stack FULL?
			{
				printf("ERROR STACK OVER FLOW!!!...\n");
			}
		else
			{
				SP = SP + 1 ; //Increase SP
				ValOperandST[SP] = ValOperand; //Put data into Stack
			}
	}
	
	
int precedenceIP(char oper) //Function for check precedence of input operator
	{
		switch(oper)
			{
				case '+'	:return(1);
				case '-'	:return(1);
				case '*'	:return(2);
				case '/'	:return(2);
				case '^'	:return(4);
				case '('	:return(4);
			}
	}
int precedenceST(char oper) //Function for check precedence of input operator
	{
		switch(oper)
			{
				case '+'	:return(1);
				case '-'	:return(1);
				case '*'	:return(2);
				case '/'	:return(2);
				case '^'	:return(3);
				case '('	:return(0);
			}
	}
void infixTOpostfix(char infix2[80])
	{
		int i , j , len,a;
		char ch,temp;
		printf("INFIX :%s\n ",infix2); 
		len=strlen(infix2); 
		printf("INFIX Length = %d \n",len); 
		for(i=0;i<=len-1;i++) 
			{
				ch=infix2[i]; 
				if(strchr("+-*/^()", ch)==0)
					{
						postfix1[a] = ch ;
						a++;
				}else 
					{
						if(SP==0)
						{
							
							push(ch);
							
							 
						}else
							if(ch != ')') 
								{
									if(precedenceIP(ch)>precedenceST(OpSt[SP]))
											push(ch); 
									else
										{	postfix1[a] = pop() ;
											a++;
										
											
											while(precedenceIP(ch)<=precedenceST(OpSt[SP]) && (SP != 0)) {
											postfix1[a] = pop();
											a++;
										
											
											}
											push(ch); 
										}
								}
							else
								{
									temp=pop();
									while((temp != '('))
										{
										
											postfix1[a] = temp ;
											a++;
											temp=pop();
											
										}
								}
					}
			}
		j=SP; 
		for(i=1;i<=j;i++){
		postfix1[a] = pop();
		a++;
	}
		
	}

void CalPostfix(char postfix[80])
	{
		float pop1 , pop2 , value ;
		int i , len ;
		char ch ;
		len = strlen(postfix);
		printf("\nPOSTFIX IS :%s\n" , postfix );
		
		
		for( i = 0 ; i <= len - 1 ; i++ )
			{
				ch = postfix[i] ; 
				if( strchr("+-*/^" , ch ) == 0 ) 
					{
						printf( "\nAssign Number to %c : " , ch );
						scanf( "%f" , &ValPostfix[i] ); 
					}
			}
		
		
		for( i = 0 ; i <= len - 1 ; i++ ) 
			{
				ch = postfix[i] ;
				if( strchr("+-*/^" , ch ) == 0 ) 
					{
						pushcal(ValPostfix[i]); 
					}
				else
					{
						pop1 = popcal(); 
						pop2 = popcal(); 
						switch(ch)
						{
							case '+' :	value = pop2 + pop1 ; 
										pushcal(value); 
										break;
							case '-' :	value = pop2 - pop1 ;
										pushcal(value); 
										break;
							case '*' :	value = pop2 * pop1 ; 
										pushcal(value); 
										break;
							case '/' :	value = pop2 / pop1 ; 
										pushcal(value); 
										break;
							case '^' :	value = pow(pop2 , pop1) ; 
										pushcal(value); 
										break;
						}
					} 
			} 
		printf( "\nANS = %f" , popcal() );
		
	}


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
			
		}else if ( (infix3 [ i ] == '+' ) && (infix3 [ i + 1 ] == ')' )){
		
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
		}else if ( (infix3 [ i ] == '-' ) && (infix3 [ i + 1 ] == ')' )){
		
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
		}else if ( (infix3 [ i ] == '*' ) && (infix3 [ i + 1 ] == ')' )){
		
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
		}else if ( (infix3 [ i ] == '/' ) && (infix3 [ i + 1 ] == ')' )){
		
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
		}else if ( (infix3 [ i ] == '^' ) && (infix3 [ i + 1 ] == ')' )){
		
			printf("error");
		
		s = s + 1 ;
	
			break;
			
		}else if ( (infix3 [ i ]  >= 65 ) && (infix3 [ i + 1 ] == '(' )){
		
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
		CalPostfix(postfix1);
	}
	
	
	

}

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
	    	 

        }
