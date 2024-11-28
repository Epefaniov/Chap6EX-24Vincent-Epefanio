/*
    Assingment: Chapter 6 Excersise 24

    Programmer: Vincent Epefanio

    Date: 11/27/2024

    Reqirements: Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. The program should work as follows:

    1. When the program begins, a random number in the range of 1 through 3 is generated. If the number is 1, then the computer has chosen rock. If the number is 2, then the computer has chosen paper. If the number is 3, then the computer has chosen scissors. (Don’t display the computer’s choice yet.)

    2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard. (You can use a menu if you prefer.) 

    3. The computer’s choice is displayed.

    4. A winner is selected according to the following rules:

      • If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)

      • If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.)

      • If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)

      • If both players make the same choice, the game must be played again to determine the winner.

    Be sure to divide the program into functions that perform each major task.

*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int getComputerChoice() {
    return rand() % 3 + 1;  
}


string getUserChoice() {
    string userChoice;
    while (true) {
        cout << "Enter your choice (rock, paper, or scissors): ";
        cin >> userChoice;

        
        for (auto &c : userChoice) {
            c = tolower(c);
        }

        if (userChoice == "rock" || userChoice == "paper" || userChoice == "scissors") {
            return userChoice;
        } else {
            cout << "Invalid choice, please enter 'rock', 'paper', or 'scissors'." << endl;
        }
    }
}


string determineWinner(const string &userChoice, int computerChoice) {
    if (userChoice == "rock" && computerChoice == 3)  
        return "You win!";
    else if (userChoice == "scissors" && computerChoice == 2)  
        return "You win!";
    else if (userChoice == "paper" && computerChoice == 1)  
        return "You win!";
    else if ((userChoice == "rock" && computerChoice == 1) || 
             (userChoice == "scissors" && computerChoice == 3) || 
             (userChoice == "paper" && computerChoice == 2)) {
        return "It's a tie! Let's play again.";
    }
    else {
        return "The computer wins!";
    }
}


void displayChoices(const string &userChoice, int computerChoice) {
    string computerChoiceStr;
    switch (computerChoice) {
        case 1: computerChoiceStr = "rock"; break;
        case 2: computerChoiceStr = "paper"; break;
        case 3: computerChoiceStr = "scissors"; break;
    }
    cout << "\nYou chose: " << userChoice << endl;
    cout << "The computer chose: " << computerChoiceStr << endl;
}

void playGame() {
    srand(time(0));  

    while (true) {
        
        int computerChoice = getComputerChoice();

        
        string userChoice = getUserChoice();

        
        displayChoices(userChoice, computerChoice);

        
        string result = determineWinner(userChoice, computerChoice);
        cout << result << endl;

        
        if (result != "It's a tie! Let's play again.") {
            break;
        }
    }
}

int main() {
    playGame();  
    return 0;
}
