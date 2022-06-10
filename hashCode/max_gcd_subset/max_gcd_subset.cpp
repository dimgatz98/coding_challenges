/*
Randomized algorithm to compute the greater common divisor of at least the half of the numbers within array nums
*/
#include <utility>
#include <vector>
#include <stdio.h>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#define MAXN 10005
#define pii pair<int,int>
#define X first
#define Y second

using namespace std;
  
vector<int> find_divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x / 2 ; i++){
        if(x % i == 0)
            res.push_back(i);
    }
    return res;
}

bool is_valid(int divisor, int n, vector<int> &v){
    int count = 0;
    for (auto i: v){
        if(i % divisor == 0)
            count++;
    }
    if(count >= n / 2)
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    int n, temp_max = 0;
    cin >> n;
    vector<int> temp_res, nums(n);
    for (int i = 0; i < n ; ++i)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n ; i++){
        temp_res = find_divisors(nums[i] );
        for(int j = temp_res.size() - 1 ; j >= 0 ; j--){
            if(is_valid(temp_res[j], n, nums) ) {
                temp_max = max(temp_max, temp_res[j] );
                break;
            }
        }
    }
    cout << temp_max << endl;
    return 0;
}