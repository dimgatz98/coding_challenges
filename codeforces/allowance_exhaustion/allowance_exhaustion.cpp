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
typedef vector<ll> vll;
typedef map<int,int> mpii;
typedef set<int> seti;


const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve(vector<vector<pair<int, long long>>> g, int s, ll T) {
    ll res = -1;
    list<vll> queue;
    vll curr = {s, 0, 0};
    queue.push_back(curr);

    while(!queue.empty())
    {
        curr = queue.front();
        queue.pop_front();

        for (auto adjacent: g[curr[0]]){
            if (curr[1] > T) {
                break;
            }
            if (curr[0] == s && curr[1] == T && curr[2] > res) {
                res = curr[2];
            }
            queue.push_back(
                {
                    adjacent.first,
                    curr[1] + 1,
                    curr[2] + adjacent.second
                }
            );
        }
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1, N, M, x, y;
    ll T, w;
    for (int t = 1; t <= tc; t++) {
        cin >> N >> M >> T;
        vector<vector<pair<int, ll>>> g(N);
        For(i, M) {
            cin >> x >> y >> w;
            g[x - 1].push_back({y - 1, w});
            g[y - 1].push_back({x - 1, w});
        }
        solve(g, 0, T);
    }
}
