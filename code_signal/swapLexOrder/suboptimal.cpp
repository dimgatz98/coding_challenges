#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

string swap_indices (string s, int i, int j) {
    char save = s[i];
    s[i] = s[j];
    s[j] = save;
    return s;
}

void print_set(unordered_set<string> s) {
    for (auto str: s) {
        cout << str << " ";
    }
    cout << endl;
}

string solution(string str, vector<vector<int>> pairs) {
    unordered_set<string> s ({str});
    unordered_set<string> seen;
    string tmp;
    string res = str;
    vector<string> v;

    while (! s.empty()) {
        // cout << "s: \n";
        // print_set(s);
        // cout << "seen: \n";
        // print_set(seen);

        v  = {s.begin(), s.end()};
        for (auto w: v) {
            if (res < w) {
                res = w;
            }

            for (auto p: pairs) {
                tmp = swap_indices(w, p[0] - 1, p[1] - 1);
                if (seen.find(tmp) == seen.end()) {
                    s.insert(tmp);
                    if (res < w) {
                        res = w;
                    }
                }
            }
            seen.insert(w);
            s.erase(w);
        }
    }

    return res;
}

int main () {
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<vector<int>> pairs;

    for (int i = 0 ; i < n ; i++) {
        int x, y;
        cin >> x >> y;
        pairs.push_back({x, y});
    }

    // str: "abcdefgh"
    // pairs:
    // [[1,4],
    // [7,8]]
    cout << solution (str, pairs) << endl;;
}
