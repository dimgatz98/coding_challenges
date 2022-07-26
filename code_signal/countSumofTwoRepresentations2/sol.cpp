#include <iostream>

using namespace std;

int solution(int n, int l, int r) {
    if (n / 2 < l) {
        return 0;
    }
    if (l == r && 2 * l == n) {
        return 1;
    }

    return ((float) n / 2 == (int) n / 2 ? min (n / 2 - l, r - n / 2) + 1 : min (n / 2 - l, r - n / 2));
}

int main () {
    int n, l, r;

    cin >> n >> l >> r;

    cout << solution (n, l, r) << endl;
}
