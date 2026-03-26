/**
* @file Lab8_fbaldwin3.cpp
* @author Finn Baldwin
* @date 3/26/26
* @brief Demonstrates stack vs heap memory and the use of pointers and references.
*/

#include<iostream>
using namespace std;

/**
 * @brief Entry point for the memory demonstration.
 * @return 0 to indicate success.
 */
int main()
{
    // stack allocation, holds integer value 50
    int stackInt = 50;

    // heap allocation, pointer that holds address of integer 100
    int* heapInt = new int(100);

    // pointer to stack variable, holds address of stackInt
    int* ptrToStack = &stackInt;

    // reference to stack variable
    int& refToStack = stackInt;

    cout << "\n";

    // output stack variable
    cout << "Stack Variable (stackInt):\n";
    cout << "Value: " << stackInt << "\n";
    cout << "Address: " << &stackInt << "\n\n";

    // output heap variable
    cout << "Heap Variable (heapInt):\n";
    cout << "Value: " << *heapInt << "\n";
    cout << "Address: " << heapInt << "\n\n";

    // output pointer to stack
    cout << "Pointer to Stack (ptrToStack):\n";
    cout << "Value Pointed To: " << *ptrToStack << "\n";
    cout << "Address Stored: " << ptrToStack << "\n\n";

    // output reference to stack
    cout << "Reference to Stack (refToStack):\n";
    cout << "Value Referred To: " << refToStack << "\n";
    cout << "Address: " << &refToStack << "\n\n";

    // cleanup
    delete heapInt;

    return 0;
}