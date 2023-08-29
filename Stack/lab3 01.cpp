#include <stdio.h> //use printf()
#include <conio.h> //use gtch()
#define MaxStack 6 // Set Max Stack

int stack[MaxStack]; // Declare Max Stack 0...5
int x; //Temporary variable
int SP = 0 ; // Initial SP = 
char status = 'N' ; // Initial Status = Normal
char ch; // kbd read variable

void push(int x) //Push Function
    {
    if(SP == MaxStack-1) // Check Stack full ?
        {
        printf ("!!!OVER FLOW!!!") ; 
        status = '0' ; // Set Status = OVER FLOW
        
        } 
    else
        {
        SP = SP + 1 ;// Increase SP
        stack[SP] = x ; // Put data into Stack
        }
    } //End void push
    
    
int pop() // POP Fuction
{
    int x ; 
    if ( SP != 0 ) // Check Stack NOT EMPTY?
    {
    x = stack[SP] ; // get data from stack
    SP--  ;
    return( x ) ; // return data
    }
    else
    {
    printf("\n!!!UNDER FLOW!!!\n");;
    status = 'U' ; // set status == "under Flow"
    }

}// end fuction pop
    

void ShowAllStack() // Display Function
    {
    int i ; // Counter variable
    printf ("N : %d\n" , MaxStack-1) ; // Display N
    printf ("Status :%c\n", status) ; // Display Status
    printf ("SP : %d\n", SP); //Display SP
    for (i = 1 ; i < MaxStack ; i++ ) 
        {
    printf ("%d : %d     \n", i , stack[i]); // Display all of data in stack
        }
    printf ("\n-----------------------------------------\n") ;
    } // end ShowAllStack
    
int main ()
    {
        printf ("Stackkk Program..\n");
        printf ("=====================\n") ;
        while (status == 'N')
            
            {
                
                printf ("[ 1 = PUSH     2 = POP ]  \n") ; // Show Menu
                ch = getch(); // Wait and read KBD with out Enter Press
                switch(ch) //Check ch 
                    {
                        case '1' : printf ("\nEnter Number : ") ;
                        scanf ("%d" , &x ) ; // read data form KBD
                        push(x) ; // call push Function
                        ShowAllStack(); // Display all data in stack
                        break ; // end case 1 
                    
                        case '2' : x = pop(); // POP data
                         printf ("\nData : %d\n", x) ; // display it 
                         ShowAllStack(); // Display all data in stack
                    } // check swtich case
            }// end while loop
    }// end int main
