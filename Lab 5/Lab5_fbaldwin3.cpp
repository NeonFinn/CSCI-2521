/**
 * @file Lab5_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 2/17/26
 * @brief Print a multiplication table for numbers 5-9 based on user input, now put into functions
 */

#include <iostream>
#include <string>
using namespace std;

// function prototypes
int getMaxDigitInput();
int stringToInt(string input, bool &isNumber);
void printMultiplicationTable(int maxDigit);
void printInputValidationError();
bool isMaxDigitInputValid(int input);

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate success.
 */
int main()
{
    int maxDigit = getMaxDigitInput();
    printMultiplicationTable(maxDigit);
    return 0;
}

/**
 * @brief Outputs an error message for invalid input.
 * @param None.
 * @return None (void).
 */
void printInputValidationError()
{
    cout << "Invalid input. The digit must be greater than 4 and less than 10." << endl;
}

/**
 * @brief Validates the user's input against the acceptable range.
 * @param input - The user-provided integer to validate.
 * @return true if the input is greater than 4 and less than 10; false otherwise.
 */
bool isMaxDigitInputValid(int input)
{
    return (input > 4 && input < 10);
}

/**
 * @brief Checks if the input is within the valid range.
 * @param None.
 * @return True if the input is valid (4 < input < 10), false otherwise.
 */
int getMaxDigitInput()
{
    // declare variables before use
    string input;
    int maxDigit = 0; 
    bool isNumber;

    cout << "Please enter the maximum digit for the multiplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10" << endl;

    // loop until valid number is entered
    while (true) 
    {
        cin >> input; // read as string

        maxDigit = stringToInt(input, isNumber);

        if (isNumber && isMaxDigitInputValid(maxDigit)) // if is number and in range
        {
            break;
        }

        printInputValidationError();
    }

    return maxDigit;
}

/**
 * @brief Converts user input from a string to a integer if valid.
 * @param input The string entered by the user
 * @param isNumber A boolean that is set to true if its a valid number
 * @return The users integer input value
 */
int stringToInt(string input, bool &isNumber)
{
    int number = 0;
    isNumber = true; 
    
        // for every character in input
        for (char c : input) 
        {
            if (c < '0' || c > '9') // if character is not a digit
            { 
                isNumber = false;
                break; // exit loop without convering to int
            }

            // convert current digit to an integer manually (had to research how to do this without using methods we haven't learned)
            number = number * 10 + (c - '0');
        }

        return number;
}

/**
 * @brief Prints the formatted multiplication table.
 * @param maxDigit - The highest digit to include in the table.
 * @return None (void).
 */
void printMultiplicationTable(int maxDigit)
{
   // multiplication table printing
    for (int row = 1; row <= maxDigit; row++) // loop each row starting at 1, check if less than or equal to maxDigit, increment count
    {
        for (int col = 1; col <= maxDigit; col++) // loop each column in the row starting at 1, check if less than or equal to maxDigit, increment count
        {
            cout << row * col << "\t"; // print product of row and column spaced with tabs
        }
        cout << endl; // new line after every row is complete
    } 
}