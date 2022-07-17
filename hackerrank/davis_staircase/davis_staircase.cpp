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
typedef map<int,int> mpii;
typedef set<int> seti;


const int MAX_N = 1e5 + 5;
const ll MOD = 1e10 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

template <typename T>
void print_vect (vector<T> v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
}

int memo[20];

long long stepPerms(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    if (n == 3) {
        return 4;
    }

    if (memo[n - 1] == 0) {
        memo[n - 1] = stepPerms(n - 1) % MOD;
    }

    if (memo[n - 2] == 0) {
        memo[n - 2] = stepPerms(n - 2) % MOD;
    }

    if (memo[n - 3] == 0) {
        memo[n - 3] = stepPerms(n - 3) % MOD;
    }

    return (memo[n - 1] % MOD + memo[n - 2] % MOD + memo[n-3] % MOD) % MOD;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}


int main()
{
    string s_temp;
    getline(cin, s_temp);

    int s = stoi(ltrim(rtrim(s_temp)));

    for (int s_itr = 0; s_itr < s; s_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        memset(memo, 0, sizeof(memo));

        int res = stepPerms(n);

        cout << res << "\n";
    }

    return 0;
}
