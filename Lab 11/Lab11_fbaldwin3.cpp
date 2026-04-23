/**
 * @file Lab11_FinnBaldwin.cpp
 * @author Finn Baldwin
 * @date 04/23/26
 * @brief Demonstrates exception handling using vectors and try/catch.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

/**
 * @brief Entry point of the program.
 * @return 0 if program runs successfully.
 */
int main()
{
    // vector of strings for city names
    vector<string> cities = {"Columbus", "Cleveland", "Cincinnati","Toledo", "Akron", "Dayton", "Youngstown"};

    int index;

    cout << "Enter an index number to find a city: ";
    cin >> index;

    // try to retrieve the city corresponding to the index number
    try
    {
        string city = cities.at(index);
        cout << "City at index " << index << " is: " << city << endl;
    }
    // if its out of range
    catch (out_of_range)
    {
        // too low: print first city
        if (index < 0)
        {
            cout << "Invalid index. Here's the first city instead: " << cities.front() << endl;
        }
        // too high: print last city
        else if (index >= cities.size())
        {
            cout << "Invalid index. Here's the last city instead: " << cities.back() << endl;
        }
    }

    return 0;
}