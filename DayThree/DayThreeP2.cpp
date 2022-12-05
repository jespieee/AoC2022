#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int longestString(string one, string two, string three) {
    int sz1 = one.length();
    int sz2 = two.length();
    int sz3 = three.length();
    if (sz2 > sz1 && sz2 > sz3) {
        return 1;
    }
    else if (sz3 > sz2 && sz3 > sz1) {
        return 2;
    }
    return 0;
}

int main() {
    ifstream input("../DayThree/DayThree.txt");
    int runningSum = 0;
    string ruckSack;
    int groupCounter = 0;
    int lineNumber = 1, groupNumber = 1;
    vector<string> group;
    while (getline(input, ruckSack)) {
        ++lineNumber;
        if (groupCounter == 3) {
            // find common letter in group
            ++groupNumber;
            string first = group[0];
            string second = group[1];
            string third = group[2];
            int maxIndex = longestString(first, second, third);
            for (int i = 0; i < group[maxIndex].size(); i++) {
                char c = group[maxIndex][i];
                if (first.find(c) != string::npos && second.find(c) != string::npos && third.find(c) != string::npos) {
                    if (c >= 97 && c <= 122) {
                        runningSum += c - 96;
                    }
                    else {
                        runningSum += c - 38;
                    }
                    break;
                }
            }
            // erase group
            group.clear();
            groupCounter = 0;
        }
        group.push_back(ruckSack);
        ++groupCounter;

    }
    cout << runningSum << endl;
    cout << lineNumber << endl;
    cout << groupNumber << endl;
    return 0;
}