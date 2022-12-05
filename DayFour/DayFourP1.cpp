#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

int totalOverlap = 0;

int main() {
    ifstream input("../DayFour/DayFour.txt");
    string section;
    vector<string> sectionPair(2);
    while (getline(input, section)) {
        // s1 start
        string s1 = "", s2 = "", s3 = "", s4 = "";
        int firstDash = section.find('-', 0);
        int secondDash = section.find('-', firstDash + 1);
        int comma = section.find(',');
        s1 = section.substr(0, firstDash);
        s2 = section.substr(firstDash + 1, comma - firstDash - 1);
        s3 = section.substr(comma + 1, secondDash - comma - 1);
        s4 = section.substr(secondDash + 1, section.length());
        // cout << s1 << " " << s2 << " " << s3 << " " << s4;
        int s1Start = stoi(s1), s1End = stoi(s2);
        int s2Start = stoi(s3), s2End = stoi(s4);
        if (s1Start <= s2Start && s1End >= s2End) {
            totalOverlap++;
        }
        else if (s2Start <= s1Start && s2End >= s1End) {
            totalOverlap++;
        }
    }

    cout << totalOverlap << endl;

    return 0;
}