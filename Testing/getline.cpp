#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstName, lastName;

    cout <<"Please enter your first name: ";
    getline(cin, firstName);

    cout <<"Please enter your last name: ";
    getline(cin, lastName);

    cout << "Your name is: " << firstName << " " << lastName << endl;
}