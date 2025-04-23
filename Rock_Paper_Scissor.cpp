#include <iostream>
#include <ctime>

int get_inputuser();
int get_inputcomputer();
void check_winner(int player, int computer);
bool play_Again();

int main()
{

    int player;
    int computer;

    bool again = false;
    do
    {
        player = get_inputuser();
        computer = get_inputcomputer();

        check_winner(player, computer);

        std ::cin.clear();
        fflush(stdin);

        again = play_Again();

    } while (!again);

    return 0;
}

int get_inputuser()
{

    int choice;
    std ::cout << "************* Rock Paper Scissor Game *************" << std ::endl;
    std ::cout << "1. Rock" << std ::endl;
    std ::cout << "2. Paper" << std ::endl;
    std ::cout << "3. Scissor" << std ::endl;
    std ::cout << "Enter Your choice : ";

    std ::cin >> choice;
    if (choice == 1)
    {
        return 1;
    }
    else if (choice == 2)
    {
        return 2;
    }
    else if (choice == 3)
    {
        return 3;
    }
    else
    {
        std ::cout << "Invalid Input" << std ::endl;
        return 0;
    }
}

int get_inputcomputer()
{

    srand(time(0));

    int com = rand() % 4;

    if (com == 0)
    {
        return 1;
    }
    return com;
}

void check_winner(int player, int computer)
{
    switch (player)
    {
    case 1:
        switch (computer)
        {
        case 1:
            std::cout << "Draw !" << std ::endl;
            break;
        case 2:
            std::cout << "You lost !" << std ::endl;
            break;
        case 3:
            std::cout << "You Won !" << std ::endl;
            break;

        default:
            break;
        }
        break;
    case 2:
        switch (computer)
        {
        case 1:
            std::cout << "You Won !" << std ::endl;
            break;
        case 2:
            std::cout << "Draw !" << std ::endl;
            break;
        case 3:
            std::cout << "You Lost !" << std ::endl;
            break;

        default:

            break;
        }
        break;
    case 3:
        switch (computer)
        {
        case 1:
            std::cout << "You Lost !" << std ::endl;
            break;
        case 2:
            std::cout << "You Win!" << std ::endl;
            break;
        case 3:
            std::cout << "Draw !" << std ::endl;
            break;

        default:

            break;
        }
        break;
    default:

        break;
    }
}

bool play_Again()
{
    char again_c;
    std ::cout << "Play Again ? (Y/n): ";
    std ::cin >> again_c;
    std ::cin.clear();
    fflush(stdin);
    again_c = toupper(again_c);
    if (again_c == 'Y')
    {
        return false;
    }
    else if (again_c == 'N')
    {
        return true;
    }
    else
    {
        return true;
    }
}