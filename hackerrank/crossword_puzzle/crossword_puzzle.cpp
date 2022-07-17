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

template <typename T>
void print_vect (vector<T> v) {
    Foreach (it, v) {
        cout << *it << " ";
    }
    cout << endl;
}

void print_map (unordered_map<int, vector<string>> m) {
    for (auto it: m) {
        cout << it.first << ": ";
        print_vect(it.second);
    }
}

vector<string> split_string (string str, char delim) {
    vector<string> res;
    stringstream s(str);
    string tmp;
    while (getline(s, tmp, delim) ) {
        res.push_back(tmp);
    }
    return res;
}

unordered_map<int, vector<string>> create_map (vector<string> v) {
    unordered_map<int, vector<string>> m;
    for (auto it = v.begin() ; it != v.end() ; it++) {
        auto pos = m.find((int((*it).length())));
        if (pos == m.end()) {
            m.insert({int((*it).length()), {*it}});
        } else {
            pos->second.push_back(*it);
        }
    }

    return m;
}

vector<string> add_to_res(vector<string> crossword, string s1, string s2, int start1, int start2) {
    vector<string> res;
    int p = 0;
    if (start1 > 0) {
        if (crossword[start1 - 1][start2] != '+' && crossword[start1][start2] == '-') {
            if (crossword[start1 - 1][start2] != s1[p++]) {
                return {""};
            }
        }
    }
    for (int i = start1 ; i < 10 ; i++) {
        if (crossword[i][start2] = '-' && s1 != "") {
            res[i][start2] = s1[p++];
            continue;
        }
        if (crossword[i][start2] != '-' && crossword[i][start2] != '+') {
            if (crossword[i][start2] != s1[p++]) return {""};
            else {
                res[0][i] = crossword[i][start2];
                continue;
            }
        }
        res[0][i] = '+';
    }

    p = 0;
    if (start2 > 0) {
        if (crossword[start1][start2 - 1] != '+' && crossword[start1][start2] == '-') {
            if (crossword[start1][start2 - 1] != s2[p++]) {
                return {""};
            }
        }
    }
    for (int i = start2 ; i < 10 ; i++) {
        if (crossword[start1][i] == '-' && s2 != "") {
            res[start1][i] = s2[p++];
            continue;
        }
        if (crossword[start1][i] != '+' && crossword[start1][i] != '-') {
            if (crossword[start1][i] != s2[p++]) return {""};
            else {
                res[i][0] = crossword[start1][i];
                continue;
            }
        }
        res[i][0] = '+';
    }

    return res;
}

unordered_map<int, vector<string>> delete_words (unordered_map<int, vector<string>> m, string s1, string s2) {
    for (auto s: {s1, s2}) {
        if (s != "") {
            auto pos = m.find(int(s.size()));
            for (auto it = pos->second.begin() ; it != pos->second.end() ; it++) {
                if (*it == s) {
                    pos->second.erase(it);
                }
            }
        }
    }
    return m;
}

void crosswordPuzzle (vector<string> crossword, unordered_map<int, vector<string>> words, vector<string> res, int start1, int start2) {
    int counter1 = 0, counter2 = 0;

    if (start1 == 10 && start2 == 10) {
        print_vect(res);
        return;
    }

    if (start1 > 0) {
        if (crossword[start1 - 1][start2] != '+' && crossword[start1][start2] != '+') {
            counter1++;
        }
    }
    for (int i = start1 ; i < 10 ; i++) {
        if (crossword[i][start2] != '+') counter1++;
    }
    if (start2 > 0) {
        if (crossword[start1][start2 - 1] != '+' && crossword[start1][start2] != '+') {
            counter2++;
        }
    }
    for (int i = start2 ; i < 10 ; i++) {
        if (crossword[start1][i] != '+') counter2++;
    }

    unordered_map<int, vector<string>>::iterator pos1, pos2;
    unordered_map<int, vector<string>> empty_map{{1, {""}}};
    if (counter1 > 1) {
        pos1 = words.find(counter1);
    } else {
        pos1 = empty_map.begin();
    }
    if (counter2 > 1) {
        pos2 = words.find(counter2);
    } else {
        pos2 = empty_map.begin();
    }
    if (pos1 == words.end() || pos2 == words.end()) {
        return;
    } else {
        for (auto s1: pos1->second) {
            for (auto s2: pos2->second) {
                auto tmp1 = delete_words (words, s1, s2);
                auto tmp2 = add_to_res(crossword, s1, s2, start1, start2);
                if (tmp2[0] == "") {
                    return;
                }
                if (start1 < 10) crosswordPuzzle (crossword, tmp1, tmp2, start1 + 1, start2);
                if (start2 < 10) crosswordPuzzle (crossword, tmp1, tmp2, start1, start2 + 1);
            }
        }
    }
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
    vector<string> crossword(10);

    for (int i = 0; i < 10; i++) {
        string crossword_item;
        getline(cin, crossword_item);

        crossword[i] = crossword_item;
    }

    string words;
    getline(cin, words);

    vector<string> w = split_string(words, ';');
    unordered_map<int, vector<string>> m = create_map(w);
    crosswordPuzzle(crossword, m, crossword, 0, 0);

    cout << "\n";

    return 0;
}
