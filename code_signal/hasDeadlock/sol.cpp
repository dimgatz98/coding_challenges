#include <vector>
#include <iostream>

using namespace std;

vector<int> q;

bool DFS (int curr, vector<vector<int>> connections, vector<int> visited) {
    bool ret = false;
    if (visited[curr] == 1) {
        return true;
    } else {
        visited[curr] = 1;
        q[curr] = 1;
    }

    for (auto j: connections[curr]) {
        ret = ret || DFS (j, connections, visited);
    }

    return ret;
}

bool solution(vector<vector<int>> connections) {
    bool ret = false;

    for (int i = 0 ; i < (int) connections.size() ; i++) {
        q.push_back(0);
    }

    for (int i = 0 ; i < (int) q.size() ; i++) {
        if (q[i] == 1) {
            continue;
        }
        ret = ret || DFS (i, connections, vector<int> ((int) connections.size()));
    }

    return ret;
}


int main () {
    int n, k, x, y;
    cin >> n;
    cin >> k;
    vector<vector<int>> connections (n);
    for (int i = 0 ; i < k ; i++) {
        cin >> x >> y;
        connections[x].push_back(y);
    }

    cout << (solution (connections) ? "True" : "False") << endl;;

}