#include <string>
#include <iostream>

using namespace std;

bool is_number(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

bool assert_no_trailing_zeros (const std::string& s) {
    if (s[0] == '0' && (int) s.size() > 1) {
        return false;
    }
    return true;
}

bool solution(string inputString) {
    string token;
    size_t pos = 0;
    int dots = 0;

    while ((pos = inputString.find('.')) != std::string::npos) {
        dots++;
        token = inputString.substr(0, pos);
        if (! is_number(token) || (int) token.size() > 3) {
            return false;
        }
        else  {
            if (stoi(token) > 255 || ! assert_no_trailing_zeros(token)) {
                return false;
            }
        }
        inputString.erase(0, pos + 1);
    }

    if (! is_number(inputString) || (int) inputString.size() > 3) {
        return false;
    }
    else  {
        if (stoi(inputString) > 255 || ! assert_no_trailing_zeros(inputString)) {
            return false;
        }
    }

    return (dots == 3 ? true : false);
}

int main() {
    string str;
    cin >> str;

    cout << (solution (str) ? "true" : "false") << endl;
}
