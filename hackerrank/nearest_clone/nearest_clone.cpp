#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <queue>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define Foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define For(i, j) FOR(i, 0, j, 1)
#define Rfor(i, j) RFOR(i, j, 0, 1)


typedef pair<int,int> pii;
typedef vector<int> vi;
typedef map<int,int> mpii;
typedef set<int> seti;


const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
int min_res = -1;

void printVect(vi ar) {
    Foreach(it, ar) {
        cout << *it << " ";
    }
    cout << endl;
}

int getRoot(vector<vector<int>> adjLists) {
    for (int i = 0 ; i < int(adjLists.size()) ; i++) {
        if (int(adjLists[i].size()) == 1) {
            return i;
        }
    }
    return -1;
}

void DFS(int vertex, bool *visited, int graph_nodes, vector<vector<int>> adjLists, vector<long> ids, int val, int counting, int res) {
    visited[vertex] = true;
    vector<int> adjList = adjLists[vertex];

    // cout << "vertex: " << vertex << " id: " << ids[vertex] << endl;

    if (counting == 1) {
        res++;
    }
    if (ids[vertex] == val) {
        if (counting == 0) {
            counting = 1;
        } else {
            if (min_res == -1) {
                min_res = res;
            } else if (res < min_res) {
                min_res = res;
            }
        }
    }

    for (int i = 0 ; i < int(adjList.size()) ; i++) {
        if (!visited[adjList[i]])
            DFS(adjList[i], visited, graph_nodes, adjLists, ids, val, counting, res);
    }
}

vector<vector<int>> makeAdjLists(int graph_nodes, vector<int> graph_from, vector<int> graph_to) {
    vector<vector<int>> res(graph_nodes);
    for (int i = 0 ; i < int(graph_from.size()) ; i++) {
        res[graph_from[i] - 1].push_back(graph_to[i] - 1);
        res[graph_to[i] - 1].push_back(graph_from[i] - 1);
    }
    return res;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    vector<vector<int>> adjLists = makeAdjLists(graph_nodes, graph_from, graph_to);
    int root = getRoot(adjLists);
    // cout << "adj_lists: " << endl;
    // for (auto x: adjLists) {
    //     printVect(x);
    // }

    bool *visited = new bool[graph_nodes];
    DFS(root, visited, graph_nodes, adjLists, ids, val, 0, 0);
    return min_res;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

int main()
{
    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    cout << ans << "\n";

    return 0;
}
