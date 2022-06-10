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

string abbreviation(string a, string b) {
    vector<vector<pair<int, int> > > memo;
    vector<int> bound(b.size() );
    int found;

    for (int i = 0 ; i < b.size() ; i++) {
        memo.push_back(vector<pair<int, int> >() );
        found = 0;
        for (int j = 0 ; j < a.size() ; j++) {
            if (tolower(a[j]) == tolower(b[i]) ) {
                found++;
                
                if (memo[i][j - 1].second == 1) {
                    memo[i].push_back(memo[i][j - 1]);
                    continue;
                }
                
                if (a[j] != b[i]) {
                    memo[i].push_back({j, 0});
                }
                else {
                    if (i > 0 && bound[j] == 1) {
                        found--;
                        memo[i].push_back({-1, 0});
                        continue;
                    }
                    else if (memo[i - 1][j].first == -1) {
                        return "NO";
                    }
                    else {
                        memo[i].push_back({j, 1});
                        bound[j] = 1;
                    }
                }             
            }
            else {
                if (found > 0) {
                    memo[i].push_back(memo[i][j - 1]);
                }
                else {
                    memo[i].push_back({-1, 0});
                }
            }
        }
    }

    return "YES";
}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

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
