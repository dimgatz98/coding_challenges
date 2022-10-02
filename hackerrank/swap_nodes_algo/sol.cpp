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

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
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
#define reset(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define Foreach(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define For(i, j) FOR(i, 0, j, 1)
#define Rfor(i, j) RFOR(i, j, 0, 1)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mpii;
typedef set<int> seti;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

vector<int> tmp_res;
vector<vector<int>> new_tree;

void inOrder(int node, vector<vector<int>> &tree)
{
    if (tree[node][0] != -1)
    {
        inOrder(tree[node][0] - 1, tree);
    }
    tmp_res.push_back(node + 1);
    if (tree[node][1] != -1)
    {
        inOrder(tree[node][1] - 1, tree);
    }
}

void inOrderSwap(int node, int depth, vector<vector<int>> &tree, vector<int> &visited, int query)
{
    if (tree[node][0] != -1 && visited[tree[node][0] - 1] == 0)
    {
        inOrderSwap(tree[node][0] - 1, depth + 1, tree, visited, query);
    }
    if ((depth + 1) % query == 0)
    {
        cout << "node: " << node << " depth: " << depth << " query: " << query << endl;
        cout << "children: " << tree[node] << endl;
        new_tree[node][0] = tree[node][1];
        new_tree[node][1] = tree[node][0];
    }
    visited[node] = 1;
    if (tree[node][1] != -1 && visited[tree[node][1] - 1] == 0)
    {
        inOrderSwap(tree[node][1] - 1, depth + 1, tree, visited, query);
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
    vector<vector<int>> res;
    vector<int> visited;
    for (auto q : queries)
    {
        visited.clear();
        For(i, sz(indexes))
        {
            visited.push_back(0);
        }
        new_tree = indexes;
        inOrderSwap(0, 0, indexes, visited, q);
        indexes = new_tree;
        tmp_res.clear();
        inOrder(0, indexes);
        res.push_back(tmp_res);
    }
    return res;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++)
    {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++)
        {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++)
    {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];

            if (j != result[i].size() - 1)
            {
                cout << " ";
            }
        }

        if (i != result.size() - 1)
        {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
