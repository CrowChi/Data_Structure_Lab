/*program Data reprtsentation Ver 2.0
The program will show value in any data types.
----------------------------------------------------------------*/
#include <stdio.h> //use prinf()
#include <conio.h> //use grtch()
#include <ctype.h> //use Character

char ch; //KBD read variable

void Dectobin(int data2 ,int byt) //Canvert Deximal to binary as byt bytes
	{
		int count ,chk ,bits ;
		bits = ( byt*8 )-1 ; //calculate total bits stared at bit no 0
		for ( count = bits ; count >= 0 ; count-- )
			{
				chk = data2 >> count ; //shift count bits of data2 and keep in to chk
				if ( chk & 1 ) //campare with '00000001'
					printf( "1" ) ; //if true
				else
					printf( "0" ) ; //false
				if ( count %4 == 0 && count>3 ) //seperate any 4 bits
					printf(" ") ;	
				}
				printf( "B\n" ) ;		
	}
	
void unsignedshortint ( ) //Test data in unsigned short integer mode
	{
	unsigned short int data ; //declare data variable for keep short unsigned integer types
	printf ("\nUNSTIGNRD SHORT INTEGER MODE [ 0 to 65,535]\n") ;
	printf ("===============================================\n") ;
	printf ("Enter Raw Data : " ) ;
	scanf ("%hu", &data) ;
	printf ("Data In Decimal = %huD\n" ,data ) ; //show in decimal format
	printf ("Data in Hexamal = %xH\n" ,data) ; //show in haxamal format
	printf ("Data in Binary = ") ;
	Dectobin (data ,sizeof(data)) ; //show in binary format
	printf ("Size           = %d bytes\n" ,sizeof(data)) ; //show size of unsigned short integer 
	getch() ; //wait for press any key
	}
	
void unsignedint ( ) //Test data in unsigned integer mode
	{
	unsigned int data ; //declare data variable for keep short unsigned integer types
	printf ("\nUNSTIGNRD INTEGER MODE [ 0 to 4,294,967,295]\n") ;
	printf ("===============================================\n") ;
	printf ("Enter Raw Data : " ) ;
	scanf ("%u", &data) ;
	printf ("Data In Decimal = %uD\n" ,data ) ; //show in decimal format
	printf ("Data in Hexamal = %xH\n" ,data) ; //show in haxamal format
	printf ("Data in Binary = ") ;
	Dectobin (data ,sizeof(data)) ; //show in binary format
	printf ("Size           = %d bytes\n" ,sizeof(data)) ; //show size of unsigned integer 
	getch() ; //wait for press any key
	}   
	
void Boolean ( ) //test data in boolean
	{
    bool data; //this data is variable to keep boolean types
    printf ("\nBoolean Mode [0 to 255]\n", data) ;
    printf ("----------------------------------------------\n") ;
    printf ("Enter Raw data : ") ;
    scanf ("%hu", &data);
    printf ("data meaning     = ") ; //Show result
    if (data)
        printf("True\n") ; //Show when true
    else
        printf("False\n") ;                       //Show when false                                         //end if
    printf ( "Data in Decimal = %uD\n", data) ; //Show Decimal process
    printf ( "Data in Hexamal = %xH\n", data) ; //Show Hexamal process
    printf ( "character       = %c\n",data) ;
    printf ( "Data in Binary  = ") ;
    Dectobin (data, sizeof(data)) ;               //Show Binary process
    printf ( "Size            = %d Bytes \n", sizeof(data)) ; //Show size of Unsigned Short int
    printf ( "\npress any key to continue...\n\n") ;
    getch ( ) ; //press any key to continue
	} 
	//end function Boolean
	
void Character ( ) //test data in Character
	{
    char data; // this data is variable to keep character types
    printf ("\nCharacter Mode [A-Z]\n") ;
    printf ("----------------------------------------------\n") ;
    printf ("Enter Data : ") ;
    scanf ("%c", &data) ;
    printf ("Data in Decimal = %uD \n", data) ; //Show Decimal process
    printf ("Data in Hexamal = %xH \n", data) ; //Show Hexamal process
    printf ( "character      = %c\n",data) ;
    printf ("Data in Binary  = ") ;
    Dectobin (data, sizeof(data)) ;               //Show Binary process
    printf ("Size = %d Bytes \n", sizeof(data)) ; //Show size of Unsigned Short int
    printf ("\npress any key to continue...\n\n") ;
    getch ( ) ; //press any key to continue
	} 
	//end function Charcater

