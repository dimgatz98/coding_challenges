#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> strings, vector<string> patterns) {
    unordered_map<string, string> m;
    unordered_set<string> seen;
    for (int i = 0 ; i < (int) strings.size() ; i++) {
        if (m.find(strings[i]) == m.end()) {
            if (seen.find(patterns[i]) != seen.end()) {
                return false;
            }
            seen.insert(patterns[i]);
            m.insert({strings[i], patterns[i]});
            continue;
        }
        if (m[strings[i]] != patterns[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    return 0;
}
