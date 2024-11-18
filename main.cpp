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

//
void DisplayGameIntro() {
    // display program intro
    cout <<
            "************************************************************************************************************************"
            << endl;
    cout << "                                   __        _____  _   _ ____  _____ ____    _" << endl;
    cout << "                                   \\ \\      / / _ \\| \\ | |  _ \\| ____|  _ \\  | |" << endl;
    cout << "                                    \\ \\ /\\ / / | | |  \\| | | | |  _| | |_) | | |" << endl;
    cout << "                                     \\ V  V /| |_| | |\\  | |_| | |___|  _ <  |_|" << endl;
    cout << "                                      \\_/\\_/  \\___/|_| \\_|____/|_____|_| \\_\\ (_)" << endl;
    cout << endl;
    cout <<
            "************************************************************************************************************************"
            << endl;
    cout <<
            "*                                              Winter Wonderland Math Tutor                                            *"
            << endl;
    cout <<
            "************************************************************************************************************************"
            << endl;

    int jokeType = (rand() % 4) + 1;

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

//
string GetUserName() {
    string userName; // checks for name
    // get username and welcome the user to the game
    cout << "Please enter your name: ";
    getline(cin, userName); // able to use the name entered, even if it has spaces in it
    cout << "Welcome " << userName << " to the Winter Wonderland Math Tutor! " << endl;
    cout << endl;
}

//
int GetNumericValue(int userAnswer){ //This is the function that gets the answer to the question
    int userAnswer = 0;
    while (!(cin >> userAnswer)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), // ADD LIMIT LIBRARBY TO MAKE IT WORK
                   '\n');
        cout << "\tInvalid input!" << endl;
        cout << "\tPlease enter an number: ";
    }
    return userAnswer;
}

//
string AskToPlayAgain(string username) {
}

//
void DisplaySumrEPORT(const vector<vector<int>> &question) {
}

//
bool GiveAttempts(string username, vector<int>row) {
    const int MAX_ATTEMPTS = 3;
    bool isCorrect = false;

}

//




