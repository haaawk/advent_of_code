#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    vector<vector<char>> pad = {
        {'0', '0', '1', '0', '0'},
        {'0', '2', '3', '4', '0'},
        {'5', '6', '7', '8', '9'},
        {'0', 'A', 'B', 'C', '0'},
        {'0', '0', 'D', '0', '0'},
    };
    int x = 2, y = 0;
    while (getline(cin, line)) {
        for (char c : line) {
            switch(c) {
                case 'U': if (x > 0 && pad[x - 1][y] != '0') --x; break;
                case 'D': if (x < 4 && pad[x + 1][y] != '0') ++x; break;
                case 'L': if (y > 0 && pad[x][y - 1] != '0') --y; break;
                case 'R': if (y < 4 && pad[x][y + 1] != '0') ++y; break;
            }
        }
        cout << pad[x][y];
    }
    return 0;
}
