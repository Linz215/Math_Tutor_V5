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
    cout << "Hello, World!" << endl;
    return 0;
}

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