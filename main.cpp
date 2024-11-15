/**************************************************************************************
Program:     Math Tutor
Section:     4 - 1:00pm
Programmers: Lindsay Itzep, Conner Diers
Date:        10.30.2024
Version:     4
GitHub URL:  https://github.com/Linz215/Math_Tutor_V5.git
Description: This program is an easy Math Tutor. It is a program that is intended to
             help small children do simple math problems. This program will ask the
             user to enter their name, and then ask them a math question until they
             don't want more. The math program is able to tell if the input is a
             number or not. It does all 4 math operations to help kids in all math
             aspects. This program also levels up every three correct answers and
             levels down every three wrong answers. After every question, the program
             will ask the user if they want to continue. The program will only end when
             the user says that they want to stop.
**************************************************************************************/
#include <iostream> //This allows the programmer the use of cin's and couts as well as
#include <string>   //Needed for the user's name
#include <ctime>    //Needed for the rand() commands to work
#include <cstdlib>  //Used for the random number generator
#include <limits>   //
#include <vector>   //Sets up table for vectors
#include <iomanip>  //Displays table

using namespace std;

int main()
{
/*
    //Constant variables
    const int MAX_ATTEMPTS = 3; // # of attempts that the user has on a question
    const int LEVEL_RANGE_CHANGE = 10; // The range in which the range of numbers change when leveling up/down

    //Used to change the font color
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string DEFAULT = "\033[0m";

    //used to determine what symbol of math is used.
    enum MathType  {MT_ADD, MT_SUB, MT_MUL, MT_DIV};
    MathType questionType;

    //range of possible numbers for question.
    int currentRange = 10;

    //variable that holds the symbol for the math problem
    char mathSymbol = '?';
    int mathLevel = 1;

    //These are the variables needed for the program to work
    string userName = "unknown";
    int userAns = 0;
    string userInput = "";
    int leftNum = 0;
    int rightNum = 0;

    //Makes sure that the leftNum will always be bigger than the rightNum so that it doesn't produce negative numbers
    int tempNum = 0;

    //Used to determine if user got the question correct
    int correctAns = 0;
    //Used to keep track of total correct and wrong answers the user has gotten
    int correctNum = 0;
    int incorrectNum = 0;
    int attempts;

    int totalCorrect;
    int totalIncorrect;
    int average;

    //makes a 2D vector
    vector<vector<int>> question;

    //The srand() and time restart the rand() so the numbers and equation sign are different everytime
    srand(time(NULL));

*/




      // display program intro
    cout << "************************************************************************************************************************" << endl;
    cout << "                                   __        _____  _   _ ____  _____ ____    _                                         " << endl;
    cout << "                                   \\ \\      / / _ \\| \\ | |  _ \\| ____|  _ \\  | |                                  " << endl;
    cout << "                                    \\ \\ /\\ / / | | |  \\| | | | |  _| | |_) | | |                                    " << endl;
    cout << "                                     \\ V  V /| |_| | |\\  | |_| | |___|  _ <  |_|                                      " << endl;
    cout << "                                      \\_/\\_/  \\___/|_| \\_|____/|_____|_| \\_\\ (_)                                  " << endl;
    cout << endl;
    cout << "************************************************************************************************************************" << endl;
    cout << "*                                              Winter Wonderland Math Tutor                                            *" << endl;
    cout << "************************************************************************************************************************" << endl;
    cout << endl;
    // Used Jazmin's and Linz's jokes from their program
    cout << "Fun Math Facts:" << endl;
    cout << " * There is no roman numeral for zero.                                                                                  " << endl;
    cout << " * There is an infinite amount of numbers between every number we normally use.                                         " << endl;
    cout << " * The symbol for division is also known as Obelus.                                                                     " << endl;
    cout << " * 42 is the answer to life, the universe and everything according to Douglas Adam's Hitchhiker's Guide to the Galaxy.  " << endl;
    cout << " * Math was invented by John Math in the year 1 when he decided to figure out what came after one.                      " << endl;
    cout << " * If you put the numbers 8 and 7 next to each other and turn your head to the left it will make a plague doctor mask.  " << endl;
    cout << " * The word 'one' is the only number that is spelled in descending order.                                               " << endl;
    cout << " * There are at least two people in the world who knows what 6 + 9 + 6 * 9 equals.                                      " << endl;
    cout << endl;
    cout << "************************************************************************************************************************" << endl;
    cout << endl;

    //Prompt the user for their name
    cout << "Please enter your name: ";
    getline(cin, userName); // able to use the name entered, even if it has spaces in it
    cout << endl;

    // Welcome the user to the game
    cout << "Welcome " << userName << " to the Winter Wonderland Math Tutor! " << endl;
    cout << endl;


string RandomJokeSets() {
        int jokeType = (rand() % 4) + 1;
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
     return 0;
}