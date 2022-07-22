#include <vector>
#include <iostream>

using namespace std;

int max_depth = 0;

void DFS (int curr, vector<vector<int>> g, int depth, vector<bool> visited) {
    if (visited[curr]) {
        return;
    }

    if (depth > max_depth) {
        max_depth = depth;
    }

    visited[curr] = true;

    for (auto adj: g[curr]) {
        DFS (adj, g, depth + 1, visited);
    }
}

int difference (string a, string b) {
    int diff = 0;
    for (int i = 0 ; i < (int) a.size() ; i++) {
        if (a[i] != b[i]) {
            diff++;
        }
    }

    return diff;
}

bool solution(vector<string> inputArray) {
    int sz = (int) inputArray.size();
    vector<vector<int>> g(sz);

    for (int i = 0 ; i < sz ; i++) {
        for (int j = 0 ; j < sz ; j++) {
            if (difference(inputArray[i], inputArray[j]) == 1) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for (int i = 0 ; i < sz ; i++) {
        vector<bool> visited(sz);
        DFS (i, g, 0, visited);
    }

    return max_depth == sz - 1;
}

int main () {
    int n;
    cin >> n;
    vector<string> v(n);

    for (int i =0 ; i < n ; i++) {
        cin >> v[i];
    }

    cout << (solution (v) ? "true" : "false") << endl;

    return 0;
}
