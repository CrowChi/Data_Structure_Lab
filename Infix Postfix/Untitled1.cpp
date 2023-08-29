#include <stdio.h> // use printf()
#include <conio.h> // use getch()
#include <string.h> // use string function

#define MaxStack 40 // set Max operator stack

char infix1[80] = {"A+B*(C^D*E/F)-G"} ; // Assign INFIX
char OpSt[MaxStack] ; // operator stack size
int SP = 0 ; // initial SP = 0


void push(char oper) // PUSH Function
{
    if ( SP == MaxStack) // Check stack Full ?
    {
        printf ("===========!!!!ERROR STACK OVER FLOW!!!!===========\n") ;
    } //end if 
    else
    {
        SP = SP + 1 ;  // Increase SP
        OpSt[SP] = oper ; // Put data into Stack
    } //end else     
} // end fuction push

int pop() // POP Fucntion
{
    char oper ; 
    if (SP != 0 ) // Check Stack not empty?
    {
        oper = OpSt[SP] ; // Getdatafrom Stack
        SP-- ;
        return(oper) ; // Return data
    }//end if
    else
    	printf ("\n===========ERROR STACK UNDER FLOW!!!===========\n") ;   
} //end pop fuction

int precedenceIP(char oper) /// Function For check precedence of input operator
{
    switch(oper) 
    {
        case '+'        :return(4) ;
        case '-'        :return(4) ;
        case '*'        :return(2) ;
        case '/'        :return(2) ;
        case '^'        :return(1) ;
        case '('        :return(1) ;
    } // end switch case
} // end precedenceIP fuction

int precedenceST(char oper) //Function check precedence of stack operator
{
    switch(oper) 
    {
        case '+'        :return(3) ;
        case '-'        :return(3) ;
        case '*'        :return(2) ;
        case '/'        :return(2) ;
        case '^'        :return(1) ;
        case '('        :return(4) ;
    } /// end switch case
} // end precedenceST

void infixTOpostfix(char infix2[80])
{
    int i , j , len ;
    char ch,temp ;
    printf("INFIX : %s\n",infix2) ; // Show infix
    len = strlen(infix2) ; // find length of infix
    printf("Infix Length =%d \n",len) ; // Display length of infix
    printf("POSFIX IS :");
    for (i = 0 ; i <= len-1 ; i++) // split infix
    {
        ch = infix2[i] ; // transfer character in to ch variable
        if (strchr("+-*/^()", ch)==0) // check is operand?
        printf ("%c",ch) ; // out to postfix
        else // if opearator do below
        {
            if (SP == 0) // Stack empty?
                push(ch); // push any way if stack empty
            else
                if (ch != ')') // if not ')' do ble
                {
                    if (precedenceIP(ch)<precedenceST(OpSt[SP])) // if precendence input > precedence in stack
                        push(ch) ; // Push input operator to stack
                    else
                    {
                        printf("%c",pop()) ; // out to postfix
                        while(precedenceIP(ch)>=precedenceST(OpSt[SP])&&(SP != 0)) // Do untill precedence input > precedence in stack in stack
                            printf("%c",pop()); // outto postfix
                            push(ch) ; // Push operator input to stack
        	        } //end else 
                } ////end if
                else
                {
                    temp = pop() ; // Pop operator from stack
                    while ((temp != '(')) // do if not found '('
                    {
                        printf("%c",temp) ; // out to postfix
                        temp = pop(); // pop again and loop
                    } ////end while
                }//end else 
        } //end else  
    } // loop for
    j = SP ; // let j for count left stack
    for (i = 1 ; i <= j ; i++) // pop all if input is null
        printf("%c",pop()) ; // out to postfix
} //end infixTOpostfix

int main ()
{
    printf ("INFIX to POSTFIX CONVERSION PROGRAM\n") ; 
    printf ("====================================\n") ; 
    infixTOpostfix(infix1) ; 
    getch();
    return(0) ; 
} // end main
