#include <stdio.h> //use printf()
#include <conio.h> //use getch()
#define N 5//Set Max Queue

	int Q[N]; //Prepare Queue 0...N-1
	int x ; //Declare x variable
	int F = N ; //Declare initial Front variable
	int R = N ; //Declare Rear variable
	char status = 'N' ; //Initial Status = Normal
	char ch; //KBD Read variable
	
		void insertQ(int x) //INSERT Function
			{
				if((R == F+1) || (R == 1 && F == N-1)) //Check Queue FULL?
					{
						printf("!!! OVER FLOW !!!");
						status ='O' ; //Set status = OVER FLOW
					}
				else
					{
						if(R == 1)
						{
							R =N-1 ;
						}
						else
						{
							R-- ;
						if(F == N)
						F = N-1 ;
					} 
						Q[R] = x ; //Put data into Queue
					}
			} //END FUNCTION VOID INSERT QUEUE!!!!
			
//End void-------------------------------------------------------------------------------------------------
			
		int deleteQ( ) //DELETE Function
			{
				int x ;
				if(F == N) //Check QUEUE NOT EMPTY?
					{
						printf("\n!!! UNDER FLOW !!!\n") ;
						status = 'U' ; //Set STATUS = "UNDER FLOW"
					}
					x=Q[F] ; //Get data from Queue
						if(F == R)
							{
								F = N ;
								R = N ;
							}
						else
							{
					 		if(F == 1)
								F = N-1 ;
							else
								F--	;
							}	
						return(x) ; //RETURN DATA			
					}
	//END FUNCTION INT QUEUE!!!!

//--------------------------------------------------------------------------------------------------------------

int datainQ( )
	{
	int x=0 ;
	if (F != N && R != N )
	{
	if (F >= R)
		x =F - R + 1 ;
	else
		x =N - R +F ;
	}
return (x) ;
	}
				
//End De-------------------------------------------------------------------------------------------------

		void ShowAllQueue( ) //Display Function
			{
				int i ; //Counter variable
				printf("N : %d\n",N-1) ;
				printf("Status : %c\n",status) ; //Display STATUS
				printf("F : %d R : %d\n",F,R) ; //Display F&R
				printf("Data In Q : %d\n",datainQ( ) ) ;
				for (i = 1 ; i < N ; i++)
					{
						printf("| %d : %d | ",i,Q[i]) ; //Display all of Data in Queue
					}
				printf("\n-----------------------------------------------------------------------\n") ;
			} //END FUNCTION VOID SHOWALLQUEUE!!!!
			
//End viod show-------------------------------------------------------------------------------------------------

		int main( )
			{
				printf("QUEUE PROGRAM\n") ;
				printf("=========================================================================\n") ;
				while (status = 'N')
					{
						printf("\n[1] : INSERT [2] : DELETE\n "); //Show menu
						ch = getch() ; //Wait and Read KBD with put ENTER press
						switch(ch) //Check Ch
							{
								case '1' :
									printf("\nINSERT NUMBER : ") ;
									scanf("%d", &x) ; //Read Data from KBD
									insertQ(x) ; //Call INSERTQ in Queue
									ShowAllQueue( ) ; //Dispaly all data in queue
									break;
									
								case '2' :
									x = deleteQ() ; //Display data
									printf("\nDATA from Queue = %d\n",x) ; //Display it
									ShowAllQueue( ) ; //Dispaly all data in queue
									
							} //END SWITCH CASE !!!!
					} //END WHILE LOOP!!!!
				printf("\n") ; // Line feed
				return(0) ;
			} //END FUNCTION INT MAIN!!!!
