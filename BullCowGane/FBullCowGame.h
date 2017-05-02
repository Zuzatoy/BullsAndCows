#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowsCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_LowerCase
};



class FBullCowGame
{
public:

	FBullCowGame(); //constractor

	int32 GetMaxTries() const;
	int32 GetCurentTry() const;
	bool IsGameWon() const;

	void Reset();
	EGuessStatus CheckGuessValibility(FString);

	FBullCowsCount SubmitGuess(FString);


private:
	// see constractor for initialisation
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;




};