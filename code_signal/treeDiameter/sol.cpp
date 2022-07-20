#include <vector>
#include <iostream>

using namespace std;

int depth = 0;
int res;

vector<bool> visited;

void DFS (int curr, int tmp_depth, vector<vector<int>> &tree) {
    visited[curr] = true;

    if (tmp_depth >= depth) {
        res = curr;
        depth = tmp_depth;
    }

    for (auto adj: tree[curr]) {
        if (visited[adj] == true) {
            continue;
        }
        DFS (adj, tmp_depth + 1, tree);
    }
}

int solution(int n, vector<vector<int>> tree) {
    vector<vector<int>> paths(n + 1);
    for (int i = 0 ; i < n + 1 ; i++) {
        visited.push_back(false);
    }

    for (auto v: tree) {
        paths[v[0]].push_back(v[1]);
        paths[v[1]].push_back(v[0]);
    }

    DFS (0, 0, paths);

    for (int i = 0 ; i < n + 1 ; i++) {
        visited[i] = false;
    }
    depth = 0;
    DFS (res, 0, paths);

    return depth;
}

int main () {
    int n, k, x, y;
    cin >> n;
    cin >> k;
    vector<vector<int>> tree;

    for (int i = 0 ; i < k ; i++) {
        cin >> x >> y;
        tree.push_back({x, y});
    }

    cout << solution (n, tree) << endl;
}
