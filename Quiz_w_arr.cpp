#include <iostream>



int main() 
{

	std::string question[] =	{"1. What year was c++ created : ",
								"2.  ",
								"3.  ",
								"4. "};
	std::string option[][4] = { {"A. 1969", "B. 1975", "C. 1985", "D. 1989"},
								{"A. C", "B. C", "C.  ", "D. C"},
								{"A.", "B. A", "C. A", "D. A"},
								{"A. ", "B. "}};

	char anwserKey[] = { 'C', 'B', 'A', 'B' };
	int size_q = sizeof(question) / sizeof(question[0]);
	char guess;
	int score = 0;

	for (int i = 0; i < size_q; i++)
	{
		for (int j = 0; j < sizeof(option[i]) / sizeof(option[i][0]); j++) {
			std::cout << option[i][j] << std::endl;
		}
		std::cout << question[i];
		std::cin >> guess;
		guess = toupper(guess);

		if (anwserKey[i] == guess)
		{
			score += 1;
		}
	}

	std::cout << "\nYou get score : " << score;

	return 0;
}
