#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <iomanip>
#include "math_tutor.h" //header file

using namespace std;

// Global Constants
const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE_CHANGE = 10;


int main() {
    srand(time(0));  // Seed the random number generator to ensure randomness for each game session

    DisplayGameIntro();  // Call the function to display the game's introductory message

    string userName = GetUserName();  // Get the user's name by calling the GetUserName function

    int mathLevel = 1, currentRange = LEVEL_RANGE_CHANGE;  // Initialize math level and current range
    vector<vector<int>> questions;  // Vector to store the questions and answers
    int totalCorrect = 0, totalIncorrect = 0;  // Initialize counters for correct and incorrect answers

    do {
        int leftNum, rightNum;  // Variables to store the numbers used in the math problem
        char mathSymbol;  // Variable to store the math operator (+, -, *, /)

        // Generate a random math question and retrieve the correct answer
        int correctAnswer = GenerateRandomQuestion(mathLevel, currentRange, leftNum, rightNum, mathSymbol);

        // Give the user three attempts to answer the question and determine if they were correct
        bool correct = GiveThreeAttempts(leftNum, rightNum, mathSymbol, correctAnswer);

        // Store the question data (math level, numbers, operator, correct answer, and result of the attempt)
        vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAnswer, correct ? 1 : 0};
        questions.push_back(row);  // Add the current question data to the questions vector

        // Update the total count of correct and incorrect answers based on the result
        if (correct) totalCorrect++;
        else totalIncorrect++;

        // Check if the user should level up or down based on their performance
        CheckForLevelChange(mathLevel, currentRange, totalCorrect, totalIncorrect);
    } while (AskToPlayAgain());  // Ask the user if they want to continue playing

    // After the game loop, display a summary report of the user's performance
    DisplaySummaryReport(questions);

    cout << "Thank you for playing! Goodbye.\n";  // Print a thank you message at the end of the game
    return 0;  // Return 0 to indicate successful completion of the program
}
