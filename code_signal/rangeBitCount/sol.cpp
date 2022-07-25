#include <iostream>

using namespace std;

int solution(int a, int b) {
    int res = 0, tmp;
    for (int i = a ; i <= b ; i++) {
        tmp = i;
        while (tmp > 0) {
            if (tmp % 2 == 1) {
                res++;
            }
            tmp = tmp >> 1;
        }
    }

    return res;
}

int main () {
    int a, b;
    cin >> a >> b;
    cout << solution (a, b) << endl;
}