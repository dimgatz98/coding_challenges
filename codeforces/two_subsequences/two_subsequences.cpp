#include <bits/stdc++.h>
#include <stdio.h>
#include <stdio.h>
#include <vector> 
#include <string>

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
#define fo(i, n) for(int i = 0 ; i < n ; i++)
#define Fo(i, k , n) for(int i = k ; k < n  ? i < n : i >= n; k < n ? i++ : i--)
#define sz(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define pii pair<int, int>
#define vi vector<int>
#define vll vector<long long>
#define X first
#define Y second

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void pv(vi arr){
    for(auto x : arr)
        cout << x << " ";
    cout << endl;
    return;
}

void solve() {
    string s, a, b;
    cin >> s;
    // cout << s << endl;
    int ind = 0;
    char temp_min = s[0];
    Fo(i, 1, sz(s) ){
        if( s[i] < temp_min){
            temp_min = s[i];
            ind = i;
        } 
    }
    a.push_back(s[ind]);
    fo(i, sz(s) ){
        if(i != ind)
            b.push_back(s[i]);
    }
    cout << a << " ";
    cout << b << endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}