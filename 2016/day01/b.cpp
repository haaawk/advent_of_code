#include <iostream>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int main() {
    string step;
    int dir = 0;
    int x = 0, y = 0;
    set<pair<int, int>> seen;
    seen.insert(make_pair(x, y));
    auto walk = [&] (int xv, int yv, int count) {
        while (count-- > 0) {
            x += xv;
            y += yv;
            if (!seen.insert(make_pair(x, y)).second) {
                return true;
            }
        }
        return false;
    };
    while (cin >> step) {
        dir += step[0] == 'R' ? 1 : 3;
        dir %= 4;
        int xv = 0, yv = 0;
        switch (dir) {
            case 0: xv = -1; break;
            case 1: yv = 1; break;
            case 2: xv = 1; break;
            case 3: yv = -1; break;
        }
        if (walk(xv, yv, atoi(step.c_str() + 1))) {
            break;
        }
    }
    cout << abs(x) + abs(y) << endl;
    return 0;
}
