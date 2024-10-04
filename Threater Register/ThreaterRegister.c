#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "MovieTheaterLib.h"
#include "QueueLib.h"
#include "BSTLib.h"
#include "ListLib.h"
#include "StackLib.h"

void PrintReceipts(SNODE **StackTop)
{
	/* 
	   if the StackTop is empty, the print appropriate message - see example output - 
	   else print out the receipts.  A receipt is one node of the stack and each receipt
	   consists of a receipt number, a movie theater name and a TicketList (a linked list
	   of all seats sold to one customer).  Use ReturnAndFreeLinkedListNode() to traverse 
	   the linked list stored in each stack node and display the seats and free the 
	   linked list nodes. Each call to ReturnAndFreeLinkedListNode() brings back ONE ticket 
	   from the linked list in the Ticket variable.  Call pop() to remove the stack node.
	*/
	if(*StackTop == NULL){
		printf("No receipts. \n");
	}
	while (*StackTop != NULL){
			SNODE * CurrentPtr = *StackTop;
			printf("Receipt #%d\n", CurrentPtr->ReceiptNumber);
			printf("\t%s\n", CurrentPtr->MovieTheaterName);
			char ticket[5];
			printf("\t");
			while(CurrentPtr->TicketList != NULL){
				ReturnAndFreeLinkedListNode(&CurrentPtr->TicketList, ticket);
				printf("%s ", ticket);
			}
			pop(StackTop);
			printf("\n\n");
	}




}

BNODE *PickAndDisplayTheater(BNODE *BSTRoot, char MovieTheaterMap[][MAXCOLS], int *MapRow, int *MapCol)
{
	BNODE *MyTheater = NULL;
	char zip[6] = {};
	char MyDims[6] = {};
	char* token;
	int Fileopen;
	
	printf("\n\nPick a theater by entering the zipcode\n\n");
				
	// Traverse the BST in order and print out the theaters in zip code order - use InOrder()
	InOrder(BSTRoot);
	// Prompt for a zip
	printf("Enter zipcode: ");
	scanf("%s", zip);
	getchar();
	// Call SearchForBNODE()
	MyTheater = SearchForBNODE(BSTRoot, zip);

	// If theater is not found, then print message
	if(MyTheater == NULL){
		printf("%s could not be found.\n", zip);
	}else{
	// If theater is found, then tokenize the theater's dimensions and
	// pass those dimensions and the MovieTheaterMap and the theater's filename
	// to ReadMovieTheaterFile()
		strcpy(MyDims, MyTheater->Dimensions);
		token = strtok(MyDims, "x");
		if(token != NULL){
			*MapRow = atoi(token);
		}else{
			printf("Invalid format.\n");
			goto end;
		}
		token = strtok(NULL, "");
		if(token!= NULL){
			*MapCol = atoi(token);
		}
		end:
		Fileopen = ReadMovieTheaterFile(MovieTheaterMap,MyTheater->FileName, *MapRow, *MapCol);
	// If ReadMovieTheaterFile() returns FALSE, then print
	// "Unable to print that seat map at this time.  Check back later."
	// else call PrintSeatMap()
		if(Fileopen == 0){
			printf("Unable to print that seat map at this time. Check back later.\n");
		}else{
			PrintSeatMap(MovieTheaterMap,*MapRow, *MapCol);
		}
	}

	// return the found theater
	return MyTheater;
}	

void ReadFileIntoQueue(FILE *QueueFile, QNODE **QH, QNODE **QT)
{
	//	read the passed in file and calls enQueue for each name in the file
	char Buffer[100];
	while (fgets(Buffer, 100, QueueFile)){
		enQueue(Buffer, QH, QT);
	}

}

void ReadFileIntoBST(FILE *BSTFile, BNODE **BSTnode)
{
	//	read the passed in file and tokenize each line and pass the information to AddBSTNode
	char Buffer[100];
	char* token;
	char MTN[100];
	char ZC[20];
	char FN[30];
	char DIM[10];
	while(fgets(Buffer, 100, BSTFile)){
		token = strtok(Buffer,"|");
		if(token != NULL){
			strcpy(MTN, token);
		}else{
			printf("Invaild format.\n");
			continue;
		}
		token = strtok(NULL, "|");
		if (token != NULL){
			strcpy(ZC, token);
		}else{
			printf("Invalid format.\n");
			continue;
		}
		token = strtok(NULL, "|");
		if (token != NULL){
			strcpy(FN, token);
		}else{
			printf("Invalid format.\n");
			continue;
		}
		token = strtok(NULL, "|");
		if(token != NULL){
			strcpy(DIM, token);
		}else{
			printf("Invalid format.\n");
			continue;
		}
	AddBSTNode(BSTnode,MTN, ZC, FN, DIM);
	}
}

void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
	int i = 0; 
	
	while (argv[++i] != NULL)
	{
		if (!strncmp(argv[i], ParamName, strlen(ParamName)))
		{
			strcpy(ParamValue, strchr(argv[i], '=') + 1);
		}
	}
}

