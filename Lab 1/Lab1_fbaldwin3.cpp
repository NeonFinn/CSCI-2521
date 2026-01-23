/**
 * @file Lab1_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 1/23/26
 * @brief A program to welcome the user based on the name they input
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string firstName;
    string lastName;
    
    cout << "Enter your first name: ";
    cin >> firstName;

    cout << "Enter your last name: ";
    cin >> lastName;

    cout << "Welcome to C++ Programming, " << firstName << " " << lastName << "!" << endl;

    return 0;
}