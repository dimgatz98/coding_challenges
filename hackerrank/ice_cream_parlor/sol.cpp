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
typedef unordered_map<int, int> umpii;
typedef set<int> seti;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void print_um(unordered_map<int, pii> um)
{
    for (auto x : um)
    {
        cout << x.first << " " << x.second << " / ";
    }
    cout << endl;
}

void solve(vector<int> cost, int money)
{
    unordered_map<int, pii> m;
    pii tmp;
    int count = 0;
    for (auto x : cost)
    {
        if (m.find(x) == m.end())
        {
            m.insert({x, {count, -1}});
        }
        else if (m.at(x).second == -1)
        {
            m.at(x) = {m.at(x).first,
                       count};
        }
        count++;
    }
    count = 0;
    for (auto x : cost)
    {
        if (m.find(money - x) != m.end())
        {
            pii res = {count, m.at(money - x).first};
            if (m.at(money - x).first == count)
            {
                if (m.at(money - x).second == -1)
                {
                    count++;
                    continue;
                }
                res = {count, m.at(money - x).second};
            }
            cout << ((res.second < res.first) ? to_string(res.second + 1) + " " + to_string(res.first + 1) : to_string(res.first + 1) + " " + to_string(res.second + 1)) << endl;
            return;
        }
        count++;
    }
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++)
        {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        solve(cost, money);
    }

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
