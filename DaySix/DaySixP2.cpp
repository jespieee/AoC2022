#include <bits/stdc++.h>

using namespace std;

bool validSet(string s) {
    unordered_set<char> set;
    for (int i = 0; i < s.length(); ++i) {
        if (set.count(s[i])) {
            return false;
        }
        set.insert(s[i]);
    }
    return true;
}

int main() {
    
    ifstream input("../DaySix/input.txt");
    string line;
    getline(input, line);
    // cout << line << endl;
    int l = 0, r = 13;
    while (r < line.length()) {
        string curr = line.substr(l, 14);
        if (validSet(curr)) {
            cout << r + 1 << endl;
            break;
        }
        ++l;
        ++r;
    }
    

    return 0;
}