#include <iostream>

/* Bank Account Project*/

double add_money(double bank, double add);
double remove_money(double bank, double remove);

int main()
{

    // defind varible
    double balance = 5000;
    bool is_running = true;
    char user_choice;
    double amount;

    std ::cout << "*********** Bank ***********" << std ::endl;
    while (is_running)
    {
        std ::cout << "Remain : " << balance << std ::endl;
        std ::cout << "Choose Your choice" << std ::endl;
        std ::cout << "(A) : For add money" << std ::endl;
        std ::cout << "(b) : remove money" << std ::endl;
        std ::cout << "(E) : Exit" << std ::endl;
        std ::cin >> user_choice;

        user_choice = toupper(user_choice);

        if (user_choice == 'A')
        {
            std::cout << "How much money do you want to add : ";
            std::cin >> amount;
            balance = add_money(balance, amount);
        }
        else if (user_choice == 'B')
        {
            std ::cout << "How much money do you want to remove : ";
            std ::cin >> amount;
            balance = remove_money(balance, amount);
        }
        else if (user_choice == 'E')
        {
            is_running = false;
        }
        else
        {
            std ::cout << "Invalid input. Please Try Again" << std ::endl;
        }
    }
    return 0;
}

double add_money(double current_balance, double add)
{
    return current_balance + add;
}

double remove_money(double current_balance, double remove)
{
    return current_balance - remove;
}