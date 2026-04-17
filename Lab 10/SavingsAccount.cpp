#include "SavingsAccount.h"
#include <fstream>
#include <iomanip>

SavingsAccount::SavingsAccount() : interest(1)
{
}

SavingsAccount::SavingsAccount(const string& accNum, double initialBalance, float interest, const Customer& customer)
    : Account(accNum, initialBalance, customer)
{    
    this->interest = interest;
}

void SavingsAccount::closeOfBusiness()
{
    double totalDeposits = accumulate(deposits.begin(), deposits.end(), 0.0);
    double totalWithdrawals = accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;
    double interestToApply = previousBalance <= 0 ? 0 : interest;
    double newBalance = (previousBalance + totalDeposits - totalWithdrawals) * (1 + interestToApply);

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

void SavingsAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Interest Rate: " << interest * 100 << "%" << endl;
    owner.printCustomerInfo();
}

/**
* @brief Saves account information to a text file
*/
void SavingsAccount::Save() const
{
    // open file
    ofstream outFile("account_summary.txt");

    // write information to file
    outFile << "Account Number: " << accountNumber << endl;
    outFile << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    outFile << "Daily Interest Rate: " << interest << endl;

    // close the file
    outFile.close();
}