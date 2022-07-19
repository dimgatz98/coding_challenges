#include <string>
#include <stack>
#include <iostream>

using namespace std;

string solution(string path) {
    stack<string> s;
    string dir = "", res = "";

    for (auto c: path) {
        if (c == '/') {
            if (dir == "" || dir == ".") {
                dir = "";
                continue;
            } else if (dir == "..") {
                if (! s.empty()) s.pop();
                dir = "";
                continue;
            }

            s.push(dir);
            dir = "";
            continue;
        }

        dir.push_back(c);
    }

    if (dir != "") {
        if (dir == "..") {
            if (! s.empty()) s.pop();
        } else if (dir != ".") {
            s.push(dir);
        }
    }

    while (! s.empty()) {
        res.insert(0, '/' + s.top());
        s.pop();
    }

    return (res == "" ? "/" : res);
}

int main () {
    string path;
    cin >> path;

    cout << solution (path) << endl;
}
