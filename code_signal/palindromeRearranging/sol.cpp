#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool solution(string inputString) {
    unordered_map<char, int> m;

    for (auto c: inputString) {
        if (m.find(c) == m.end()) {
            m.insert({c, 1});
            continue;
        }

        m[c]++;
    }

    int counter = 0;
    for (auto it: m) {
        if (it.second % 2 == 1) {
            counter++;
            if (counter == 2) {
                return false;
            }
        }
    }

    return true;
}

int main () {
    string str;

    cin >> str;

    cout << (solution (str) ? "true" : "false") << endl;

    return 0;
}
