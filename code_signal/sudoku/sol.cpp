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


bool solution(vector<vector<int>> grid) {
    unordered_set<int> s;
    for (auto v: grid) {
        s.clear();
        for (auto i: v) {
            if (i < 1 || i > 9) {
                return false;
            }
            if (s.find(i) != s.end()) {
                return false;
            }
            s.insert(i);
        }
    }

    for (int i = 0 ; i < 9 ; i++) {
        s.clear();
        for (int j = 0 ; j < 9 ; j++) {
            if (grid[j][i] < 1 || grid[j][i] > 9) {
                return false;
            }
            if (s.find(grid[j][i]) != s.end()) {
                return false;
            }
            s.insert(grid[j][i]);
        }
    }

    for (int i = 0 ; i < 9 ; i += 3) {
        for (int j = 0 ; j < 9 ; j += 3) {
            s.clear();
            for (int k = 0 ; k < 3 ; k++) {
                for (int l = 0 ; l < 3 ; l++) {
                    if (grid[i + k][j + l] < 1 || grid[i][j] > 9) {
                            return false;
                        }
                        if (s.find(grid[i + k][j + l]) != s.end()) {
                            return false;
                        }
                        s.insert(grid[i + k][j + l]);
                }
            }
        }
    }

    return true;
}


void print_vect_vect (vector<vector<int>> vec) {
    for (auto v: vec) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1, tmp;
    vector<vector<int>> grid;
    for (int i = 0 ; i < 9 ; i++) {
        grid.push_back({});
        for (int j = 0 ; j < 9 ; j++) {
            cin >> tmp;
            grid[i].push_back(tmp);
        }
    }

    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        cout << (solution (grid) ? "true" : "false") << endl;
    }
}
