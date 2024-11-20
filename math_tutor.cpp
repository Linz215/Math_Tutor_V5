//
// Created by conne on 11/19/2024.
//

// Function to display the introduction

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <iomanip>

using namespace std;

// Global Constants
const int MAX_ATTEMPTS = 3;
const int LEVEL_RANGE_CHANGE = 10;

void DisplayGameIntro() {
    int jokeType = (rand() % 4);
    cout <<
            "************************************************************************************************************************\n"
            "                                   __        _____  _   _ ____  _____ ____    _\n"
            "                                   \\ \\      / / _ \\| \\ | |  _ \\| ____|  _ \\  | |\n"
            "                                    \\ \\ /\\ / / | | |  \\| | | | |  _| | |_) | | |\n"
            "                                     \\ V  V /| |_| | |\\  | |_| | |___|  _ <  |_|\n"
            "                                      \\_/\\_/  \\___/|_| \\_|____/|_____|_| \\_\\ (_)\n\n"
            "************************************************************************************************************************\n"
            "*                                              Winter Wonderland Math Tutor                                            *\n"
            "************************************************************************************************************************\n";
    //Random Joke sets
    switch (jokeType) {

        //Switch that adds extra fancy amounts of UI, makes it semi random with each login
        case 1: //adds a switch that adds a random set of jokes to make the UI feel fresher
            cout <<
                    "****************************************************************************************************"
                    << endl;
        cout << "Have you ever noticed what's odd? Every other number!!" << endl;
        cout << "What do mathematicians do after it snows? They make snow angles!!" << endl;
        cout << "Which tool is best for math? Multi-pliers!!" << endl;
        cout << "Swimmers love one kind of math more than others, what is it? Dive-ision!!" << endl;
        cout <<
                "****************************************************************************************************"
                << endl;
        break;
        case 2:
            cout <<
                    "****************************************************************************************************"
                    << endl;
        cout << "Once there was a hen who counted her own eggs. She was a mathemachicken!!" << endl;
        cout << "Why was six afraid of seven? Because seven, eight, nine!!" << endl;
        cout << "Why can't two 4's go eat lunch? They already 8!!" << endl;
        cout << "What does the moon and a dollar have in common? They both have 4 quarters!!" << endl;
        cout <<
                "****************************************************************************************************"
                << endl;
        break;
        case 3:
            cout <<
                    "****************************************************************************************************"
                    << endl;
        cout << "Why's 69 afraid of 70? Because 71!!" << endl;
        cout << "Who's in charge in a pencil case? The ruler!!" << endl;
        cout << "Why can't your nose grow to be 12 inches long? Because then it would be a foot!!" << endl;
        cout << "Which numbers just won't sit still?? Roamin' numbers" << endl;
        cout <<
                "****************************************************************************************************"
                << endl;
        break;
        case 4:
            cout <<
                    "****************************************************************************************************"
                    << endl;
        cout << "What did 0 say to 8? Nice belt!!" << endl;
        cout << "How do you make time fly? Throw a clock out the window!!" << endl;
        cout << "If you're ever in a cold room, go to the corner. It's 90 degrees!!" << endl;
        cout << "Why did the girl always wear glasses when doing math? It improved her di-vision!!" << endl;
        cout <<
                "****************************************************************************************************"
                << endl;
        break;
        default:
            cout <<
                    "****************************************************************************************************"
                    << endl;
        cout << "What's the best way to get a math tutor? An add!!" << endl;
        cout << "Do you see that circle over there? He's really smart. He has 360 degrees!!" << endl;
        cout << "What is a math teacher's favorite tree? Geometry!!" << endl;
        cout << "Why are obtuse and acute angles always sad? They're never right!!" << endl;
        cout <<
                "****************************************************************************************************"
                << endl;
        break;
    }
}

// Function to get the username
string GetUserName() {
    string userName;
    cout << "Please enter your name: ";
    getline(cin, userName);
    cout << "Welcome " << userName << " to the Winter Wonderland Math Tutor!\n\n";
    return userName;
}

// Function to get a numeric value with validation
int GetNumericValue(const string& prompt) {
    int value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\tInvalid input! Please enter a number: ";
    }
    return value;
}

