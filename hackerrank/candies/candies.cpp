#include <bits/stdc++.h>

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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


template <typename T>
long sum(vector<T> ar) {
    T sum = 0;
    for (auto x: ar) {
        sum += x;
    }
    return sum;
}

template <typename T>
void print_vect(vector<T> ar) {
    for (auto x: ar) {
        cout << " " << x;
    }
    cout << endl;
}


long solve(vector<long> arr) {
    vector<long> l_arr(int(arr.size()));
    vector<long> r_arr(int(arr.size()));
    l_arr[0] = 1;
    for (int i = 1 ; i < int(l_arr.size()) ; i++) {
        if (arr[i] > arr[i - 1]) {
            l_arr[i] = l_arr[i - 1] + 1;
            continue;
        }
        l_arr[i] = 1;
    }

    r_arr[int(arr.size()) - 1] = l_arr[int(arr.size()) - 1];
    for (int i = int(r_arr.size()) - 2 ; i >= 0 ; i--) {
        if (arr[i] > arr[i + 1]) {
            r_arr[i] = max(r_arr[i + 1] + 1, l_arr[i]);
            continue;
        }
        r_arr[i] = l_arr[i];
    }

    // print_vect(l_arr);
    // print_vect(r_arr);

    return sum(r_arr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1, n;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        vector<long> arr(n);
        // cout << "Case #" << t << ": ";
        for (int i = 0 ; i < n ; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
}
