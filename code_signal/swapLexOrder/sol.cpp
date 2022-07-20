#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(unordered_map<int, unordered_set<int>> map, int u, unordered_set<int> visited, unordered_set<int> current) {
    for (int v: map[u]) {
        if (visited.find(v) == visited.end()) {
            visited.insert(v);
            current.insert(v);
            dfs(map, v, visited, current);
        }
    }
}

string solution(string str, vector<vector<int>> pairs) {
    unordered_map<int, unordered_set<int>> map;

    for (vector<int> edge: pairs) {
        int u = edge[0];
        int v = edge[1];

        if (map.find(u) == map.end()) {
            map.insert({u, {}});
        }
        if (map.find(v) == map.end()) {
            map.insert({v, {}});
        }

        map[u].insert(v);
        map[v].insert(u);
    }

    // DFS and collect all connected components, order ascending
    vector<unordered_set<int>> ccs;
    unordered_set<int> visited;

    for (auto iter = map.begin() ; iter != map.end() ; iter++) {
        if (visited.find(iter->first) == visited.end()) {
            visited.insert(iter->first);
            unordered_set<int> current;
            current.insert(iter->first);
            dfs(map, iter->first, visited, current);
            ccs.push_back(current);
        }
    }

    string ans = str;
    // Collect chars at connected component, sort des and populate output
    for (auto set : ccs) {
        string ordered;
        for (auto iter = set.begin() ; iter != set.end() ; iter++) {
            ordered.push_back(str[*iter - 1]);
        }
        sort(ordered.begin(), ordered.end(), greater<char>());
        int i = 0;
        for (auto iter = set.begin() ; iter != set.end() ; iter++) {
            ans[*iter - 1] = ordered[i++];
        }
    }
    return ans;
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
    cout << solution(str, pairs) << endl;;
}
