/**
 * @file Source.cpp
 * @author Finn Baldwin
 * @date 2026-03-10
 * @brief A banking simulation interacting with Account and Customer objects.
 */

#include<iostream>
#include "Account.h"

using namespace std;

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
 * @brief Entry point for the banking simulation
 * @param None
 * @return 0 when sucessful
 */
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        {
            double depositAmount;

            cout << "Enter the amount you would like to deposit: $";
            cin >> depositAmount; 

            if (isAmountValid)
            {
                account.deposit(depositAmount);
                cout << "Deposit successful\n";
            }

            else
            {
                cout << "Invalid amount. Your deposit must be greater than 0.\n";
            }
            break;
        }
        case WITHDRAWAL:
            {
            double withdrawlAmount;

            cout << "Enter the amount you would like to withdrawl: $";
            cin >> withdrawlAmount; 

            if (isAmountValid)
            {
                account.withdraw(withdrawlAmount);
                cout << "Withdrawl successful\n";
            }

            else
            {
                cout << "Invalid amount. Your withdrawl must be greater than 0.\n";
            }
            break;
        }
        case CLOSE_OF_BUSINESS:
            {
            account.closeOfBusiness();
            account.printAccountInfo(); // shows balance details after closing
            }
            break;
        }

        menuChoice = getMenuOption();
    }
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT && choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}