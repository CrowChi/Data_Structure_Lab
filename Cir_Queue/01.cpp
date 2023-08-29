#include <stdio.h> //use printf()
#include <conio.h> //use getch()
#define N 5 //Set Max Queue

	int Q[N]; //Prepare Queue 0...N-1
	int x ; //Declare x variable
	int F = 0 ; //Declare initial Front variable
	int R = 0 ; //Declare Rear variable
	char status = 'N' ; //Initial Status = Normal
	char ch; //KBD Read variable
	
		void insertQ(int x) //INSERT Function
			{
				if(R == N-1) //Check Queue FULL?
					{
						printf("!!! OVER FLOW !!!");
						status ='O' ; //Set status = OVER FLOW
					}
				else
					{
						R =R + 1 ; //Increase R
							if(F==0)
								{
									F++ ;
								}
						Q[R] = x ; //Put data into Queue
					}
			} //END FUNCTION VOID INSERT QUEUE!!!!
			
//End void-------------------------------------------------------------------------------------------------
			
		int deleteQ( ) //DELETE Function
			{
				int x ;
				if(F != 0) //Check QUEUE NOT EMPTY?
					{
					x=Q[F] ; //Get data from Queue
						if(F == R)
							{
								F = 0 ;
								R = 0 ;
							}
						else
							{
								F++ ;
							}	
						return(x) ; //RETURN DATA			
					}
				else
					{
						printf("\n!!! UNDER FLOW !!!\n") ;
						status = 'U' ; //Set STATUS = "UNDER FLOW"
					}
			}//END FUNCTION INT QUEUE!!!!
			
//End De-------------------------------------------------------------------------------------------------

		void ShowAllQueue( ) //Display Function
			{
				int i ; //Counter variable
				printf("N : %d\n",N-1) ;
				printf("Status : %c\n",status) ; //Display STATUS
				printf("F : %d R : %d\n",F,R) ; //Display F&R
				for (i = 1 ; i < N ; i++)
					{
						printf("| %d : %d | ",i,Q[i]) ; //Display all of Data in Queue
					}
				printf("\n-----------------------------------------------------------------------\n") ;
			} //END FUNCTION VOID SHOWALLQUEUE!!!!
			
//End viod show-------------------------------------------------------------------------------------------------

		int main( )
			{
				printf("QUEUE PROGRAM....\n") ;
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
