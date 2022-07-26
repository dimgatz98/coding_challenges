#include <iostream>

using namespace std;

int solution(int n, int m) {
  return ~ (~ (n ^ m)) & (~ (n ^ m) + 1);
}

int main () {
    int n, m;
    cin >> n >> m;
    cout << solution (n, m) << endl;
}