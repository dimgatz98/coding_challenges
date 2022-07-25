#include <iostream>

using namespace std;

int solution(int n, int k) {
  return n & ~(1 << (k - 1));
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << solution (n, k) << endl;
}

