#include <iostream>
#include <string>

using namespace std;

float findArea(float width, float length);

int main()
{
    float width = 0, length = 0;

    cout << "Please enter a width: ";
    cin >> width;

    cout << "Please enter a length: ";
    cin >> length;

    cout << "The area = " << findArea(width, length) << endl;
    
    return 0;
}

float findArea(float width, float length)
{
    return width * length;
}