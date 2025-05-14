#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>

std::vector<char> getRandomWord(std::vector<std::string> words);
void displayEmptySpace(std::vector<char>* emptys);
void displayhangman(int wrong_guess);
void getInput(std::vector<char>* word, std::vector<char>* emptys,int attemps);
bool checkWin(std::vector<char>* emptys);

int main()
{
	// Hangman Game
	std::vector<std::string> words{ "KEYBORD", "MOUSE", "COMPUTER" };
	std::vector<char> word = getRandomWord(words);
	std::vector<char> emptys(word.size(), '_');
	int attemps = 6;

	displayEmptySpace(&emptys);
	getInput(&word, &emptys, attemps);




	return 0;
}


std::vector<char> getRandomWord(std::vector<std::string> words)
{
	srand(time(NULL));
	int index = rand() % words.size();
	std::string word_str = words[index];
	std::vector<char> word;

	for (int i = 0; i < word_str.length(); i++)
	{
		word.push_back(word_str[i]);
	}
	return word;
}

void displayEmptySpace(std::vector<char> *emptys)
{
	//display empty spcae
	for (char empty : *emptys)
	{
		std::cout << empty << " ";
	}
	std::cout << std::endl;
}

void displayhangman(int wrongGuesses)
{
	std::string hangman[7] = {
		"  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========",
		"  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",
		"  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",
		"  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========",
		"  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",
		"  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",
		"  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="
	};
	std::cout << hangman[wrongGuesses] << std::endl;

}

void getInput(std::vector<char> *word, std::vector<char>* emptys, int attemps)
{
	int wrong_guesses = 0;
	char guess;
	for (int i = attemps; i > 0; i--)
	{

		displayhangman(wrong_guesses);

		std::cout << "\n\nYou Have " << i << " attemp To enter : ";

		// clear in put buffer
		std::cin.clear();

		//Get only first char
		guess = std::cin.get();

		//clear the rest of the line
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//To upper case
		guess = toupper(guess);

		bool correct_guess = false;

		for (int j = 0; j < word->size(); j++)
		{
			if (guess == (*word)[j])
			{
				(*emptys)[j] = guess;
				i++;
				correct_guess = true;
			}
			
		}

		if (!correct_guess) {
			wrong_guesses++;
		}

		//Check WIN
		if (checkWin(emptys)) 
		{

			displayEmptySpace(emptys);
			std::cout << "\nYou won Hangman is safe now" << std::endl;
			break;
		}


		displayEmptySpace(emptys);
	}
	//Check Lost
	if (!checkWin(emptys))
	{
		displayhangman(wrong_guesses);
		std::cout << "\nYou Lost Hangman is dead" << std::endl;
	}
	
}

bool checkWin(std::vector<char>* emptys)
{
	// Return true when NO underscores are found (player has won)
	return std::find(emptys->begin(), emptys->end(), '_') == emptys->end();
}
