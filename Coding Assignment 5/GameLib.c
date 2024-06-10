/* Barun Singh 1002064749*/

#include "GameLib.h"

void StartGame(char ChosenPhrase[])
{
	char DashPhrase[MAX_INPUT] = {};
	int i = 0;
	int Choice = 0;
		
	/* put an include here to include PhraseBank.txt in your program */
	#include "PhraseBank.txt"

	printf("\n\nWelcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n", STRIKES);
	
	printf("Please pick a phrase from the following menu\n\n");
	
	/* while PhraseBank[i] is not empty "" */
	while (PhraseBank[i] != 0)
	{
		/* Call CheckPhrase with PhraseBank[i] */
		CheckPhrase(PhraseBank[i]);
		/* Call DashIt with PhraseBank[i] and DashPhrase */
		printf("%d.\t%s\n", i+1, DashPhrase);
		i++;
	}
	
	printf("\nEnter choice : ");
	scanf("%d", &Choice);
	getchar();
	
	/* create a while condition that is true when Choice is less than 1 or greater than i */
	{
		printf("You entered an invalid choice.\nPlease reenter ");
		scanf("%d", &Choice);
	}
	
	/* copy the phrase from PhraseBank based on Choice into ChosenPhrase */ 	
}

void CheckPhrase(char *Phrase)
{
	/* Declare a char pointer named FindDash and initialize it to NULL */
	char * FindDash = NULL;
	
	/* call strchr() with Phrase and a dash and store the result in FindDash.  If that */
	/* value is not NULL, then you found a dash                                        */
	FindDash = strchr(Phrase, '-');
	if (FindDash != NULL)
	{
		printf("\n\"%s\" contains a dash in position %d!!\n", Phrase, abs(Phrase-FindDash)+1);
		printf("\nYou broke the rules.  We can't play.  BYE!!\n\n");
		/* exit the program */
		exit(1);
	}
}

int GuessALetter(char Phrase[], char DashedPhrase[], char UpperPhrase[])
{
	char Guess;
	char *FindGuess = NULL;
	char UpperPhraseCopy[MAX_INPUT];
	int FoundALetter = 0;
	
	/* copy UpperPhrase into UpperPhraseCopy */
		
	printf("\n\n%s", DashedPhrase);	
	printf("\n\nGuess a letter : ");
	scanf(" %c", &Guess);
	getchar();
	/* uppercase Guess */

	/* Use strchr() to look for Guess in UpperPhraseCopy.  Store the result of strchr() */
	/* in FindGuess                                                                     */
	
	/* while FindGuess is not NULL */
	{
		FoundALetter = 1;
		DashedPhrase[FindGuess - UpperPhraseCopy] = Phrase[FindGuess - UpperPhraseCopy];
		/* Dereference FindGuess and set it to a dash */

		/* Call strchr() again */
	}
	
	return FoundALetter;
}

void DashIt(char *Phrase, char DashPhrase[])
{
	char *ReplaceIt;
	char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;

	/* Put the uppercase version of Phrase into DashPhrase */

	/* Call strpbrk() with DashPhrase and Alphabet and save the result in ReplaceIt */

	/* while ReplaceIt is not NULL */
	{
		/* Dereference ReplaceIt and set it to a dash */
		/* Call strpbrk() again */
	}
}
