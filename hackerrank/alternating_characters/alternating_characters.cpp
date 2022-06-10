#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'alternatingCharacters' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

void printStr (string s) {
    for (char c: s) {
        cout << c << " ";
    }
    cout << endl;
}

int alternatingCharacters(string s) {
    string res;

    for (int i = 0 ; i < int(s.size()) ; i++) {
        if (i == int (s.size() - 1)) {
            if (s[i] != res.back()) { 
                res.push_back(s[i]);
            }
            continue;
        }

        if (s[i] != s[i + 1]) { 
            res.push_back(s[i]);
        }
    }

    // printStr (res);

    return int(s.size() - res.size());
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = alternatingCharacters(s);

        cout << result << "\n";
    }

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
