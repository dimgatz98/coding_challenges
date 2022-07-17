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


// Singly-linked lists are already defined with this interface:
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};

void printList (ListNode<int> * l) {
    ListNode<int> * tmp = l;
    while (tmp != nullptr) {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

ListNode<int> * addElement(ListNode<int> * l, int n) {
    if (l == nullptr) {
        return new ListNode <int> (n);
    }

    ListNode<int> *curr = l;
    while (curr->next != nullptr) {
        curr = curr->next;
    }

    curr->next = new ListNode<int> (n);
    return l;
}

ListNode<int> * solution(ListNode<int> * l, int k) {
    int k_cp, sz = 0;
    ListNode<int> * save_prev, * tmp = l, * start, * end, * save, * prev = nullptr, * curr = l;
    while (tmp != nullptr) {
        sz++;
        tmp = tmp->next;
    }

    while (sz >= k) {
        sz -= k;
        k_cp = k;
        tmp = curr;
        while (k_cp > 1) {
            // cout << "tmp->value: " << tmp->value << endl;
            k_cp--;
            tmp = tmp->next;
        }
        end = tmp;
        k_cp = k;
        if (prev != nullptr) {
            prev->next = end;
        } else {
            l = end;
        }
        save_prev = curr;
        while (k_cp > 0) {

            // cout << "curr->value: " << curr->value << endl;

            save = curr->next;
            if (k_cp != k) curr->next = prev;
            else curr->next = end->next;
            prev = curr;
            curr = save;
            k_cp--;
        }
        prev = save_prev;
    }

    return l;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1, tmp, n, k;
    ListNode<int> * l = nullptr;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // l: [1, 2, 3, 4, 5]
        // k: 2
        cin >> n;
        while (n > 0) {
            n--;
            cin >> tmp;
            l = addElement(l, tmp);
        }
        cin >> k;

        ListNode<int> * res = solution(l, k);
        printList(res);
    }
}
