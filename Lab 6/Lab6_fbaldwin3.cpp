/**
 * @file Lab6_fbaldwin3.cpp
 * @author Finn Baldwin
 * @date 2/25/26
 * @brief Compare static arrays and vectors for processing student scores.
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// function prototypes
void arraySolution();
void vectorSolution();

// array helper function prototypes
float calculateAverage(const int arr[], int size);
int findMax(const int arr[], int size);
int findMin(const int arr[], int size);

// vector helper function prototypes
float calculateAverage(const vector<int>& vec);
int findMax(const vector<int>& vec);
int findMin(const vector<int>& vec);

/**
 * @brief: Entry point of program
 * @param: None
 * @return: 0 for sucess
 */
int main()
{
    arraySolution();
    vectorSolution();

    return 0;
}

/**
 * @brief: calculates statistics using a fixed-size static array
 * @param: None
 * @return: None (Void)
 */
void arraySolution()
{
    int scores[10]; // static array
    int score = 0;

    // title
    cout << "\nArray Solution\n";
    cout << "----------------------------------\n";

    // loop to get 10 valid scores
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter test score #" << (i + 1) << " (0 - 100): ";
        cin >> score;

        // validate input
        while (score < 0 || score > 100)
        {
            cout << "Invalid score. Enter a score between 0 and 100: ";
            cin >> score; 
        }

        // once valid
        scores[i] = score;
    }

    // Use helper functions
    float average = calculateAverage(scores, 10);
    int highest = findMax(scores, 10);
    int lowest = findMin(scores, 10);

    cout << "\nArray Results:\n";
    cout << "Average: " << average << endl;
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
}

/**
 * @brief: calculates statistics using a dynamic vector
 * @param: None
 * @return: None (Void)
 */
void vectorSolution()
{
    vector<int> scores; // empty vector
    int score = 0;

    // title
    cout << "\nVector Solution\n";
    cout << "----------------------------------\n";

    // input loop
    while (true)
    {
        cout << "Enter test score (-1 to stop): ";
        cin >> score;

        // break value
        if (score == -1)
            break;

        // validate input if not -1
        if (score < 0 || score > 100)
        {
            cout << "Invalid score. Enter a value from 0-100. ";
            continue;
        }

        scores.push_back(score);
    }

    if (scores.size() == 0)
    {
        cout << "No scores entered.\n";
        return;
    }

    // Use helper functions
    float average = calculateAverage(scores);
    int highest = findMax(scores);
    int lowest = findMin(scores);

    cout << "\nVector Results:\n";
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;

    sort(scores.begin(), scores.end());

    cout << "Sorted scores: ";
    for (int x : scores)
        cout << x << " ";
    cout << endl;
    cout << endl;
}

// Array helper functions

/**
 * @brief Calculates the average of integers in the an array
 * @param arr The array of integers
 * @param size Number of elements in the array
 * @return The average as a float
 */
float calculateAverage(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return sum / (float)size;
}

/**
 * @brief Finds the maximum value in an array
 * @param arr The array of integers
 * @param size Number of elements in the array
 * @return The maximum value
 */
int findMax(const int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

/**
 * @brief Finds the minimum value in an array
 * @param arr The array of integers
 * @param size Number of elements in the array
 * @return The minimum value
 */
int findMin(const int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

// Vector helper function definitions

/**
 * @brief Calculates the average of the integers in the vector
 * @param vec The vector of integers
 * @return The average as a float
 */
float calculateAverage(const vector<int>& vec)
{
    int sum = 0;
    for (int x : vec) 
        sum += x;
    return sum / (float)vec.size();
}

/**
 * @brief Finds the maximum value in a vector
 * @param vec The vector of integers
 * @return The maximum value
 */
int findMax(const vector<int>& vec)
{
    int max = vec[0];
    for (int val : vec)
        if (val > max)
            max = val;
    return max;
}

/**
 * @brief Finds the minimum value in a vector
 * @param vec The vector of integers
 * @return The minimum value
 */
int findMin(const vector<int>& vec)
{
    int min = vec[0];
    for (int val : vec)
        if (val < min)
            min = val;
    return min;
}