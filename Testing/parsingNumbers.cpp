#include <iostream>
#include <string>

using namespace std;

int main()
{
    int manufacturerNumber = 51500;
    int temp = manufacturerNumber;

    // use integer division to parse digit
    int firstDigit = manufacturerNumber / 10000;
    // strip digit using mod = 1500
    manufacturerNumber = manufacturerNumber % 10000;

    int secondDigit = manufacturerNumber / 1000;
    manufacturerNumber = manufacturerNumber % 1000; // 500

    int thirdDigit = manufacturerNumber / 100;
    manufacturerNumber = manufacturerNumber % 100; // 10

    int fourthDigit = manufacturerNumber / 10;
    manufacturerNumber = manufacturerNumber % 10; // 0

    int fifthDigit = manufacturerNumber;

    cout << "The manufacturer number : " << temp << " parsed is: " << endl;
    cout << firstDigit << "\t" << secondDigit << "\t" << thirdDigit << "\t" << fourthDigit << "\t" << fifthDigit << endl;

    return 0;
}
