#include <string>
#include <iostream>

using namespace std;

string solution(int level, int pos) {
    string tmp;

    if (level == 1) {
        return "Engineer";
    }

    bool same = (((pos - 1) % 2 == 0) ? true : false);

    if (same) return solution(level - 1, ((pos - 1) / 2) + 1);
    else {
        tmp = solution(level - 1, pos / 2);
        if (tmp == "Engineer") {
            return "Doctor";
        } else {
            return "Engineer";
        }
    }
}

int main () {
    int level, pos;
    cin >> level >> pos;
    cout << solution(level, pos) << endl;
}