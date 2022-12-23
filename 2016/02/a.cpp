#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<vector<int>> pad = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int x = 1, y = 1;
    while (getline(cin, line)) {
        for (char c : line) {
            switch(c) {
                case 'U': if (x > 0) --x; break;
                case 'D': if (x < 2) ++x; break;
                case 'L': if (y > 0) --y; break;
                case 'R': if (y < 2) ++y; break;
            }
        }
        cout << pad[x][y];
    }
    return 0;
}
