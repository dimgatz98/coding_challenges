#include <iostream>

using namespace std;

int solution(int a, int b, int n) {

    return a * b * n + (a + b) * n * (n - 1) / 2
           + n * (n - 1) * (2 * n - 1) / 6;
}

int main () {
    int a, b, n;
    cin >> a >> b >> n;
    cout << solution (a,b,n) << endl;
}
