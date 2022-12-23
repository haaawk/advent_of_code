#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    int d, e, f;
    int g, h, i;
    int res = 0;
    auto check = [&] (int a, int b, int c) {
        if (a < b + c && b < a + c && c < a + b) {
            ++res;
        }
    };
    while (cin >> a >> d >> g >> b >> e >> h >> c >> f >> i) {
        check(a, b, c);
        check(d, e, f);
        check(g, h, i);
    }
    cout << res << endl;
    return 0;
}
