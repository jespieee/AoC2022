#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


int totalScore = 0;

int scoreChecker(char c) {
    if (c == 'a' || c == 'x') {
        return 1;
    }
    else if (c == 'b' || c =='y') {
        return 2;
    }
    return 3;
}

char oppositeWin(char c) {
    if (c == 'a') {
        return 'y';
    }
    else if (c == 'b') {
        return 'z';
    }
    return 'x';
}

char oppositeLose(char c) {
    if (c == 'a') {
        return 'z';
    }
    else if (c == 'b') {
        return 'x';
    }
    return 'y';
}

int decision(char opp, char my) {
    // x lose, y draw, z win
    if (my == 'x') {
        return scoreChecker(oppositeLose(opp));
    }
    else if (my == 'y') {
        return 3 + scoreChecker(opp);
    }
    return 6 + scoreChecker(oppositeWin(opp));
}

int main() {

    ifstream input("../DayTwo/DayTwo.txt");
    string currLine;
    while (getline(input, currLine)) {
        char oppMove = tolower(currLine[0]);
        char myMove = tolower(currLine[2]);
        totalScore += decision(oppMove, myMove);
    }
    cout << totalScore << endl;
    return 0;
}

