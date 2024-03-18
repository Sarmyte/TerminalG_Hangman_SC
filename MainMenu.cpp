#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
using namespace std;

//Creating Variables: Words Database.
string wordsDB[2][10] =
{
		{"Deer"},
		//{"Cat", "Bear", "Camel", "Donkey", "Rabbit", "Zebra", "Deer", "Squirrel", "Horse", "Cheetah"}, //Row1
		{"Puding", "Pasta", "Cheese", "Sandwich", "Yogurt", "Kebab", "Pancake", "Pizza", "Seafood", "Rice"} //Row2
	};
//Creating Variables: Word Types.
	string wordsT[2] =
	{"Animal", "Food"};

//Word Storages.
	int wordSH; //Stores word size.
	string wordTH, wordH; //Stores word type, //Stores the word.
	string wordMasked; //Stores a Masked word.
	char letter; //Stores guessed letters.
	string failedLetters; //Stores in a string to showcase failed guesses.
	bool isInWord = false, isInMask = false, isInFailed = false; //Checks if the letter has already been guessed

//Creating Variables: World Variables.
	int wdbRows = sizeof(wordsDB) / sizeof(wordsDB[0]); //Row Size.
	int wdbCols = sizeof(wordsDB[0]) / sizeof(wordsDB[0][0]); //Col Size.
	int option = 0; //Used on SCases on Menus.
	int cont = 0; //Used for Counting.
	

//Function: Cleaning Screen.
void fSCleaner()
{
	system("CLS");
}

void  fWrongGuessDisplay()
{
	cout << "Wrong guesses: ";
	if(failedLetters.size() > 0)
	{
		for (cont = 0; cont < failedLetters.size(); cont++)
		{
			cout << failedLetters[cont] << ", ";
		}
	}
	cout << "\n";
}

//Function: Unmasking wordMask
string fWordReveal()
{
	for (cont = 0; cont < wordH.size(); cont++)
	{
		if (wordH[cont] == letter)
		{
			wordMasked[cont] = wordH[cont];
		}
	}
	return wordMasked;
}

//Function: Word Masking
string fWordMask()
{
	cont = 0;
	if (wordMasked.size() < wordH.size())
	{
		while (cont < wordH.size())
		{
			wordMasked += "_";
			cont++;
		}
	}
	return wordMasked;
}

//Function: Generating a random Word.
string fRandomWord()
{
	int randomRow = rand() % wdbRows;
	int randomCol = rand() % wdbCols;
	return wordH = wordsDB[randomRow][randomCol], wordTH = wordsT[randomRow];
}

//Function: Choosing a type of Word.
string fChooseWType()
{
	int randomCol = rand() % wdbCols;
	return wordH = wordsDB[option - 1][randomCol], wordTH = wordsT[option - 1];
}

//Function: Game Screen
void fGameScreen()
{
	int chancesRemaining = wordH.size() * 2;
	while (chancesRemaining > 0)
	{
		cout << "GAME ON!\n";
		cout << "You can guess a Letter or the entire word.\n";
		cout << "Your word is a " << wordTH << " with " << wordH.size() << " letters\n\n";
		cout << "Remaining Guesses: " << chancesRemaining << "\n";
		fWrongGuessDisplay();
		cout << "Word: " << fWordMask() << "\n";
		cout << "Guess: ";
		cin >> letter;

		cont = 0;
		while (cont < wordH.size())
		{
			if (letter == wordH[cont])
			{
				cout << "vezes in word\n";
				isInWord = true;
			}
			cont++;
		}

		if (isInWord == true)
		{
			cont = 0;
			while (cont < wordMasked.size())
			{
				if (letter == wordMasked[cont])
				{
					cout << "vezes in Mask\n";
					isInMask = true;
				}
				cont++;
			}
		}
		else
		{
			cont = 0;
			while (cont < failedLetters.size() + 1)
			{
				if (letter == failedLetters[cont])
				{
					cout << "vezes not in failed\n";
					isInFailed = true;
				}
				cont++;
			}
		}

		if (isInMask == false)
		{
			cout << "vezes in Mask2\n";
			fWordReveal();
			chancesRemaining--;
		}

		if (isInFailed == false)
		{
			cout << "vezes in failed2\n";
			failedLetters += letter;
			chancesRemaining--;
		}






			fSCleaner();
	}
	//Loss Condition
	if (chancesRemaining == 0)
		{
		fSCleaner();
		cout << "!BETTER LUCK NEXT TIME!\n";
		cout << "!!!!!!!!YOU LOST!!!!!!!\n\n";
		}
	//Win Condition
	if (fWordReveal() == wordH)
	{
		fSCleaner();
		cout << "!CONGRATULATIONS!\n";
		cout << "!!!!!YOU WON!!!!!\n\n";
	}
}

//Function: Solo Menu.
void fPlaySoloMenu()
{
	option = 0;
	while (option < 1 || option > 3)
	{
		fSCleaner();

		cout << "Choose the type of word you want to guess\n";
		cout << "1 - Animal \n";
		cout << "2 - Food\n";
		cout << "3 - Random\n";
		cout << "Choose your option and press ENTER: ";

		cin >> option;

		switch (option)
		{
		case 1:
			fSCleaner();
			fChooseWType();
			fGameScreen();
			break;
		case 2:
			fSCleaner();
			fChooseWType();
			fGameScreen();
			break;
		case 3:
			fSCleaner();
			fRandomWord();
			fGameScreen();
			break;
		}
	}
}

//Function: Main Menu.
void fMainMenu()
{
	 option = 0;

	while (option < 1 || option > 3)
	{
		fSCleaner();

		cout << "\t\tWelcome to the Hangman Game.\n";
		cout << "1 - Play\n";
		cout << "2 - About\n";
		cout << "3 - Quit\n";
		cout << "Choose your option and press ENTER: ";

		cin >> option;

		switch (option)
		{
		case 1:
			fPlaySoloMenu();
			break;
		case 2:
			cout << "About the game\n";
			break;
		case 3:
			cout << "You just left the game\n";
			break;
		}
	}

}

//Main.
int main()
{
//Generates random numbers
	srand((unsigned)time(NULL));
	fMainMenu();
}