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

uint counter = 0;
vll REGS;

ll bin_to_int (string bin) {
    ll res = 0;
    for (int i = bin.size() - 1 ; i >= 0 ; i--) {
        res += (bin[i] - '0') * (ll) pow(2, ((bin.size() - 1) - i));
    }

    return res;
}

void MOV (ll &R1, ll &R2) {
    R2 = R1;
}

void ADD (ll &R1, ll &R2) {
    R1 = (R1 + R2) % (ll) pow(2, 32);
}

void DEC (ll &R1) {
    if (R1 == 0) {
        R1 = (ll) pow(2, 32) - 1;
        return;
    }
    --R1;
}

void INC (ll &R1) {
    if (R1 == (ll) pow(2, 32) - 1) {
        R1 = 0;
        return;
    }
    ++R1;
}

void INV (ll &R1) {
    string res = "", bits = bitset<32>(R1).to_string();
    for (auto b: bits) {
        if (b == '1') {
            res.push_back('0');
            continue;
        }
        res.push_back('1');
    }
    R1 = stoll(res, 0, 2);
}

void JMP (ll d) {
    counter = d - 1;
}

void JZ (ll d) {
    if (REGS[0] == 0) counter = d - 1;
}

void NOP () {}

vector<string> parse (string command) {
    vector<string> res;
    while (command.find(' ') != string::npos) {
        res.push_back("");
        for (int i = 0 ; i < command.find(' ') ; i++)
        res[res.size() - 1].push_back(command[i]);
        command.erase(0, command.find(' ') + 1);
    }

    while (command.find(',') != string::npos) {
        res.push_back("");
        for (int i = 0 ; i < command.find(',') ; i++)
        res[res.size() - 1].push_back(command[i]);
        command.erase(0, command.find(',') + 1);
    }
    res.push_back(command);

    return res;
}

string solution(vector<string> subroutine) {
    vector<string> v;
    vll ops;
    int mov_type;
    while (counter < subroutine.size()) {
        ops.clear();
        v = parse (subroutine[counter]);
        counter++;
        if (v[0] == "MOV" && v[1][0] == 'R') {
            mov_type = 1;
        } else if (v[0] == "MOV" && v[1][0] != 'R') {
            mov_type = 2;
        }
        for (int i = 1 ; i < v.size() ; i++) {
            if (v[i][0] == 'R') {
                v[i].erase(0, 1);
                ops.push_back(stoll(v[i]));
            } else {
                ops.push_back(stoll(v[i]));
            }
        }

        if ("MOV" == v[0]) {
            if (mov_type == 1) {
                MOV (REGS[ops[0]], REGS[ops[1]]);
            } else {
                MOV (ops[0], REGS[ops[1]]);
            }
        } else if ("ADD" == v[0]) {
            ADD (REGS[ops[0]], REGS[ops[1]]);
        } else if ("DEC" == v[0]) {
            DEC (REGS[ops[0]]);
        } else if ("INC" == v[0]) {
            INC (REGS[ops[0]]);
        } else if ("INV" == v[0]) {
            INV (REGS[ops[0]]);
        } else if ("JMP" == v[0]) {
            JMP (ops[0]);
        } else if ("JZ" == v[0]) {
            JZ (ops[0]);
        }
    }

    return to_string(REGS[42]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1, n;
    cin >> n;
    vector<string> routine;
    string tmp;
    for (int i = 0 ; i < n ; i++) {
        getline(cin, tmp);
        routine.push_back(tmp);
    }

    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        REGS.clear();
        for (int i = 0 ; i < 43 ; i++) {
            REGS.push_back(0);
        }
        cout << solution (routine) << endl;
    }
}
