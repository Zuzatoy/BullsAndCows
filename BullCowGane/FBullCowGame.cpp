#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();

}


void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	const FString HIDEN_WORD = "ant";
	MyHiddenWord = HIDEN_WORD;
	
	MyCurrentTry = 1;
	return;
}

FBullCowsCount FBullCowGame::SubmitGuess(FString guess)
{
	// Incriment the turn number
	MyCurrentTry++;
	// Setup and return the variables
	FBullCowsCount BullCowCount;
	//loop through all letter in the loop
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		//compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (guess[i] == MyHiddenWord[i])
			{
				if (i ==j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			} 
	
		}

	}
	
	return BullCowCount;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValibility(FString)
{
	return false;
}
