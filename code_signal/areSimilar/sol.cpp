#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<int> a, vector<int> b) {
    int counter = 0;
    vector<vector<int>> out_of_place(2);

    if (a.size() != b.size()) {
        return false;
    }

    for (int i = 0 ; i < (int) a.size() ; i++) {
        if (a[i] != b[i]) {
            out_of_place[0].push_back(a[i]);
            out_of_place[1].push_back(b[i]);
            counter++;
            if (counter > 2) {
                return false;
            }
        }
    }

    sort(out_of_place[0].begin(), out_of_place[0].end());
    sort(out_of_place[1].begin(), out_of_place[1].end());

    for (int i = 0 ; i < out_of_place[0].size() ; i++) {
        if (out_of_place[0][i] != out_of_place[1][i]) {
            return false;
        }
    }

    return true;
}

int main () {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    for (int i = 0 ; i < n ; i++) {
        cin >> b[i];
    }

    cout << (solution (a, b) ? "true" : "false") << endl;

    return 0;
}
