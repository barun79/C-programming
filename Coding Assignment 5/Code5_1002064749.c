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
	/* Call DashIt and pass in Phrase and DashedPhrase */
	/* uppercase Phrase */

	// Checking the CheckPhrase Function
	char check[50] ="Barun-Singh";
	CheckPhrase(check);
	
	// printf("\nHere's the phrase you need to guess\n");

	// do
	// {
	// 	/* if !(call GuessALetter and pass Phrase, DashedPhrase and UpperPhrase) */
	// 	{
	// 		Strikes++;
	// 		printf("\nStrike %d", Strikes);
	// 	}
	// }
	// /* while (call strchr() with DashedPhrase with -) AND strike counter is less than strikes define */

	// if (Strikes < STRIKES)
	// {
	// 	printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
	// 	printf("\n\nYOU WIN!!!!\n");
	// }
	// else
	// {
	// 	printf("\n\n");
	// 	printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
	// 	printf("Game over\n\n");
	// }
	return 0;
}
