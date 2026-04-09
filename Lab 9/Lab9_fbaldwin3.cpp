#include<iostream>
#include "Account.h"
#include <numeric>
using namespace std;

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

// SavingsAccount inheriting from Account
class SavingsAccount : public Account
{
private:
    double dailyInterestRate;

public:
    /**
    * @brief SavingsAccount object.
    * @param accNum The account number.
    * @param initBal The initial balance.
    * @param cust The customer associated with the account.
    * @param rate The daily interest rate.
    */
    SavingsAccount(const string& accNum, double initBal, const Customer& cust, double rate) 
        : Account(accNum, initBal, cust), dailyInterestRate(rate)
    {
    }

    /**
    * @brief Processes transactions and applies interest if applicable.
    */
    void closeOfBusiness() override
    {
        double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
        double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

        double previousBalance = balance;

        balance = previousBalance + totalDeposits - totalWithdrawals;

        // Apply interest only if balance is positive
        if (balance > 0)
        {
            balance = balance + (balance * dailyInterestRate);
        }

        printSummary(previousBalance, totalDeposits, totalWithdrawals, balance);

        deposits.clear();
        withdrawals.clear();
    }

    /**
    * @brief Prints account information with the new interest rate.
    */
    void printAccountInfo() const override
    {
        Account::printAccountInfo();
        cout << "Daily Interest Rate: " << dailyInterestRate * 100 << "%" << endl;
    }
};

int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account* account = new SavingsAccount("5423678409", 100.00, customer, 0.005);
    account->printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        double deposit = 0, withdrawal = 0;

        switch (menuChoice)
        {
        case DEPOSIT:
            deposit = getDepositAmount();
            account->deposit(deposit);
            break;
        case WITHDRAWAL:
            withdrawal = getWithdrawalAmount();
            account->withdraw(withdrawal);
            break;
        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();
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

double getDepositAmount()
{
    double deposit = 0;
    do
    {
        cout << "Please enter the deposit amount: $";
        cin >> deposit;

        if (!isAmountValid(deposit))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(deposit));

    return deposit;
}

double getWithdrawalAmount()
{
    double withdrawal = 0;
    do
    {
        cout << "Please enter the withdrawal amount: $";
        cin >> withdrawal;

        if (!isAmountValid(withdrawal))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(withdrawal));

    return withdrawal;
}

void printInvalidAmountMessage()
{
    cout << "The dollar amount must be greater than $0.00. Please try again." << endl;
}