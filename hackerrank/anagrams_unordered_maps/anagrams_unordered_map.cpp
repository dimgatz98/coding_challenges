#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
 * Complete the 'makeAnagram' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

void printMap (unordered_map<char, int> m) {
    for (pair<char,int> p: m) {
        cout << "{" << p.first << ", " << p.second << "}";
    }
    cout << endl;
} 

int makeAnagram(string a, string b) {
    unordered_map <char, int> m;
    int res = 0;

    for (char c: a)
    {
        if (m.find(c) == m.end()) {
            m.insert({c, 1});
            continue;
        }
        m.at(c)++;
    }

    // printMap (m);

    for (char c: b)
    {
        if (m.find(c) == m.end()) {
            res++;
        }
        else { 
            if (m.at(c) > 0)
                m.at(c)--;
            else
                res++;
        }
    }

    for (pair<char,int> p: m) {
        if (p.second == 0) continue;
        res += p.second;
    }

    return res;
}

int main()
{
    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    cout << res << "\n";

    return 0;
}
