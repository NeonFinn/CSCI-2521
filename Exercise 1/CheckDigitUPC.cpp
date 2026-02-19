#include <iostream>
#include <string>

using namespace std;

// function prototypes
bool DoesUserHaveNumber();
int GetFirstNumber();
int GetLastNumber();
int GetManufacturerNumber();
int GetProductNumber();
void ParseInput(int number);
bool TestValidity();
void OutputValidity(bool isValid);

int main()
{
    if (!DoesUserHaveNumber()) // if user does not have a number to check exit program, otherwise keep going
    {
        return 0; // exit program
    }
    GetFirstNumber(); // prompt user for first number of the UPC
    GetLastNumber(); // prompt user for last number of the UPC

    //int manufacturerNumber = GetManufacturerNumber(); // prompt user for manufacturer number
   // ParseInput(manufacturerNumber); // parse the digits so they can be checked

    //int productNumber = GetProductNumber(); // prompt the user for the product number
   // ParseInput(productNumber); // parse the digits so they can be checked

   // bool isValid = TestValidity(); // use the parsed digits to see if the UPC is valid
   // OutputValidity(isValid); // tell player if the UPC is valid or not

    return 0;
}

bool DoesUserHaveNumber()
{
    string answer;

    while (true)
    {
        cout << "Do you have a UPC code to check? (y/n): ";
        cin >> answer;

        if (answer == "y" || answer == "Y")
        {
            return true; // user has a UPC code to check
        }
        else if (answer == "n" || answer == "N")
        {
            cout << "No UPC to check. Exiting program." << endl;
            return false; // user does not have a UPC code to check
        }
        else
        {
            cout << "Invalid input" << endl;
        }
    }
}

int GetFirstNumber()
{
    int firstNumber;

    cout << "Enter the very first number of the UPC: ";
    cin >> firstNumber;
    
    while (firstNumber < 0 || firstNumber > 9)
    {
        cout << "Invalid input. Please enter a number from 0 to 9: ";
        cin >> firstNumber;
    }

    return firstNumber;
}

int GetLastNumber()
{
    int lastNumber;

    cout << "Enter the very last number of the UPC: ";
    cin >> lastNumber;
    
    while (lastNumber < 0 || lastNumber > 9)
    {
        cout << "Invalid input. Please enter a number from 0 to 9: ";
        cin >> lastNumber;
    }

    return lastNumber;
}

/*
void ParseInput(int manufacturerNumber)
{
    int temp = manufacturerNumber;

    int firstDigit = manufacturerNumber / 10000;
    manufacturerNumber = manufacturerNumber % 10000;

    int secondDigit = manufacturerNumber / 1000;
    manufacturerNumber = manufacturerNumber % 1000;

    int thirdDigit = manufacturerNumber / 100;
    manufacturerNumber = manufacturerNumber % 100;

    int fourthDigit = manufacturerNumber / 10;
    manufacturerNumber = manufacturerNumber % 10;

    int fifthDigit = manufacturerNumber;

    cout << "The manufacturer number " << temp << " parsed is: " << endl;
    cout << firstDigit << "\t" << secondDigit << "\t" << thirdDigit << "\t" << fourthDigit << "\t" << fifthDigit << endl;
}
*/
