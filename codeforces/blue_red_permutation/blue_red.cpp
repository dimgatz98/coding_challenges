#include <bits/stdc++.h>
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
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;


template<typename T>
void print_vect(T x) {
    for (auto a: x) {
        cout << a << endl;
    }
}

string solve(vector<int> nums, string colors) {
    vector<int> low, high;
    int low_count = 0, high_count = 0;

    for(int i = 0 ; i < int(nums.size()) ; i++) {
        if (colors[i] == 'B') {
            low.push_back(nums[i]);
            low_count++;
        } else {
            high.push_back(nums[i]);
            high_count++;
        }
    }

    sort(low.begin(), low.end());
    sort(high.begin(), high.end());
    for (int i = 1 ; i < low_count + 1 ; i++) {
        if (low[i - 1] < i) {
            return "NO";
        }
    }

    for (int i = nums.size() - high_count ; i < nums.size() ; i++) {
        if (high[i - nums.size() + high_count] > i + 1) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int temp, n, tc = 1;
    vector<int> nums;
    string colors;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cin >> n;
        for (int i = 0 ; i < n ; i++) {
            cin >> temp;
            nums.push_back(temp);
        }
        cin >> colors;
        cout << solve(nums, colors) << endl;
        nums.clear();
        colors.clear();
    }
}
