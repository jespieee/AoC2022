#include <bits/stdc++.h>

using namespace std;

int X = 1;
int cycleNum = 0;
int runningSum = 0;
int checkInterval = 20;
bool isCheck(int num) {

    if (num == checkInterval) {
        checkInterval += 40;
        return true;
    }
    return false;
}

void tick() {
    ++cycleNum;
    if (isCheck(cycleNum)) {
        runningSum += cycleNum * X;
    }
    return;
}

void noop() {
    tick();
    return;
}

void addx(int adder) {
    tick();
    tick();
    X += adder; 
    return;
}

int main() {
    
    ifstream input("../DayTen/input.txt");
    string command;
    
    while (getline(input, command)) {
        
        if (command[0] == 'n') {
            noop();
        }
        else if (command[0] == 'a') {
            // call addx
            int adder = stoi(command.substr(5, command.length()));
            addx(adder);
        }
    }

    cout << "The answer is: " << runningSum << endl;
    return 0;
}