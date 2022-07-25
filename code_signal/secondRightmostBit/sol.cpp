#include <iostream>

using namespace std;

int solution(int n) {
  return ~ (n + (~n & (n+1))) & (n + (~n & (n+1)) + 1);
}

int main() {
    int n;
    cin >> n;
    cout << solution (n) << endl;
}