#include <bits/stdc++.h>

using namespace std;

class CommSystem {
public:
  void noop() {
    tick();
  };

  void addx(const int val) {
    tick();
    tick();
    X += val;
  }

  long long get_signal_strength() {
    return signal_strength;
  }

  void print_screen() {
    for(const auto& row : screen) {
      for (const auto ele : row) {
        cout << ele;
      }
      cout << '\n';
    }
  }


private:

  void update_crt() {
    const auto pixel_id = (cycle_count  - 1) % 240;
    const auto pixel_row = pixel_id / 40;
    const auto pixel_col = pixel_id % 40;
    if (pixel_col == X || pixel_col == (X - 1) || pixel_col == (X + 1)) {
      screen[pixel_row][pixel_col] = '#';
    } 
    else {
      screen[pixel_row][pixel_col] = '.';
    }
  }

  void tick() {
    cycle_count++;
    update_crt();
    if ((cycle_count - 20) % 40 == 0) {
      signal_strength += cycle_count * X;
    }
  }

  long long X = 1;
  long long cycle_count = 0;
  long long signal_strength = 0;
  array<array<char, 40>, 6> screen = {};
};


int main(int argc, char * argv[]) {
  
  
  ifstream file("../DayTen/input.txt");
  string line;
  CommSystem cs;

  while(getline(file, line)) {
    // cout << line << '\n';
    const auto space = line.find(' ');
    const auto instr = line.substr(0, space);
    if (instr == "noop") {
      cs.noop();
    } 
    else if (instr == "addx") {
      cs.addx(stoi(line.substr(space + 1, line.size() - space - 1)));
    }
  }

  cs.print_screen();

  return 0;
}