#include <bits/stdc++.h>

using namespace std;

void customStoi(string s, vector<int>& row) {
    for (int i = 0; i < s.length(); i++) {
        row.push_back(s[i] - '0');
    }
    return;
}

int viewScore(vector<vector<int>>& grid, int row, int col) {
    
    int n = grid.size();
    int m = grid[0].size();
    int left = 0, right = 0, up = 0, down = 0;
    // check left
    int leftIter = col - 1;
    while (leftIter >= 0) {
        if (grid[row][leftIter] < grid[row][col]) {
            left++;
            leftIter--;
        }
        else if (grid[row][leftIter] == grid[row][col]) {
            left++;
            break;
        }
        else {
            break;
        }
    }
    // check right
    int rightIter = col + 1;
    while (rightIter < m) {
        if (grid[row][rightIter] < grid[row][col]) {
            right++;
            rightIter++;
        }
        else if (grid[row][rightIter] == grid[row][col]) {
            right++;
            break;
        }
        else {
            break;
        }
    }
    // check up
    int upIter = row - 1;
    while (upIter >= 0) {
        if (grid[upIter][col] < grid[row][col]) {
            up++;
            upIter--;
        }
        else if (grid[upIter][col] == grid[row][col]) {
            up++;
            break;
        }
        else {
            break;
        }
    }
    // check down
    int downIter = row + 1;
    while (downIter < n) {
        if (grid[downIter][col] < grid[row][col]) {
            down++;
            downIter++;
        }
        else if (grid[downIter][col] == grid[row][col]) {
            down++;
            break;
        }
        else {
            break;
        }
    }
    return left * right * up * down;
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
    
    int n = grid.size(), m = grid[0].size(), ans = INT_MIN;
    for (int row = 1; row < n; ++row) {
        for (int col = 1; col < m; ++col) {
            ans = max(ans, viewScore(grid, row, col));
        }
    }
    cout << ans << endl;
    return 0;
}