// Function to ask the user if they want to play again
bool AskToPlayAgain() {
    string userInput;
    while (true) {
        cout << "Do you want to continue (y = yes or n = no)? ";
        cin >> userInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        for (char& c : userInput) c = tolower(c);
        if (userInput == "y" || userInput == "yes") return true;
        if (userInput == "n" || userInput == "no") return false;
        cout << "Invalid input. Please enter 'y' or 'n'.\n";
    }
}

// Function to generate a random question and return the correct answer
int GenerateRandomQuestion(int mathLevel, int currentRange, int& leftNum, int& rightNum, char& mathSymbol) {
    enum mathType { MT_ADD, MT_SUB, MT_MUL, MT_DIV };
    int correctAnswer;
    leftNum = (rand() % currentRange) + 1;
    rightNum = (rand() % currentRange) + 1;
    mathType questionType = static_cast<mathType>(rand() % 4);

    switch (questionType) {
        case MT_ADD:
            mathSymbol = '+';
            correctAnswer = leftNum + rightNum;
            break;
        case MT_SUB:
            mathSymbol = '-';
            if (leftNum < rightNum) swap(leftNum, rightNum);
            correctAnswer = leftNum - rightNum;
            break;
        case MT_MUL:
            mathSymbol = '*';
            correctAnswer = leftNum * rightNum;
            break;
        case MT_DIV:
            mathSymbol = '/';
            correctAnswer = leftNum;
            leftNum *= rightNum;
            break;
        default:
            cout << "Error: Invalid question type.\n";
            exit(-1);
    }
    return correctAnswer;
}

// Function to give the user up to 3 attempts to answer a question
bool GiveThreeAttempts(int leftNum, int rightNum, char mathSymbol, int correctAnswer) {
    for (int i = 1; i <= MAX_ATTEMPTS; i++) {
        int userAnswer = GetNumericValue("[Attempt " + to_string(i) + "] What does " +
                                        to_string(leftNum) + " " + mathSymbol + " " +
                                        to_string(rightNum) + " = ");
        if (userAnswer == correctAnswer) {
            cout << "Correct!\n";
            return true;
        } else {
            cout << "Incorrect. " << (MAX_ATTEMPTS - i) << " attempts left.\n";
        }
    }
    cout << "The correct answer is: " << correctAnswer << ".\n";
    return false;
}

// Function to check and update the level based on user performance
void CheckForLevelChange(int& mathLevel, int& currentRange, int& totalCorrect, int& totalIncorrect) {
    if (totalCorrect == 3) {
        mathLevel++;
        currentRange += LEVEL_RANGE_CHANGE;
        cout << "Level up! You are now on level " << mathLevel << " with a range of 1 to " << currentRange << ".\n";
    } else if (totalIncorrect == 3 && mathLevel > 1) {
        mathLevel--;
        currentRange -= LEVEL_RANGE_CHANGE;
        cout << "Level down. You are now on level " << mathLevel << " with a range of 1 to " << currentRange << ".\n";
    }
}

// Function to display a summary report
void DisplaySummaryReport(const vector<vector<int>>& questions) {
    cout << "\n=================================\n";
    cout << "|         Summary Report        |\n";
    cout << "=================================\n";
    cout << "Level  Question        Attempts\n";
    cout << "-----  --------------- --------\n";
    int totalQuestions = 0, totalCorrect = 0, totalIncorrect = 0;

    for (const auto& row : questions) {
        int mathLevel = row[0];
        int leftNum = row[1];
        char mathSymbol = static_cast<char>(row[2]);
        int rightNum = row[3];
        int correctAnswer = row[4];
        int attempts = row[5];

        cout << setw(5) << mathLevel << "  " << leftNum << " " << mathSymbol << " " << rightNum << " = " << correctAnswer;
        if (attempts == 0) {
            cout << "    Incorrect\n";
            totalIncorrect++;
        } else {
            cout << "    " << attempts << "\n";
            totalCorrect++;
        }
        totalQuestions++;
    }
    cout << "\nTotal Questions: " << totalQuestions
         << "\nTotal Correct  : " << totalCorrect
         << "\nTotal Incorrect: " << totalIncorrect
         << "\nAccuracy       : " << (totalQuestions ? (totalCorrect * 100 / totalQuestions) : 0) << "%\n";
}
