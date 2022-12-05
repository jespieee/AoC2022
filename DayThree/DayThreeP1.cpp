#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ifstream input("../DayThree/DayThree.txt");
    int runningSum = 0;
    string ruckSack;

    while (getline(input, ruckSack)) {
        int sz = ruckSack.size();
        cout << ruckSack;
        cout << endl;
        string comp1 = ruckSack.substr(0, sz / 2);
        string comp2 = "";
        for (int i = sz - 1; i > sz / 2 - 1; i--) {
            comp2 += ruckSack[i];
        }
        reverse(comp2.begin(), comp2.end());
        cout << comp1 << " BREAK " << comp2 << endl;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for (int i = 0; i < comp1.size(); i++) {
            map1[comp1[i]]++;
        }
        for (int i = 0; i < comp2.size(); i++) {
            map2[comp2[i]]++;
        }
        for (auto i : map1) {
            if (map2[i.first] > 0 && i.second > 0) {
                // add priority
                if (i.first >= 97 && i.first <= 122) {
                    runningSum += i.first - 96;
                }
                else {
                    runningSum += i.first - 38;
                }
                break;
            }
        }
    }
    cout << runningSum << endl;
    return 0;
}