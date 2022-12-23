#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    int res = 0;
    while (cin >> a >> b >> c) {
        if (a < b + c && b < a + c && c < a + b) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
