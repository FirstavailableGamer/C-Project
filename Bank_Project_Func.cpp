#include <iostream>
#include <limits>  // สำหรับ std::numeric_limits
#include <string>
#include <sstream>
#include <iomanip>


int get_Choice();
void Bank_start();
void show_money(double amout);
double withdraw_money();
double Deposite();

int main()
{

    Bank_start();

    return 0;
}

void Bank_start()
{
    int choice;
    double MONEY_REMAIN = 0;
    double amount;
    bool exit = false;
    std ::cout << "************* BANK *************" << std ::endl;
    do
    {

        choice = get_Choice();

        if (choice == 1)
        {
            show_money(MONEY_REMAIN);
        }
        else if (choice == 2)
        {
            amount = Deposite();
            MONEY_REMAIN += amount;
            show_money(MONEY_REMAIN);
        }
        else if (choice == 3)
        {
            amount = withdraw_money();
            if (MONEY_REMAIN >= amount)
            {
                MONEY_REMAIN -= amount;
            }
            else
            {
                std :: cout << "You dont have enough money." << std :: endl;
            }
            show_money(MONEY_REMAIN);
        }
        else if (choice == 4)
        {
            exit = true;
        }
        else
        {
            std ::cout << "Invalid Input" << std ::endl;
        }
    } while (!exit);
    std ::cout << "************* BANK *************" << std ::endl;
}

int get_Choice()
{
    // std::string input; // second choice for clear input buffer
    int choice;
    std ::cout << "1 . Money Balance." << std ::endl;
    std ::cout << "2 . Deposit Money." << std ::endl;
    std ::cout << "3 . Withdraw Money." << std ::endl;
    std ::cout << "4 . Exit." << std ::endl;
    
    std:: cout << "Enter your choice : " ;
    std :: cin >> choice;
    std :: cin.clear();
    fflush(stdin);
    return choice;
    // std::getline(std::cin, input); // รับทั้งหมดเป็นสตริง

    // std::stringstream ss(input);
    // if (ss >> choice && ss.eof())
    // {
    //     return choice;
    // }
    // else
    // {   
    //     return -1; // Give number for check
    // }
}

void show_money(double MONEY_REMAIN)
{
   
    std::cout << "Your balance is: $"<< std::setprecision(2) << std::fixed << MONEY_REMAIN << '\n';

}

double withdraw_money()
{

    double amount;
    std ::cout << "How much money do you want to withdraw : ";
    std ::cin >> amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (amount >= 0)
    {
        return amount;
    }
    else
    {
        
        std ::cout << "Invalid Value" << std ::endl;
        return 0;

    }
}

double Deposite()
{
    double amount;
    std ::cout << "How much money do you want to Deposite : ";
    std ::cin >> amount;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (amount >= 0)
    {
        return amount;
    }
    else
    {
        std ::cout << "Invalid Value" << std ::endl;
        return 0;
    }
}
