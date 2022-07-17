#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>

using namespace std;

bool solution(vector<int> nums, int k) {
    unordered_map <int , vector<int> > m;
    for (int i = 0 ; i < (int) nums.size() ; i++) {
        if (m.find(nums[i]) == m.end()) {
            m.insert ({nums[i], {i}});
            continue;
        }
        m[nums[i]].push_back(i);
    }

    int prev;
    for (auto &p: m) {
        sort(p.second.begin() , p.second.end());
        for (int i = 0 ; i < (int) p.second.size() ; i++) {
            if (i == 0) {
                prev = p.second[i];
                continue;
            }
            if (p.second[i] - prev <= k){
                return true;
            }
            prev = p.second[i];
        }
    }

    return false;
}

int main () {
    int n, k, tmp;
    vector<int> nums;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    cin >> k;

    solution (nums, k);
    return 0;
}