void Sfloat( ) //test data in single precision Float mode
	{
    float data; //this data is variable to keep Single Precision Float types
    printf ("\nSingle Precision Float Mode [1.2E To 3.4E+38]\n") ;
    printf ("----------------------------------------------\n") ;
    printf ("Enter Data : ");
    scanf ("%f", &data);
    printf ("Data in Decimal = %uD \n", data) ; //Show Decimal process
    printf ("Data in Hexamal = %xH \n", data) ; //Show Hexamal process
    printf ("Data in Binary  = ") ;
    Dectobin (data, sizeof(data)) ;               //Show Binary process
    printf ("Size = %d Bytes \n", sizeof(data)) ; //Show size of Unsigned Short int
    printf ("\npress any key to continue...\n\n") ;
    getch ( ) ; //press any key to continue
	} 
	//end function Sfloat
	
void Double ( ) //test data in double
	{
    double data; //this data is variable to keep Double types
    printf ("\nDouble mode [1.7E-308 to 1.7E+308]\n");
    printf ("----------------------------------------------\n");
    printf ("Enter Data : ") ;
    scanf ("%le", &data) ;
    printf ("Data in Decimal = %u [D] \n", data) ; //Show Decimal process
    printf ("Data in Hexamal = %x [H] \n", data) ; //Show Hexamal process
    printf ("Data in Binary  = ") ;
    Dectobin (data, sizeof(data)) ;               //Show Binary process
    printf ("Size = %d Bytes \n", sizeof(data)) ; //Show size of Unsigned Short int
    printf ("\npress any key to continue...\n\n") ;
    getch ( ) ; //press any key to continue
	} 
	//end function Double
	
void UnsignedLongLongInt ( ) //test data in Unsigned long long integer
	{
    unsigned long long int data; //this data is variable to keep unsigned long long integer types
    printf ("\nUnsigned Long Long Integer Mode [0 to +18,446,744,073,709,551,615]\n") ;
    printf ("----------------------------------------------\n" );
    printf ("Enter Data : ") ;
    scanf ("%llu", &data );
    printf ("Data in Decimal = %uD \n", data) ; //Show Decimal process
    printf ("Data in Hexamal = %xH \n", data) ; //Show Hexamal process
    printf ("Data in Binary  = ") ;
    Dectobin (data, sizeof(data)) ;               //Show Binary process
    printf ("Size = %d Bytes \n", sizeof(data)) ; //Show size of Unsigned Short int
    printf ("\npress any key to continue...\n\n") ;
    getch () ; //press any key to continue
	} 
	//end function UnsignedLongLongint

void SignedLongLongInt ( ) //test data in signed Long long integer
	{
    signed long long int data; //this data is variable to keep signed long long integer types
    printf ("\nSigned Long Long Integer Mode \n[-9,223,372,036,854,775,807 to +9,223,372,036,854,775,807]\n") ;
    printf ("----------------------------------------------\n") ;
    printf ("Enter Data : ") ;
    scanf ("%lld", &data) ;
    printf ("Data in Decimal = %uD \n", data) ; //Show Decimal process
    printf ("Data in Hexamal = %xH \n", data) ; //Show Hexamal process
    printf ("Data in Binary  = " ) ;
    Dectobin (data, sizeof(data)) ;               //Show Binary process
    printf ("Size = %d Bytes \n", sizeof(data)) ; //Show size of Unsigned Short int
    printf ("\npress any key to continue...\n\n") ;
    getch ( ) ; //press any key to continue
	}
	 //end function SignedLongLongInt

int main ( ) //main function
	{
    printf ("\nData Representation Program...\n") ;
    printf ("------------------------------------\n") ;
    while (ch != '0')
    {
        printf ("[1] Unsigned Short Integer\n") ;
        printf ("[2] Unsigned Integer\n") ;
        printf ("[3] Boolean\n") ;
        printf ("[4] Character\n") ;
        printf ("[5] Single Precision Float\n" );
        printf ("[6] Double \n");
        printf ("[7] Unsigned Long Long Integer\n") ;
        printf ("[8] Signed Long Long Integer\n") ;

        printf ("\n") ; // new line

        ch = getch ( ) ; // Wait when keyboard passed and check it
        switch (ch)   // check ch
        {
        case '1':
            unsignedshortint ( ) ;
            break ;
        case '2':
            unsignedint ( ) ;
            break ;
        case '3':
            Boolean ( ) ;
            break ;
        case '4':
            Character ( ) ;
            break ;
        case '5':
            Sfloat ( ) ;
            break ;
        case '6':
            Double ( ) ;
            break ;
        case '7':
            UnsignedLongLongInt ( ) ;
            break ;
        case '8':
            SignedLongLongInt ( ) ;
            break ;

        } //end switch case
    }     //end while loop
    printf ( "\n" ) ;
    return (0) ;
} //end main function
