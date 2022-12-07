#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
    auto const num_trials{argc > 1 ? atoi(argv[1]) : 1};
    for (auto t{0}; t < num_trials; ++t) {
        ifstream in{"../DaySeven/input.txt"};
        vector<int> path{};
        path.reserve(32);
        vector<int> dir_sizes{};
        path.reserve(256);

        auto p1{0};
        auto total{0};

        auto const up{[&path, &dir_sizes, &p1, &total]() {
            dir_sizes.push_back(path.back());
            path.pop_back();
            if (!path.empty()) { 
                path.back() += dir_sizes.back(); 
            }

            if (dir_sizes.back() < 100000) {
                p1 += dir_sizes.back();
            }
            total = max(total, dir_sizes.back());
        }};

        for (string line; getline(in, line);) {
            if (line[0] == '$') {
                if (line[2] != 'c') {
                    continue; // we're only interested in `cd` commands
                }
                if (line[5] == '.') {
                    up();
                }
                else {
                    path.push_back(0);
                }
            } 
            else if (line[0] != 'd') {
                int num{0};
                for (auto i{0}; line[i] != ' '; ++i) {
                    num = num * 10 + line[i] - '0';
                }
                path.back() += num;
            }
        }

        while (!path.empty()) {
            up();
        }

        auto p2{30000000};
        for (auto const& v : dir_sizes) {
            if (v >= (total - 40000000)) p2 = min(p2, v);
        }
        cout << p1 << endl;
    }
    return 0;
}