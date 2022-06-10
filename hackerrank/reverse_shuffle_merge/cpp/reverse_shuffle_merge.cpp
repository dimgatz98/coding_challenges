#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

/*
 * Complete the 'reverseShuffleMerge' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

int binSearch(vector<pair<char, int>> v, char s) {
    if (v[0].first == s) {
        return 0;
    }
    int left = 0, right = v.size() - 1, middle = (right - left) / 2;
    while (left < right - 1) {
        middle = (right + left) / 2;
        if(v[middle].first == s) {
            return middle;
        }
        if (v[middle].first > s) {
            right = middle;
        } 
        else {
            left = middle;
        }
    }
    return left;
}

void printMap (unordered_map<char, int> m) {
    for (pair<char, int> p: m) {
            cout << "[" << p.first << ", " << p.second << "]  ";
    }
    cout << endl;
}

void printVector (vector<pair<char, int>> m) {
    for (pair<char, int> p: m) {
            cout << "[" << p.first << ", " << p.second << "]  ";
    }
    cout << endl;
}

bool compare(pair<char, int> p1, pair<char, int> p2) {
    if (p1.first < p2.first) {
        return true;
    }
    return false;
}

string reverseShuffleMerge(string s) {
    reverse(s.begin(), s.end());
    cout << s << endl;
    unordered_map<char, int> m;
    for (int i = 0 ; i < s.size() ; i++) {
        if (m.find(s[i]) == m.end()) {
            m[s[i]] = 1;
            continue;
        }
        m[s[i]]++;
    }

    vector<pair<char, int>> sortedMap;
    // In c++ iterators work like pointers in the sense that when changing an
    // iterator's value the value of the iterated object also changes.
    // Instead when you iterate a data structure using for (auto x: arr) {}
    // if you change the value of x the value of the iterated element stays the same. 
    for (unordered_map<char, int>::iterator it = m.begin() ; it != m.end() ; it++) {
        it->second /= 2;
        sortedMap.push_back({it->first, it->second});
    }
    sort(sortedMap.begin(), sortedMap.end(), compare);
    unordered_map<char, int> added = m;
    // printVector (sortedMap);
    
    string res;
    for (auto c: s) {
        // cout << "m: ";
        // printMap (m);
        // cout << "a: ";
        // printMap (added);

        if (sortedMap[0].first == c) {
            added[c]--;
            if (added[c] == 0) {
                sortedMap.erase(sortedMap.begin());
            }
            res.push_back(c);
        }
        else if (m[c] == 0 && added[c] > 0) { 
            res.push_back(c);
            added[c]--;
            if (added[c] == 0) {
                sortedMap.erase(sortedMap.begin() + binSearch(sortedMap, c));
            }
        }
        if (m[c] != 0)
            m[c]--;
        if(sortedMap.size() == 0) {
            break;
        }
    }

    return res;

    // int tmp = -1, ind, size;
    // vector<int> res;
    // for (pair<char, vector<int>> p : sortedMap) {
    //     if (tmp == -1){
    //         size = p.second.size();
    //         tmp = p.second[(size / 2) - 1];
    //         for (int i = 0 ; i < size / 2 ; i++) {
    //             res.push_back(p.second[i]);
    //         }
    //     }
    //     else {
    //         size = p.second.size();
    //         ind = binSearch(p.second, tmp);
    //         if (ind <= size / 2) {
    //             for (int i = ind ; i < ind + size / 2 ; i++) {
    //                 res.push_back(p.second[i]);
    //             }
    //             tmp = p.second[ind + size / 2 - 1];
    //         }
    //         else {
    //             for (int i = size / 2 ; i < size ; i++) {
    //                 res.push_back(p.second[i]);
    //             }
    //             tmp = p.second[size - 1];
    //         }
    //     }
    // } 
    
    // for (int x: res) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // sort(res.begin(), res.end());
    // string ret;
    // for (int x: res)
    //     ret.push_back(s[x]);
    // return ret;
}

int main()
{
    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    cout << result << "\n";

    return 0;
}
