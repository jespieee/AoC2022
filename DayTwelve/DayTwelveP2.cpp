#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dirs = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int bfs(vector<string>& grid, pair<int, int>& start, pair<int, int>& end) {
    queue<pair<int, pair<int, int>>> q;
    int height = grid.size();
    int width = grid[0].size();

    q.emplace(0, start);
    bool visited[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            visited[i][j] = false;
        }
    }

    while (!q.empty()) {
        int depth;
        pair<int, int> curr;
        tie(depth, curr) = q.front();
        q.pop();

        if (visited[curr.first][curr.second]) {
            continue;
        }

        visited[curr.first][curr.second] = true;

        if (curr.first == end.first && curr.second == end.second){
            return depth;
        };

        for (auto &dir : dirs) {
            int newX = curr.first + dir.first;
            int newY = curr.second + dir.second;

            if (newX < 0 || newY < 0 || newX >= height || newY >= width) {
                continue;
            }

            if (grid[newX][newY] <= grid[curr.first][curr.second] + 1) {
                q.emplace(depth + 1, make_pair(newX, newY));
            }
        }
    }
    return INT_MAX;
}

int main() {

    ifstream input("../DayTwelve/input.txt");
    string line;
    vector<string> grid;

    pair<int, int> start, end;

    while (getline(input, line)) {
        grid.push_back(line);
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == 'S') {
                grid[grid.size() - 1][i] = 'a';
            }
            else if (line[i] == 'E') {
                end = {grid.size() - 1, i};
                grid[end.first][end.second] = 'z';
            }
        } 
    }

    int minSteps = INT_MAX;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if (grid[i][j] == 'a') {
                start = {i, j};
                minSteps = min(minSteps, bfs(grid, start, end));
            }
        }
    }
    cout << minSteps << endl;
}