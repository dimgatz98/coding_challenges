#include <iostream>
#include <vector>

using namespace std;

vector<long> memo(30);

long fibonacci(int n) {
    if (n <= 2) {
        memo[n] = 1;
        return 1;
    }
    if (memo[n] != 0) {
        return memo[n];
    }
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}