#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int totalScore = 0;

int scoreChecker(char c) {
    if (c == 'x') {
        return 1;
    }
    else if (c == 'y') {
        return 2;
    }
    return 3;
}

bool isWin(char opp, char my) {
    if (opp == 'a' && my == 'y') { // rock v paper
        return true;
    }
    else if (opp == 'b' && my == 'z') { // paper v scissors
        return true;
    }
    else if (opp == 'c' && my == 'x') { // scissors v rock
        return true;
    }
    return false;
}

bool isDraw (char opp, char my) {
    if (opp == 'a' && my == 'x') { // rock v rock
        return true;
    }
    else if (opp == 'b' && my == 'y') { // paper v paper
        return true;
    }
    else if (opp == 'c' && my == 'z') { // scissors v scissors
        return true;
    }
    return false;
}

int main() {

    ifstream input("../DayTwo/DayTwo.txt");
    string currLine;
    while (getline(input, currLine)) {
        char oppMove = tolower(currLine[0]);
        char myMove = tolower(currLine[2]);
        totalScore += scoreChecker(myMove);
        // draw
        if (isDraw(oppMove, myMove)) {
            totalScore += 3;
        }
        // win
        else if (isWin(oppMove, myMove)) {
            totalScore += 6;
        }
    }
    cout << totalScore << endl;
    return 0;
}

