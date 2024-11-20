//
// Created by conne on 11/19/2024.
//

#ifndef MATH_TUTOR_H
#define MATH_TUTOR_H
#include <string>
#include <vector>
using namespace std;

int GenerateRandomQuestion(int mathLevel, int currentRange, int& leftNum, int& rightNum, char& mathSymbol);
bool GiveThreeAttempts(int leftNum, int rightNum, char mathSymbol, int correctAnswer);
void DisplayGameIntro();
string GetUserName();
void DisplayRandomJoke();
int GenerateRandomNumber(int range);
char GenerateMathSymbol(int mathType);
int SolveMathProblem(int mathType, int leftNum, int rightNum);
bool CheckAnswer(int correctAnswer, int userAnswer, int attempt, int &totalCorrect, int &totalIncorrect);
void DisplaySummaryReport(const vector<vector<int>> &questions);
bool AskToPlayAgain();
void CheckForLevelChange(int &totalCorrect, int &totalIncorrect, int &mathLevel, int &currentRange);


#endif //MATH_TUTOR_H
