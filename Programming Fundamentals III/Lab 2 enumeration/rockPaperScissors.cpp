#include <iostream>

using namespace std;

enum rps {
    ROCK,
    PAPER,
    SCISSORS
};

void displayRules() {
    cout << "Two players play this game.\n\n"
         << "Each player enters R or r for Rock, P or p for Paper, or S or s for Scissors.\n\n"
         << "Once both entries are in, if the entries are valid, the program outputs the\n"
         << "players' choices and declares the winner of the play. The game continues until\n"
         << "one of the players decides to quit the game."  << endl << endl;
}

bool validSelection(char selection) {
    selection = toupper(selection);

    if(selection == 'R' || selection == 'P' || selection == 'S') {
        return true;
    } else {
        return false;
    }
}

rps retrievePlay(char selection) {
    rps choice;

    selection = toupper(selection);

    if(selection == 'R') choice = rps::ROCK;
    else if(selection == 'P') choice = rps::PAPER;
    else choice = rps::SCISSORS;

    return choice;
}

string convertEnum(int selection) {
    switch(selection) {
        case 0:
            return "ROCK";
        case 1:
            return "PAPER";
        case 2:
            return "SCISSORS";
        default:
            break;
    }
}

void gameResult(rps selectionOne, rps selectionTwo, string& winner) {
    // cout << "Player 1 chose " << convertEnum(selectionOne) << " and Player 2 chose " << convertEnum(selectionTwo) << endl;
    if(selectionOne == rps::ROCK && selectionTwo == rps::SCISSORS || (selectionOne - selectionTwo) == rps::PAPER) {
        winner = "Player 1";
    }
    else if(selectionTwo == rps::ROCK && selectionOne == rps::SCISSORS || (selectionTwo - selectionOne) == rps::PAPER) {
        winner = "Player 2";
    }

    if(selectionOne == selectionTwo) {
        cout << "This is a tie game." << endl << endl;
    }
    else {
        cout << winner << " wins" << endl << endl;
    }
}

void displayResults(int& winCount1, int& winCount2, int& gameCount) {
    cout << "Number of games played: " << gameCount << endl << endl;
    cout << "Player 1 Win Count: " << winCount1 << endl;
    cout << "Player 2 Win Count: " << winCount2 << endl;
}

int main() {
    char playerOneResponse, playerTwoResponse, playerOneSelection, playerTwoSelection;
    string winner = "";
    int gameCount = 0, winCount1 = 0, winCount2 = 0;

    displayRules();

    while(playerOneResponse != 'Y' && playerOneResponse != 'N' && playerTwoResponse != 'Y' && playerTwoResponse != 'N') {
        cout << "Does player 1 want to play? (Y/N): ";
        cin >> playerOneResponse;
        cout << "Does player 2 want to play? (Y/N): ";
        cin >> playerTwoResponse;
        playerOneResponse = (playerOneResponse);
        playerTwoResponse = (playerTwoResponse);
    }

    while(playerOneResponse == 'Y' && playerTwoResponse == 'Y') {
        cout << "Player 1 selection: ";
        cin >> playerOneSelection;
        cout << "Player 2 selection: ";
        cin >> playerTwoSelection;

        if(validSelection(playerOneSelection) && validSelection(playerTwoSelection)) {
            gameResult(retrievePlay(playerOneSelection), retrievePlay(playerTwoSelection), winner);
        }
        ++gameCount;
        if(winner == "Player 1") {
            ++winCount1;
        }
        else if(winner == "Player 2"){
            ++winCount2;
        }
        playerOneResponse = ' ';
        playerTwoResponse = ' ';
        while(playerOneResponse != 'Y' && playerOneResponse != 'N' && playerTwoResponse != 'Y' && playerTwoResponse != 'N') {
            cout << "Does player 1 want to play? (Y/N): ";
            cin >> playerOneResponse;
            cout << "Does player 2 want to play? (Y/N): ";
            cin >> playerTwoResponse;
        }
    }

    displayResults(winCount1, winCount2, gameCount);

    cout << endl << "Code by Jacob Smetana" << endl;
    return 0;
}
