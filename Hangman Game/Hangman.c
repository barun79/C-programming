/* Coding Assignment 5 */

/* Add necessary includes */
#include<stdio.h>
#include "GameLib.h"

int main(void)
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int Strikes = 0;
	int i;
	
	/* Call StartGame and pass in Phrase */
	StartGame(Phrase);

	/* Call DashIt and pass in Phrase and DashedPhrase */
	DashIt(Phrase, DashedPhrase);
	/* uppercase Phrase */
	int y = 0;
	while(Phrase[y] != '\0'){
		UpperPhrase[y] = toupper(Phrase[y]);
		y++;
	}
	
	printf("\nHere's the phrase you need to guess\n");

	do
	{
		/* if !(call GuessALetter and pass Phrase, DashedPhrase and UpperPhrase) */
		if (!GuessALetter(Phrase,DashedPhrase,UpperPhrase))
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
	}
	/* while (call strchr() with DashedPhrase with -) AND strike counter is less than strikes define */
	while(strchr(DashedPhrase, '-') != NULL && Strikes < STRIKES);

	if (Strikes < STRIKES)
	{
		printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
		printf("\n\nYOU WIN!!!!\n");
	}
	else
	{
		printf("\n\n");
		printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
		printf("Game over\n\n");
	}
	return 0;
}
