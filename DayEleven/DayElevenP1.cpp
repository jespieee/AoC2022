#include <bits/stdc++.h>

using namespace std;

class Monkey {
private:
    deque<int> items;
    int test;
    int operation;
public:
    Monkey() {

    }
    Monkey(deque<int> starting, int operation, int test) {
        this->items = starting;
        this->operation = operation;
        this->test = test;
    }
    void throwItem(Monkey& thrower, Monkey& receiver) {
        receiver.items.push_front(thrower.items.front());
        thrower.items.pop_front();
    }
};


int main() {


    return 0;
}