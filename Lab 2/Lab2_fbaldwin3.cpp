/**
 * @file Lab2_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 1/29/26
 * @brief A program calculate the area of a rectangle
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    int length; // make sure the variables are integers
    int width;
    
    cout << "Enter the length of the recangle: " << endl;
    cin >> length;

    cout << "Enter the width of the recangle: " << endl;
    cin >> width;

    int perimiter = 2 * (length + width); // calculate perimiter

    cout << "The perimiter of the recangle is: " << perimiter << endl;

    return 0;
}