#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string step;
    int dir = 0;
    int x = 0, y = 0;
    while (cin >> step) {
        dir += step[0] == 'R' ? 1 : 3;
        dir %= 4;
        int moves = atoi(step.c_str() + 1);
        switch (dir) {
            case 0: x -= moves; break;
            case 1: y += moves; break;
            case 2: x += moves; break;
            case 3: y -= moves; break;
        }
    }
    cout << abs(x) + abs(y) << endl;
    return 0;
}
