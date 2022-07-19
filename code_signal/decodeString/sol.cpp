#include <string>
#include <iostream>
#include <stack>

using namespace std;

string solution(string s) {
    stack<string> strings;
    stack<char> brackets;
    stack<int> nums;
    string res, tmp, repeat, num;
    bool was_digit = false;

    for (auto c: s) {
        if (isdigit(c)) {
            if (was_digit) {
                num += c;
                nums.pop();
                nums.push(stoi(num));
                continue;
            }
            was_digit = true;
            num += c;
            nums.push(stoi(num));
            continue;
        }
        was_digit = false;
        num = "";

        if (c == '[') {
            brackets.push(c);
            strings.push("");
            continue;
        } else if (c == ']') {
            brackets.pop();
            tmp = strings.top();
            strings.pop();
            repeat = tmp;

            for (int i = 0 ; i < nums.top() - 1 ; i++) {
                repeat += tmp;
            }
            if (brackets.empty()) {
                res += repeat;
                continue;
            }
                tmp = strings.top();
                strings.pop();
                strings.push(tmp + repeat);
            nums.pop();
        } else {
            if (brackets.empty()) {
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
    string s;
    cin >> s;

    cout << solution (s) << endl;

    return 0;
}
