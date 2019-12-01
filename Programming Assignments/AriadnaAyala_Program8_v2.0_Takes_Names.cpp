//*************************************************************************
//  Test Scores V2.0 (Accepts students' names)
//  Programmer: Ariadna Ayala
//  Completed: 11/29/2019
//  Status: Completed

//  This program collects user input for an amount of students taken the test and uses this data as an
//  array size; then, it collects user input for students' names and  test scores, distributes this
// informtion into an array. The program outputs all grades individually and students' average grade.
//*************************************************************************




#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//****************************
struct studentTests
{
    string name;
    int score;
};
//*****************************


void userInput (studentTests [], int, int);
void ascendingSort(studentTests [], int, int);
double averageGrade (double, int);
void outputGrades(studentTests *, int, int);

int main()
{
    // PART 1: Variable declaration.
    studentTests *tests;                // Used to allocate the array;
    double totalScores = 0.0;           // Total tests scores accumulator;
    int testsTaken,                     // Amount of tests taken;
        i;                              // Variable used as a counter for amount of tests.
    
    
    // PART 2:  Array allocation and call functions.
    cout << "Number of students: ";
    cin >> testsTaken;
    
    tests = new studentTests [testsTaken];
    
    userInput(tests, testsTaken, i);
    
    ascendingSort(tests, testsTaken, i);
    
    
    
    
    // PART 3: Calculate grand total of all scores and display the final results.
    //         Includes dynamically allocated memory.
    for (i = 0; i < testsTaken; i = i + 1)
    {
        totalScores += tests[i].score;
    }
    
    cout << fixed << showpoint << setprecision (2);
    cout << left << setw(17) << "Name" << right << setw(10) << "Score" << endl;
    cout << "-------------------------------" << endl;
    outputGrades(tests, testsTaken, i);
    cout << "-------------------------------" << endl;
    cout << "Average score: " << right << averageGrade (totalScores, testsTaken) << endl;
    
    return 0;
}

// Function collects user input for test information.
void userInput (studentTests tests[], int testsTaken, int i)
{
     
    cout << "\nEnter test information." << endl;
    for (i = 0; i < testsTaken; i = i + 1)
    {
        cin.ignore();
        cout << "Name: ";
        getline(cin, tests[i].name);
        cout << "Score: ";
        cin >> tests[i].score;
        while (tests[i].score < 0 || tests[i].score > 105)
        {
            cout << "ERROR! Invalid score. Enter value between 0 and 105." << endl;
            cout << "Try again: ";
            cin >> tests[i].score;
        }
        
    }
 }
 
// Function performs ascending array sorting.
void ascendingSort(studentTests array[], int num, int i)
{
    studentTests temp;
    bool sorted;
    sorted = false;
    while (!sorted)
    {
        sorted = true;
        for (i  = 0; i < (num - 1); i = i + 1)
        {
            if (array[i].score > array[i + 1].score)
            {
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = false;
            }
        }
    }
}

// Function calculates the average.
double averageGrade (double totalScores, int testsTaken)
{
    double average;
    average = totalScores / testsTaken;
    return average;
    
}

// Function outputs student's gardes.
void outputGrades(studentTests *array, int num, int i)
{
    for (i = 0; i < num; i = i + 1)
    {
        cout << left << setw(17) << array -> name << " " << right << setw(10) << array -> score << endl;
        array = array + 1;
    }
}
