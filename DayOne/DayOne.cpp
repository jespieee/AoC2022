#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> calories(1000);

int day1part1() {
    ifstream input("../DayOne/DayOne.txt");
    int currSum = 0;
    string curr;
    while (getline(input, curr)) {
        if (curr == "") {
            calories.push_back(currSum);
            currSum = 0;
        }
        else {
            currSum += stoi(curr);
        }
    }
    sort(calories.begin(), calories.end(), greater<int>());
    return calories[0];
}

int day1part2() {
    return calories[0] + calories[1] + calories[2];
}

int main() {
    cout << "Part 1: " << day1part1() << endl;
    cout << "Part 2: " << day1part2() << endl;
    return 0;
}
