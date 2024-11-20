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


// Main Function
int main() {
    srand(time(0));
    DisplayGameIntro();
    string userName = GetUserName();

    int mathLevel = 1, currentRange = LEVEL_RANGE_CHANGE;
    vector<vector<int>> questions;
    int totalCorrect = 0, totalIncorrect = 0;

    do {
        int leftNum, rightNum;
        char mathSymbol;
        int correctAnswer = GenerateRandomQuestion(mathLevel, currentRange, leftNum, rightNum, mathSymbol);

        bool correct = GiveThreeAttempts(leftNum, rightNum, mathSymbol, correctAnswer);
        vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAnswer, correct ? 1 : 0};
        questions.push_back(row);

        if (correct) totalCorrect++;
        else totalIncorrect++;

        CheckForLevelChange(mathLevel, currentRange, totalCorrect, totalIncorrect);
    } while (AskToPlayAgain());

    DisplaySummaryReport(questions);
    cout << "Thank you for playing! Goodbye.\n";
    return 0;
}
