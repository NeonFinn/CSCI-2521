/**
 * @file Exercise1_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 03/04/26
 * @brief This program validates UPC-A barcodes performing the UPC-A check digit algorithm.
 */

#include <iostream>
#include <string>

using namespace std;

// function prototypes
bool DoesUserHaveNumber();
int GetFirstNumber();
int GetLastNumber();
int GetManufacturerNumber();
int GetProductNumber();

bool TestValidity(int first, int manufacturer, int product, int last);
void OutputValidity(int first, int manufacturer, int product, int last, bool isValid);

/**
 * @brief: Entry point of program
 * @param: None
 * @return: 0 (upon completion)
 */
int main()
{
    while (DoesUserHaveNumber())
    {
        int firstNumber = GetFirstNumber();
        int lastNumber = GetLastNumber();
        int manufacturerNumber = GetManufacturerNumber();
        int productNumber = GetProductNumber();

        bool isValid = TestValidity(firstNumber, manufacturerNumber, productNumber, lastNumber);

        OutputValidity(firstNumber, manufacturerNumber, productNumber, lastNumber, isValid);

        cout << endl;
    }

    return 0;
}

/**
 * @brief: Sees if the user has another UPC to check
 * @param: None
 * @return: true if the user wants to check a UPC, false otherwise
 */
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

/**
 * @brief: Gets first number from user
 * @param: None
 * @return: first digit in UPC
 */
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

/**
 * @brief: Gets the check digit from user
 * @param: None
 * @return: last digit in UPC
 */
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

/**
 * @brief: Gets 5 digit manufacturer number from user
 * @param: None
 * @return: manufacturer number
 */
int GetManufacturerNumber()
{
    int number;
    cout << "Enter the 5-digit manufacturer number: ";
    cin >> number;

    while (number < 10000 || number > 99999) // makes sure it is 5 digits long
    {
        cout << "Invalid input. Enter a 5-digit number: ";
        cin >> number;
    }

    return number;
}

/**
 * @brief: Get 5 digit product number from user
 * @param: None
 * @return: product number
 */
int GetProductNumber()
{
    int number;
    cout << "Enter the 5-digit product number: ";
    cin >> number;

    while (number < 10000 || number > 99999) // makes sure it is 5 digits long
    {
        cout << "Invalid input. Enter a 5-digit number: ";
        cin >> number;
    }

    return number;
}

/**
 * @brief: Tests if the numbers the user entered form a valid UPC code using the formula
 * @param: first first UPC digit
 * @param: manufacturer 5 digit manufacturer number
 * @param: product 5 digit product number
 * @param: last UPC check digit
 * @return: true if the UPC is valid, false otherwise
 */
bool TestValidity(int first, int manufacturer, int product, int last)
{
    int digits[12];

    digits[0] = first;

    // break manufacturer number into individual digits
    digits[1] = manufacturer / 10000;
    digits[2] = (manufacturer / 1000) % 10;
    digits[3] = (manufacturer / 100) % 10;
    digits[4] = (manufacturer / 10) % 10;
    digits[5] = manufacturer % 10;

    // break product number into individual digits
    digits[6] = product / 10000;
    digits[7] = (product / 1000) % 10;
    digits[8] = (product / 100) % 10;
    digits[9] = (product / 10) % 10;
    digits[10] = product % 10;

    digits[11] = last;

    int oddSum = 0;
    int evenSum = 0;

    // for first 11 digits
    for (int i = 0; i < 11; i++)
    {
        if (i % 2 == 0)
            oddSum += digits[i]; // add odd sum diguts
        else
            evenSum += digits[i]; // add even sum digits
    }

    int total = (oddSum * 3) + evenSum; // multiply odd sum by 3 and add even sum
    int mod = total % 10; // modulo 10

    int calculatedCheckDigit;

    if (mod != 0)
        calculatedCheckDigit = 10 - mod; // subtract modded number from 10
    else
        calculatedCheckDigit = 0;

    return calculatedCheckDigit == digits[11];
}

/**
 * @brief: Outputs if the UPC entered was valid or not
 * @param: first first UPC digit
 * @param: manufacturer 5 digit manufacturer number
 * @param: product 5 digit product number
 * @param: last UPC check digit
 * @param: isValid bool returned from TestValidity to determine the output
 * @return: None (void)
 */
void OutputValidity(int first, int manufacturer, int product, int last, bool isValid)
{
    if (isValid)
        cout << "UPC code " << first << manufacturer << product << last << " is valid" << endl;
    else
        cout << "Invalid UPC code" << endl;
}