int main() {
    // declare and initialized variables

    string userInput; // checks for yes or no

    char mathSymbol;
    //Constant variables

    const int LEVEL_RANGE_CHANGE = 10;

    int userAnswer; // checks for user number answer for math problems
    int leftNum;
    int rightNum;
    int correctAnswer;
    int tempNum;
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;

    int currentRange = LEVEL_RANGE_CHANGE;
    int i; // used for for loops, decided to put it up here for simplicity
    enum mathType { MT_ADD, MT_SUB, MT_MUL, MT_DIV };

    srand(time(0)); // takes completely random numbers and math types every time
    vector<vector<int> > questions;





do {
        // asks a randomized math question with random numbers
        mathType questionType;
        cout << userName << ", " << "Please answer the following question:" << endl;
        leftNum = (rand() % currentRange) + 1; // generates the left number at random
        rightNum = (rand() % currentRange) + 1; // generates the right number at random
        questionType = static_cast<mathType>(rand() % 4); // helps generate the type of math problem

        switch (questionType) {
            // assigns math symbol
            case MT_ADD:
                // makes the problem addition
                mathSymbol = '+';
                correctAnswer = leftNum + rightNum; // solves for the right answer
                break;
            case MT_SUB:
                // says the math type is subtraction
                mathSymbol = '-';
                if (leftNum < rightNum) {
                    // checks if the right number is bigger than the left to avoid negative answers
                    tempNum = leftNum; // swaps around the numbers so that the bigger number is on the left
                    leftNum = rightNum;
                    rightNum = tempNum;
                }
                correctAnswer = leftNum - rightNum;
                break;
            case MT_MUL:
                // sets type for multiplication
                mathSymbol = '*';
                correctAnswer = leftNum * rightNum;
                break;
            case MT_DIV:
                // sets type for division
                correctAnswer = leftNum;
                leftNum *= rightNum;
            // makes it so that the left number generated is able to be the answer to the problem
                mathSymbol = '/';
                correctAnswer = leftNum / rightNum;
                break;
            default: // output if mathType generates an invalid output
                cout << questionType << " is not a valid choice." << endl;
                cout << "Contact IsaiahGuilliatt and/or ConnerDiers about the error." << endl;
                return -1;
        }
        vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAnswer};

        for (i = 1; i <= MAX_ATTEMPTS; i++) {
            // give user 3 attempts
            cout << "[Level #" << mathLevel << "] " << userName << ", what does " << leftNum << " " << mathSymbol << " "
                    << rightNum << " = ";
            //asks the random math question generated with random numbers
            /* cout << leftNum << " " << mathSymbol << " " << rightNum << " = "; */

            while (!(cin >> userAnswer)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), // ADD LIMIT LIBRARBY TO MAKE IT WORK
                           '\n');
                cout << "\tInvalid input!" << endl;
                cout << "\tPlease enter an number: ";
            }
            cout << endl;
            if (userAnswer == correctAnswer) {
                ++totalCorrect; // increases total correct
                cout << "Woohoo! You got it right!" << endl; // happens if the answer is correct
                row.push_back(i);
                break;
            } else {

                if (i == MAX_ATTEMPTS) {
                    totalIncorrect++; // increases total incorrect
                    cout << "Whoops! Looks like you got that one wrong." << endl;
                    cout << "The correct answer is " << correctAnswer << "." << endl;
                    // happens if the answer is wrong after 3
                    row.push_back(0);
                } else {
                    cout << "Sorry you got that wrong. You have " << MAX_ATTEMPTS - i << " attempts left." << endl;
                    // tells user how many attempts they have left
                }
            }
        }
        questions.push_back(row);

        if (totalCorrect == 3) {
            // increases math level
            mathLevel = ++mathLevel;
            totalCorrect = 0; // resets the total correct and total incorrect back to 0
            totalIncorrect = 0;
            currentRange += LEVEL_RANGE_CHANGE; // raises the math rage for problems by 10
            cout << "You're now on level " << mathLevel << "." << endl; // tells user new level
            cout << "You're new range is 1 - " << currentRange << "." << endl; // tells user new range
        } else if (totalIncorrect == 3 && mathLevel > 1) {
            // makes it so the lowest level that the user can be is 1 and decreases the level by one
            mathLevel--; // lowers level by one
            totalCorrect = 0; // resets the correct and incorrect numbers counters to 0
            totalIncorrect = 0;
            currentRange -= LEVEL_RANGE_CHANGE; // lowers math range buy ten
            cout << "You're now on level " << mathLevel << "." << endl; // tells user new level
            cout << "You're new range is 1 - " << currentRange << "." << endl; // tells user new range
        }

        getline(cin, userInput);

        while (true) {
            //While loop to continue program
            cout << "Do you want to continue(y=yes or n=no)?";
            getline(cin, userInput); // check users input for letters
            for (i = 0; i < userInput.size(); i++) {
                userInput.at(i) = tolower(userInput.at(i));
            }

            if (userInput == "yes" || userInput == "y" || userInput == "n" || userInput == "no") {
                // progresses the user forward into the code
                break;
            } else {
                cout << "Invalid Input, please try again." << endl << endl;
                // output if the user enters letters instead of numbers
            }
        }

        //Swaps to \n instead of endl to make coding easier and may need to change to match the rest of the code??
    } while (userInput == "yes" || userInput == "y"); // end text for the program
    totalCorrect = 0; //changes purpose to now count how many questions ther are
    totalIncorrect = 0; //changes purpose to count total incorrect questions
    tempNum = 0; //used to show how many attempts were needed

    for (i = 0; i < 35; i++) cout << "=";
    cout << "\n|         Summary Report         |\n";

    for (i = 0; i < 35; i++) cout << "=";
    cout << "\nLevel       Question      Attempts\n" << "----- ------------------ ---------";

    //Calls data for Summary report and displays it
    for (i = 0; i < questions.size(); i++) {
        mathLevel = questions.at(i).at(0);
        leftNum = questions.at(i).at(1);
        mathSymbol = static_cast<char>(questions.at(i).at(2));
        rightNum = questions.at(i).at(3);
        correctAnswer = questions.at(i).at(4);
        tempNum = questions.at(i).at(5);
        cout << "\n  " << setw(3) << left << mathLevel << setw(6) << right << leftNum << " " << mathSymbol << " " <<
                setw(3) << left << rightNum << setw(3) << " = " << setw(3) << right << correctAnswer;

        if (tempNum == 0) {
            cout << setw(11) << "Incorrect";
            totalIncorrect++;
        } else cout << setw(7) << tempNum;
        totalCorrect++;
    }

    //displays how user did
    cout    << "\nTotal Questions :" <<setw(4)<<right<< totalCorrect //Shows total questions
            << "\nTotal Correct   :"<<setw(4)<<right << totalCorrect - totalIncorrect //no total question varible to keep help with storage
            << "\nTotal Incorrect :" <<setw(4)<<right<< totalIncorrect //shows total incorrect
            << "\nAverage Correct :" <<setw(4)<<right<< 100 - (totalIncorrect * 100 / totalCorrect) << "%\n" //shows average
            << "\nThank you for trying out our game! If you would like to play again, feel free to do so, otherwise, this game is still in development so stay tuned for updates in the future."
            << "\nEnd of program."; //End of program message
}

     return 0;
}