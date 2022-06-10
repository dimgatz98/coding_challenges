#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    string s;
    // vector<int> tmp(1);
    cin >> s;
    // cout << s << endl;
    unordered_map<char, vector<int>> m;
    for (int i = 0 ; i < s.size() ; i++) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = vector<int>(1, i);
            continue;
        }
        m[s[i]].push_back(i);
    }
    for (pair<char, vector<int>> p: m) {
        for (int x: p.second)
            cout << "[" << p.first << ", " << x << "]" << "  ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
