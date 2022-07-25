#include <iostream>

using namespace std;

int solution(int n) {
  return ((1431655765 & n) << 1) | ((2863311530 & n) >> 1);
}

int main() {
    int n;
    cin >> n;

    cout << solution (n) << endl;
}
