/**
 * @file Lab3_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 2/3/26
 * @brief A menu-driven program to calculate areas of rectangles and circles.
 */

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string userInput;
    double rectangleLength;
    double rectangleWidth;
    double rectangleArea;
    double circleRadius;
    double circleArea;
    const double PI = 3.14159;
    
    // show the user the menu options
    cout << "Menu" << endl;
    cout << "1. Calculate the Area of a Rectangle" << endl;
    cout << "2. Calculate the Area of a Circle" << endl;
    cout << "3. Quit" << endl;
    cout << "Please make a menu selection: ";

    // get user input for menu selection
    cin >> userInput;

    // if the player selects 1, prompt for length and width of a rectangle and solve for area
    if (userInput == "1")
    {
        cout << "Please enter the length of the rectangle: ";
        cin >> rectangleLength;

        cout << "Please enter the width of the rectangle: ";
        cin >> rectangleWidth;

        rectangleArea = rectangleLength * rectangleWidth;

        cout << "The area of the rectangle is: " << rectangleArea << endl;

        return 0;
    }

    // if the player selects 2, prompt for radius of the circle and solve for area
    else if (userInput == "2")
    {
        cout << "Please enter the radius of the circle: ";
        cin >> circleRadius;

        circleArea = PI * (circleRadius * circleRadius);

        cout << "The area of the circle is: " << circleArea << endl;

        return 0;
    }

    // if the player selects 3, quit and tell them
    else if (userInput == "3")
    {
        cout << "You sucessfully quit the program.";

        return 0;
    }

    // if the player makes an invalid choice, quit automatically
    else
    {
        cout << "You did not choose a valid menu option. Quitting the Program.";

        return 0;
    }
}