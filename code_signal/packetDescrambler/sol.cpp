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

string solution(vector<int> seq, vector<char> fragmentData, int n) {
    vector<unordered_map<char, int>> freq((int) seq.size());
    vector<pair<char, int>> res;
    unordered_set<int> added;

    unordered_set<int> chars;
    int size = 0;
    for (auto i: seq) {
        if (chars.find(i) != chars.end()) {
            continue;
        }
        chars.insert(i);
        size++;
    }
    cout << size << endl;

    for (int i = 0 ; i < seq.size() ; i++) {
        if (freq[seq[i]].find(fragmentData[i]) != freq[seq[i]].end()) {
            freq[seq[i]][fragmentData[i]]++;
            if (freq[seq[i]][fragmentData[i]] >= n / 2 + 1) {
                if (added.find(seq[i]) != added.end()) {
                    continue;
                }
               added.insert(seq[i]);
               if (fragmentData[i] == '#' && seq[i] != size - 1) {
                return "";
               }
               res.push_back({seq[i], fragmentData[i]});
            }
        } else {
            freq[seq[i]].insert({fragmentData[i], 1});
        }
    }

    sort(res.begin(), res.end());

    string ret = "";
    for (auto p: res) {
        ret.push_back(p.second);
    }
    return ((ret.size() < size || ret[ret.size() - 1] != '#') ? "" : ret);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    int n, k;
    cin >> k;
    vector<int> seq(k);
    vector<char> data(k);
    cin >> n;
    for (int i = 0 ; i < k ; i++) {
        cin >> seq[i];
    }
    for (int i = 0 ; i < k ; i++) {
        cin >> data[i];
    }
    // cout << seq << data << endl;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        cout << solution (seq, data, n) << endl;
    }
}