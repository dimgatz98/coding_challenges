#include <string>
#include <stack>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    stack<string> strings;
    stack<char> brackets;
    stack<int> nums;
    string res, tmp;

    for (auto c: s) {
        if (c == '(') {
            strings.push("");
            continue;
        } else if (c == ')') {
            tmp = strings.top();
            strings.pop();
            reverse(tmp.begin(), tmp.end());
            if (strings.empty()) {
                res += tmp;
            } else {
                tmp = strings.top() + tmp;
                strings.pop();
                strings.push(tmp);
            }
        } else {
            if (strings.empty()) {
                res.push_back(c);
            } else {
                tmp = strings.top();
                tmp.push_back(c);
                strings.pop();
                strings.push(tmp);
            }
        }
    }

    return res;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    cout << solution (str) << endl;

    return 0;
}
