#include <iostream>
#include<string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void printIntro();
void playGame();
FText getGuess();
bool askToPlayAgain();

FBullCowGame BCGame; // Instatiation

// the antry point for our application
int main()
{
	std::cout << BCGame.GetCurentTry();
	bool bWantsToPlayAgain = false;
	do
	{
		printIntro();
		playGame();
		bWantsToPlayAgain = askToPlayAgain();
	} while (bWantsToPlayAgain);
	

	int32 iTemp;
	std::cin >> iTemp;
	return 0;


}

// intridaction the game
void printIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Please try to guess the " << WORD_LENGTH;
	std::cout << " letter isogram I thinking of?\n";
	std::cout << std::endl;
	return;
}


void playGame()
{
	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns asking for guesses
	

	for (int32 i = 1; i <= MaxTries; i++)
	{
		FText guess = getGuess();

		EGuessStatus Status = BCGame.CheckGuessValibility(guess); 

		switch (Status)
		{
		case EGuessStatus::OK:
			break;
		case EGuessStatus::Not_Isogram:
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.
			break;
		case EGuessStatus::Not_LowerCase:
			break;
		default:
			break;
		}


		FBullCowsCount BullCowCount =  BCGame.SubmitGuess(guess);

		std::cout << "Bulls:" << BullCowCount.Bulls;
		std::cout << "  Cows:" << BullCowCount.Cows << std::endl;
		std::cout << std::endl;

	}
}

FText getGuess()
{
	int32 CurrentTry = BCGame.GetCurentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess";
	FText guess = " ";
	std::getline(std::cin, guess);
	return guess;

}

bool askToPlayAgain()
{
	
    std::cout << "Do you want to play again (y/n)?";
	FText Response = " ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
	
}



