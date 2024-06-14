// FileLib Template
#include "FileLib.h"

/* return type */ 
FILE *OpenFile(int argc , char* argv[] )
{	
	/* declare various variables needed */
	char filename[100];
	FILE* fptr = NULL;

	/* if argc is 2, then use argv[1] as the input file name, else print the message seen in sample output */
	if (argc == 2){
		strcpy(filename, argv[1]);
	} else{
		printf("Must be run with an input file name. \nEnter a file name a the prompt ");
		scanf("%s", filename);
		getchar();
	}

	do
	{
		/* open file with "r" mode */
		fptr = fopen(filename, "r");
		/* if file did not open */
		if(fptr == NULL)
		{
			/* print message seen in sample output */
			printf("Could not open input filed %s", filename);
			/* read in new filename */
			scanf("%s", filename);
			getchar();
			/* open the file "r" mode */
			fptr = fopen(filename, "r");
		}
	}
	while (/* file is not open */ fptr == NULL);

	return fptr;

	/* return the file handle */
}

/* return type */
void ReadFileIntoLinkedList(FILE* DCFile , NODE ** LinkListHead)
{
	/* declare various variables needed */
	char buffer[100];
	char *token;
	char Letter;
	char DrawCommand[100];
	
	/* while fgets() reads the file */
	while (fgets(buffer, 100, DCFile))
	{
		/* if line from file ends with \n, then replace \n with \0 */
			int len = strlen(buffer);
			if(buffer[len -1] == '\n'){							
				buffer[len-1]= '\0';
			}

		/* tokenize to get the Letter and the DrawCommand */
		token = strtok(buffer, "|");
		if(token != NULL){
			Letter = token[0];
			token = strtok(NULL, "");
			if(token != NULL){
				strcpy(DrawCommand, token);
			}
		}
	
		/* Call AddDrawCommandToList with correct parameters */
		AddDrawCommandToList(Letter,DrawCommand, LinkListHead);
	}
}

