#include <string>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool solution(string cell1, string cell2) {
    int c1 = cell1[0] - 'A' + cell1[1] - '0', c2 = cell2[0] - 'A' + cell2[1] - '0';
    return (max(c1, c2) - min(c1, c2)) % 2 == 0;
}

int main () {
    string cell1, cell2;
    cin >> cell1 >> cell2;

    cout << (solution (cell1, cell2) ? "true" : "false") << endl;

    return 0;
}