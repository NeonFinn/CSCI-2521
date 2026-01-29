/**
 * @file Lab2_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 1/29/26
 * @brief A program calculate the area of a rectangle
 */

#include<iostream>
using namespace std;

int main()
{
    float length; // make sure the variables are floats
    float width;
    
    cout << "Enter the length of the rectangle: " << endl;
    cin >> length;

    cout << "Enter the width of the rectangle: " << endl;
    cin >> width;

    float perimeter = 2 * (length + width); // calculate perimeter

    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    return 0;
}