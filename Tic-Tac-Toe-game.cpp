#include <iostream>
#include <ctime>

void drawBord(char *spaces);
void playerMove(char* spaces, char player);
void comMove(char* spaces, char computer);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);

int main()
{
	char spaces[9] = { ' ' , ' ', ' ', ' ', ' ', ' ', ' ', ' ',' '};
	char player = 'X';
	char computer = 'O';
	bool running = true;

	drawBord(spaces);

	while (running)
	{
		playerMove(spaces, player); 
		if (checkWinner(spaces, player, computer))
		{
			drawBord(spaces);
			running = false;
			break;
			
		}
		else if(checkTie(spaces))
		{
			drawBord(spaces);
			running = false;
			break;
		}

		comMove(spaces, computer);
		drawBord(spaces);
		if (checkWinner(spaces, player, computer))
		{
			
			running = false;
			break;
		}
		else if (checkTie(spaces))
		{
			
			running = false;
			break;
		}
	}

	return 0;
}

void drawBord(char* spaces)
{
	std::cout << "     |     |      " << std::endl;
	std::cout << "  "<<spaces[0]<<"  |  " << spaces[1] << "  |  " << spaces[2] << "   " << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |      " << std::endl;
	std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "   " << std::endl;
	std::cout << "_____|_____|_____" << std::endl;
	std::cout << "     |     |      " << std::endl;
	std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "   " << std::endl;
	std::cout << "     |     |      " << std::endl;
	std::cout << std::endl;

}
void playerMove(char* spaces, char player)
{
	int number;
	do
	{
		std::cout << "Enter a spot to place a marker (1-9) : ";
		std::cin >> number;
		number--;
		if (spaces[number] == ' ')
		{
			spaces[number] = player;
			break;
		}
	} while (!number > 0 || !number < 8);
}
void comMove(char* spaces, char computer)
{
	int number;
	srand(time(0));
	
	while (true) 
	{
		number = rand() % 9;
		if (spaces[number] == ' ')
		{
			spaces[number] = computer;
			break;
		}
	}

}
bool checkWinner(char* spaces, char player, char computer)
{
	if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2]))
	{
		spaces[0] == player ? std::cout << "--------\nYou win\n--------" << std::endl : std::cout << "-------\nYou Lose\n-------" << std::endl;
	}
	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5]))
	{
		spaces[3] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "-------\nYou Lose\n-------" << std::endl;
	}
	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8]))
	{
		spaces[6] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "-------\nYou Lose\n-------" << std::endl;
	}
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6]))
	{
		spaces[0] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "-------\nYou Lose\n-------" << std::endl;
	}
	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7]))
	{
		spaces[1] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "-------\nYou Lose\n-------" << std::endl;
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8]))
	{
		spaces[2] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "---------\nYou Lose\n---------" << std::endl;
	}
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8]))
	{
		spaces[0] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "-------\nYou Lose\n-------" << std::endl;
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6]))
	{
		spaces[2] == player ? std::cout << "-------\nYou win\n-------" << std::endl : std::cout << "-----\nYou Lose\n-----" << std::endl;
	}
	else
	{
		return 0;
	}
	return 1;
}
bool checkTie(char* spaces)
{
	if (spaces[0] != ' ' && spaces[1] != ' ' && spaces[2] != ' '&&
		spaces[3] != ' ' && spaces[4] != ' ' && spaces[5] != ' '&&
		spaces[6] != ' ' && spaces[7] != ' ' && spaces[8] != ' ')
	{
		std::cout << "--------\nTie!\n-------"<<std::endl;
		return true;
	}
	return false;
}