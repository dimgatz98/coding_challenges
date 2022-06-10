#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

bool is_uppercase(char a) {
    if (a >= 65 && a <= 90) return true;
    return false;
}

int char_to_int(char a) {
    if (is_uppercase(a)) {
        return a - 'A';
    }
    return a - 'a';
}

void init_pair_array(pair<int,int> ar[]) {
    for (int i = 0 ; i < 26 ; i++) {
        ar[i] = {-1, 0};
    }
}

string abbreviation(string a, string b) {
    int pointer1 = 0, pointer2 = 0;
    pair<int, int> save, memo[26];

    init_pair_array(memo);
    // for (int i = 0 ; i < 26 ; i++) {
    //     cout << memo[i].first << " " << memo[i].second << " ";
    // }
    // cout << endl;

    while(pointer1 < a.size()) {
        if (pointer2 >= b.size()) {
            if (is_uppercase(a[pointer1])) {
                if (memo[char_to_int(a[pointer1])].first == -1) {
                    cout << "Hello1";
                    return "NO";
                }
                pointer2 = memo[char_to_int(a[pointer1])].first + 1;

                init_pair_array(memo);
            }
            pointer1++;
            continue;
        }

        if (char_to_int(a[pointer1]) == char_to_int(b[pointer2])) {
            if (memo[char_to_int(a[pointer1])].first == pointer2 - 1) {
                memo[char_to_int(a[pointer1])].second++;
            }
            memo[char_to_int(a[pointer1])].first = pointer2;
            pointer2++;
        } else {

            if (is_uppercase(a[pointer1])) {
                if (memo[char_to_int(a[pointer1])].first == -1) {
                    for (int i = 0 ; i < 26 ; i++) {
                        cout << " " << char('a' + i) << " " << memo[i].first;
                    }
                    cout << endl;
                    cout << endl;
                    for (int j = 0 ; j < 10 ; j++) {
                        cout << a[pointer1 - 5 + j];
                    }
                    cout << endl;
                    cout << endl;
                    for (int j = 0 ; j < 10 ; j++) {
                        cout << b[pointer2 - 5 + j];
                    }
                    cout << endl;
                    cout << pointer1 << " " <<  a[pointer1] << " "
                    << pointer2 << " " << b[pointer2] << " Hello2 ";

                    return "NO";
                }
                pointer2 = memo[char_to_int(a[pointer1])].first + 1;
                if (memo[char_to_int(a[pointer1])].second > 0) {
                    save = memo[char_to_int(a[pointer1])];
                }
                memo[char_to_int(a[pointer1])].second--;
                init_pair_array(memo);
                memo[char_to_int(a[pointer1])] = save;
                pointer1++;
                continue;
            }
        }

        if (is_uppercase(a[pointer1])) {
            init_pair_array(memo);
        }

        if (pointer1 == 373) {
            for (int i = 0 ; i < 26 ; i++) {
                cout << " " << char('a' + i) << " " << memo[i].first;
            }
            cout << endl;
            cout << endl;
            for (int j = 0 ; j < 10 ; j++) {
                cout << a[pointer1 - 5 + j];
            }
            cout << endl;
            cout << endl;
            for (int j = 0 ; j < 10 ; j++) {
                cout << b[pointer2 - 5 + j];
            }
            cout << endl;
            cout << pointer1 << " " <<  a[pointer1] << " "
            << pointer2 << " " << b[pointer2];
        }

        pointer1++;
    }
    return ((pointer2 == b.size()) ? "YES" : "NO");
}

int main()
{
    vector<string> res;

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        res.push_back(result);
    }

    for (auto s: res) {
        cout << s << "\n";
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
