/* ListLib-Template */

#include "ListLib.h"

/* add return type */  void AddDrawCommandToList(/* Add parameters */ char Letter, char DrawCommand[], NODE** LinkedListHead)
{
    NODE *TempPtr, *NewNode;
	/* declare pointers of type NODE named TempPtr and NewNode */
    
	/* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */
	NewNode = (NODE*)malloc(sizeof(NODE));
	if(NewNode == NULL){
		printf("Memory allocation failed.\n");
		return;
	}
	NewNode->Letter = Letter;
	NewNode->DrawCommand = (char*)malloc(strlen(DrawCommand)+1);
	if(NewNode->DrawCommand == NULL){
		printf("Memory allocation failed.\n");
		free(NewNode);
	}
	strcpy(NewNode->DrawCommand, DrawCommand);
	NewNode->next_ptr = NULL;

	/* If the LinkedListHead is NULL, then give it the address of the new node */
	if(*LinkedListHead == NULL){
		*LinkedListHead = NewNode;
	}else{
		TempPtr = *LinkedListHead;
		while(TempPtr->next_ptr != NULL){
			TempPtr = TempPtr->next_ptr;
		}
		TempPtr->next_ptr = NewNode;
}
	/* Else traverse to the end of the linked list and add the new node */
}


/* add return type */  
NODE *FindLetter(/* Add parameters */ NODE *LinkedListHead, char Letter, char DC[] )
{
	NODE* TempPtr = LinkedListHead;
	/* while traversing the linked list AND the Letter in the node is not the Letter passed in */
	while(TempPtr != NULL && TempPtr->Letter != Letter)
	{
		TempPtr = TempPtr->next_ptr;
		/* move TempPtr */
	}

	if (/* TempPtr is not NULL */ TempPtr != NULL)
	{
		/* copy the DrawCommand from the node into the passed in parameter */
		strcpy(DC, TempPtr->DrawCommand);
		/* return the next pointer stored in TempPtr */
		return TempPtr->next_ptr;
	}
	else
	{
		memset(DC, '\0', sizeof(*DC));  //Set DC to NULLs to signal that we found all of the nodes for this letter
		/* return TempPtr */
		return TempPtr;
	}
}
