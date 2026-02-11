/**
 * @file Lab4_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 2/10/26
 * @brief Print a multiplication table for numbers 5-9 based on user input
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // declare variables before use
    int maxDigit = 0; 
    int row = 0;
    int column = 0;
    string input;

    cout << "Please enter the maximum digit for the multiplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10" << endl;

    // loop until valid number is entered
    while (maxDigit <= 4 || maxDigit >= 10) {
        cin >> input; // read as string

        bool isNumber = true; 
        maxDigit = 0;
        // for every character in input
        for (char c : input) {
            if (c < '0' || c > '9') { // if character is not a digit
                isNumber = false;
                break; // exit loop without convering to int
            }
            // convert current digit to an integer manually (had to research how to do this without using methods we haven't learned)
            maxDigit = maxDigit * 10 + (c - '0');
        }

        if (!isNumber || maxDigit <= 4 || maxDigit >= 10) { // if its not a number or in the correct range re prompt the user
            cout << "Try again. The digit must be greater than 4 and less than 10" << endl;
            maxDigit = 0;
            continue;
        }
    }

    // multiplication table printing
    for (int row = 1; row <= maxDigit; row++) // loop each row starting at 1, check if less than or equal to maxDigit, increment count
    {
        for (int col = 1; col <= maxDigit; col++) // loop each column in the row starting at 1, check if less than or equal to maxDigit, increment count
        {
            cout << row * col << "\t"; // print product of row and column spaced with tabs
        }
        cout << endl; // new line after every row is complete
    }

    return 0;
}