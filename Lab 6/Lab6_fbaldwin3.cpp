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
    int sum = 0;
    int highest = 0;
    int lowest = 0;

    // title
    cout << "\n";
    cout << "Array Solution\n";
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
        sum += score;

        // set highest and lowest score
        if (i == 0)
        {
            highest = score;
            lowest = score;
        }
        else
        {
            if (score > highest)
                highest = score;

            if (score < lowest)
                lowest = score;
        }
    }
        
    double average = sum / 10.0;

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
    int sum = 0;
    int highest = 0;
    int lowest = 0;

    // title
    cout << "\n";
    cout << "Vector Solution\n";
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

    // check if empty
    if (scores.size() == 0)
    {
        cout << "No scores entered.\n";
        return;
    }

    // initialize highest and lowest
    highest = scores[0];
    lowest = scores[0];

    // calculate sum, highest, lowest
    for (int i = 0; i < scores.size(); i++)
    {
        sum += scores[i];

        if (scores[i] > highest)
            highest = scores[i];

        if (scores[i] < lowest)
            lowest = scores[i];
    }

    double average = (double)sum / scores.size();

    // display stats
    cout << "\nVector Results:\n";
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;

    // sort scores
    sort(scores.begin(), scores.end());

    // display sorted scores
    cout << "Sorted scores: ";

    for (int i = 0; i < scores.size(); i++)
    {
        cout << scores[i] << " ";
    }

    cout << endl;
}