#include <iostream> 
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std;

int main() {
    srand(time(nullptr)); // set the seed using time

    int randomNum = rand() % 10 + 1; // find number between 1 and 10
    cout << "Random number (1-10): " << randomNum << endl;

    return 0;
}