int PrintMenu()
{
	int choice = 0;
	
	printf("\n\n1.	Sell tickets to next customer\n\n");
	printf("2.	See who's in line\n\n");
	printf("3.	See the seat map for a given theater\n\n");
	printf("4.	Print today's receipts\n\n");
	printf("Choice : ");
	scanf("%d", &choice);
	
	while (choice < 1 || choice > 4)
	{
		printf("Invalid choice.  Please reenter. ");
		scanf("%d", &choice);
	}
	
	return choice;
}

int main(int argc, char *argv[])
{
	int i, j, k;
	FILE *queueFile = NULL;
	FILE *zipFile = NULL;
	char arg_value[20];
	char queuefilename[20];
	char zipfilename[20];
	int ReceiptNumber = 0;
	int choice = 0;
	int SeatNumber;
	char Row;
	char Ticket[5];
	int ArrayRow, ArrayCol;
	int MapRow, MapCol;
	char MovieTheaterMap[MAXROWS][MAXCOLS] = {};
	LNODE *TicketLinkedListHead = NULL;
	QNODE *QueueHead = NULL;
	QNODE *QueueTail = NULL;
	BNODE *BSTRoot = NULL;
	BNODE *MyTheater = NULL;
	SNODE *StackTop = NULL;
	int NumberOfTickets = 0;
	
	if (argc != 4)
	{
		printf("%s QUEUE=xxxxxx ZIPFILE=xxxxx RECEIPTNUMBER=xxxxx\n", argv[0]);
		exit(0);
	}
	
	get_command_line_parameter(argv, "QUEUE=", queuefilename);
	get_command_line_parameter(argv, "ZIPFILE=", zipfilename);
	get_command_line_parameter(argv, "RECEIPTNUMBER=", arg_value);
	ReceiptNumber = atoi(arg_value);
		
	/* call function to open queuefilename - if it does not open, print message and exit */	
	queueFile = fopen(queuefilename, "r");
	if (queueFile == NULL){
		printf("%s could not be open.\n", queuefilename);
	}else{
		ReadFileIntoQueue(queueFile, &QueueHead, &QueueTail);
	}

	/* calll function to open zipfilename - if it does not open, print message and exit */
	zipFile = fopen(zipfilename, "r");
	if (zipFile == NULL){
		printf("%s could not be open.\n",zipfilename);
	}else{
		ReadFileIntoBST(zipFile, &BSTRoot);
	}


	
	while (QueueHead != NULL)
	{
		choice = PrintMenu();
	
		switch (choice)
		{
			case 1 :
				printf("\n\nHello %s\n", QueueHead->name);				
				MyTheater = PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);			
				if (MyTheater != NULL)
				{
					printf("\n\nHow many movie tickets do you want to buy? ");
					scanf("%d", &NumberOfTickets);
					for (i = 0; i < NumberOfTickets; i++)
					{
						do
						{
							printf("\nPick a seat (Row Seat) ");
							scanf(" %c%d", &Row, &SeatNumber);
							Row = toupper(Row);
							ArrayRow = (int)Row - 65;
							ArrayCol = SeatNumber - 1;
							printf(" ArrayRow %d ArrayCol %d\n", ArrayRow, ArrayCol);
						
							if ((ArrayRow < 0 || ArrayRow >= MapRow) ||
								(ArrayCol < 0 || ArrayCol >= MapCol))
							{
								printf("\nThat is not a valid seat.  Please choose again\n\n");
							}		
						}
						while ((ArrayRow < 0 || ArrayRow >= MapRow) ||
							   (ArrayCol < 0 || ArrayCol >= MapCol));
						
						if (MovieTheaterMap[ArrayRow][ArrayCol] == 'O')
						{	
							MovieTheaterMap[ArrayRow][ArrayCol] = 'X';
							sprintf(Ticket, "%c%d", Row, SeatNumber); 
							InsertNode(&TicketLinkedListHead, Ticket);
						}
						else
						{
							printf("\nSeat %c%d is not available.\n\n", Row, SeatNumber);
							i--;
						}
						PrintSeatMap(MovieTheaterMap, MapRow, MapCol);
					}
					
					WriteSeatMap(MyTheater, MovieTheaterMap, MapRow, MapCol);
					push(&StackTop, TicketLinkedListHead, ReceiptNumber, MyTheater->MovieTheaterName);
					TicketLinkedListHead = NULL;
					ReceiptNumber++;
					printf("\nThank you %s - enjoy your movie!\n", QueueHead->name);
					deQueue(&QueueHead);
				}
				break;
			case 2 : 
				printf("\n\nCustomer Queue\n\n");
				DisplayQueue(QueueHead);
				printf("\n\n");
				break;
			case 3 :
				PickAndDisplayTheater(BSTRoot, MovieTheaterMap, &MapRow, &MapCol);
				break;
			case 4 : 
				PrintReceipts(&StackTop);
				break;
			default :
				printf("Bad menu choice");
		}
	}
	
	printf("Good job - you sold tickets to all of the customers in line.\n");
	PrintReceipts(&StackTop);
	
	return 0;
}
