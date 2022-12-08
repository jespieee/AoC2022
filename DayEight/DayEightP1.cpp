#include <bits/stdc++.h>

using namespace std;

void customStoi(string s, vector<int>& row) {
    for (int i = 0; i < s.length(); i++) {
        row.push_back(s[i] - '0');
    }
    return;
}

bool isBorder(vector<vector<int>>& grid, int row, int col) {
    int rowNum = grid.size();
    int colNum = grid[0].size();
    if (row == 0 || row == grid.size() - 1) {
        return true;
    }
    else if (col == 0 || col == grid[0].size() - 1) {
        return true;
    }
    return false;
}

bool isVisible(vector<vector<int>>& grid, int row, int col) {
    int curr = grid[row][col];
    int n = grid.size();
    int m = grid[0].size();
    bool one = true, two = true, three = true, four = true;
    // check left
    for (int i = 0; i < col; ++i) {
        if (grid[row][i] >= curr) {
            one = false;
        }
    }
    // check right
    for (int i = m - 1; i > col; --i) {
        if (grid[row][i] >= curr) {
            two = false;
        }
    }
    // check up
    for (int i = 0; i < row; ++i) {
        if (grid[i][col] >= curr) {
            three = false;
        }
    }
    // check down
    for (int i = n - 1; i > row; --i) {
        if (grid[i][col] >= curr) {
            four = false;
        }
    }
    if (one || two || three || four) {
        return true;
    }
    return false;
}
int main() {
    ifstream input("../DayEight/input.txt");
    string line;
    int rowNum = 0;
    vector<vector<int>> grid;
    while (getline(input, line)) {
        vector<int> row;
        customStoi(line, row);
        grid.push_back(row);
    }
    
    int numVisible = (grid.size() * 2) + (grid[0].size() - 2) * 2;
    cout << numVisible << endl;
    // start from inside border
    for (int row = 1; row < grid.size() - 1; ++row) {
        for (int col = 1; col < grid[0].size() - 1; ++col) {
            if (isVisible(grid, row, col)) {
                numVisible++;
            }
        }
    }
    cout << numVisible << endl;
    return 0;
}