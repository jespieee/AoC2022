#include <bits/stdc++.h>

using namespace std;

//     [H]         [D]     [P]        
// [W] [B]         [C] [Z] [D]        
// [T] [J]     [T] [J] [D] [J]        
// [H] [Z]     [H] [H] [W] [S]     [M]
// [P] [F] [R] [P] [Z] [F] [W]     [F]
// [J] [V] [T] [N] [F] [G] [Z] [S] [S]
// [C] [R] [P] [S] [V] [M] [V] [D] [Z]
// [F] [G] [H] [Z] [N] [P] [M] [N] [D]
//  1   2   3   4   5   6   7   8   9 

void mover(deque<char> &take, deque<char> &place, int numMoves) {
    stack<char> temp;
    for (int i = 0; i < numMoves; i++) {
        temp.push(take.back());
        take.pop_back();
    }
    while (!temp.empty()) {
        place.push_back(temp.top());
        temp.pop();
    }
    return;
}
int main() {

    unordered_map<int, deque<char>> map;
    map[1] = {'F', 'C', 'J', 'P', 'H', 'T', 'W'};
    map[2] = {'G', 'R', 'V', 'F', 'Z', 'J', 'B', 'H'};
    map[3] = {'H', 'P', 'T', 'R'};
    map[4] = {'Z', 'S', 'N', 'P', 'H', 'T'};
    map[5] = {'N', 'V', 'F', 'Z', 'H', 'J', 'C', 'D'};
    map[6] = {'P', 'M', 'G', 'F', 'W', 'D', 'Z'};
    map[7] = {'M', 'V', 'Z', 'W', 'S', 'J', 'D', 'P'};
    map[8] = {'N', 'D', 'S'};
    map[9] = {'D', 'Z', 'S', 'F', 'M'};

    ifstream input("../DayFive/input.txt");
    string instruct;

    while (getline(input, instruct)) {
        string numMoves = "", take = "", place = "";
        if (isdigit(instruct[6])) {
            numMoves = instruct.substr(5, 2);
            take = instruct[13];
            place = instruct[18];
        }
        else {
            numMoves = instruct[5];
            take = instruct[12];
            place = instruct[17];
        }
        cout << numMoves << " " << take << " " << place << endl;
        mover(map[stoi(take)], map[stoi(place)], stoi(numMoves));
    }
    cout << "Column 1: " << map[1].back() << endl;
    cout << "Column 2: " << map[2].back() << endl;
    cout << "Column 3: " << map[3].back() << endl;
    cout << "Column 4: " << map[4].back() << endl;
    cout << "Column 5: " << map[5].back() << endl;
    cout << "Column 6: " << map[6].back() << endl;
    cout << "Column 7: " << map[7].back() << endl;
    cout << "Column 8: " << map[8].back() << endl;
    cout << "Column 9: " << map[9].back() << endl;
    return 0;
}