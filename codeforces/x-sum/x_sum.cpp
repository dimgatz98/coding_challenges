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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
int a[200][200];

vi compute_sum (bool main, int n, int m) {
    int sum;
    vi sums;
    if (main) {
        for (int start = 0 ; start < n ; start++) {
            sum = 0;
            for (int i = start, j = 0 ; i < n ; i++) {
                sum += a[i][j++];
                if (j >= m) {
                    break;
                }
            }
            sums.push_back(sum);
        }

        for (int start = 1 ; start < m ; start++) {
            sum = 0;
            for (int j = start, i = 0 ; j < m ; j++) {
                sum += a[i++][j];
                if (i >= n) {
                    break;
                }
            }
            sums.push_back(sum);
        }
    } else {
        for (int start = n - 1 ; start >= 0 ; start--) {
            sum = 0;
            for (int i = start, j = 0 ; i >= 0 ; i--) {
                sum += a[i][j++];
                if (j >= m) {
                    break;
                }
            }
            sums.push_back(sum);
        }

        for (int start = 1 ; start < m ; start++) {
            sum = 0;
            for (int j = start, i = n - 1 ; j < m ; j++) {
                sum += a[i--][j];
                if (i < 0) {
                    break;
                }
            }
            sums.push_back(sum);
        }
    }
    return sums;
}

void print_vect(vi x) {
    Foreach (it, x) {
        cout << *it << " ";
    }
    cout << endl;
}

pii remove_common (int n, int m, int i, int j) {
    unordered_set<string> s;
    pii first_pair, second_pair;
    if (i < n) {
        first_pair = {i, 0};
    } else {
        first_pair = {i, j - n + 1};
    }

    if (j < n) {
        second_pair = {n - 1 - j, 0};
    } else {
        second_pair = {n - 1, j - n + 1};
    }

    while (first_pair.first < n && first_pair.second < m) {
        s.insert(to_string(first_pair.first) + to_string(first_pair.second));
        first_pair.first++; first_pair.second++;
    }

    while (second_pair.first >= 0 && second_pair.second < m) {
        if (s.find(to_string(second_pair.first) + to_string(second_pair.second)) != s.end()) {
            return second_pair;
        }
        second_pair.first--; second_pair.second++;
    }
    return {-1, -1};
}

void solve(int n, int m) {
    vi main_sums = compute_sum (true, n, m);
    // print_vect(main_sums);
    vi rest_sums = compute_sum (false, n, m);
    // print_vect(rest_sums);
    int max = 0, remove;
    pii remove_ind;
    For (i, n) {
        RFOR (j, n-1, i, 1) {
            remove_ind = remove_common(n, m, i, n - 1 - j);
            if (remove_ind.first == -1) {
                continue;
            }
            remove = a[remove_ind.first][remove_ind.second];
            if (max < main_sums[i] + rest_sums[n - 1 - j] - remove) {
                max = main_sums[i] + rest_sums[n - 1 - j] - remove;
                // cout << "i: " << i << ", j: " <<  n - 1 - j << endl;
                // cout << "max: " << max << endl;
            }
        }
        For (j, m - i - 1) {
            remove_ind = remove_common(n, m, i, n + j);
            if (remove_ind.first == -1) {
                continue;
            }
            remove = a[remove_ind.first][remove_ind.second];
            if (max < main_sums[i] + rest_sums[n + j]) {
                max = main_sums[i] + rest_sums[n + j] - remove;
                // cout << "i: " << i << ", j: " <<  n + j << endl;
                // cout << "max: " << max << endl;
            }
        }
    }

    For (j, m - 1) {
        RFOR (i, n-1, j, 1) {
            remove_ind = remove_common(n, m, n + j, n - 1 - i);
            if (remove_ind.first == -1) {
                continue;
            }
            remove = a[remove_ind.first][remove_ind.second];
            if (max < main_sums[n + j] + rest_sums[n - 1 - i]) {
                max = main_sums[n + j] + rest_sums[n - 1 - i] - remove;
                // cout << "i: " << n + j << ", j: " <<  n - 1 - i << endl;
                // cout << "max: " << max << endl;
            }
        }
        For (i, m - 1 - j) {
            remove_ind = remove_common(n, m, n + j, n + i);
            remove = 0;
            if (remove_ind.first == -1) {
                continue;
            }
            remove = a[remove_ind.first][remove_ind.second];
            if (max < main_sums[n + j] + rest_sums[n + i]) {
                max = main_sums[n + j] + rest_sums[n + i] - remove;
                // cout << "i: " << n + j << ", j: " <<  n + i << endl;
                // cout << "max: " << max << endl;
            }
        }
    }

    cout << max << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1, n, m;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n >> m;
        for (int i = 0 ; i < n ; i++) {
            for (int j = 0 ; j < m ; j++) {
                cin >> a[i][j];
            }
        }
        solve(n, m);
    }
}
