#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        vector<int> nums_cp(nums);
        int left = 0, right = nums.size() - 1, solleft, solright;
        sort(nums.begin(), nums.end());
        while(true) {
            int sum = nums[left] + nums[right];
            if (sum == target)
                {
                    if (nums[left] >= nums[right]){
                        left = (int)((find(nums_cp.begin(), nums_cp.end(), nums[left])) - nums_cp.begin());
                        nums_cp.erase(nums_cp.begin() + left);
                        right = (int)((find(nums_cp.begin(), nums_cp.end(), nums[right])) - nums_cp.begin()) + 1;
                    }
                    else{
                        left = (int)((find(nums_cp.begin(), nums_cp.end(), nums[left])) - nums_cp.begin());
                        right = (int)((find(nums_cp.begin(), nums_cp.end(), nums[right])) - nums_cp.begin());
                    }
                    return {left, right};
                }
            else if (sum < target)
                left++;
            else if (sum > target)
                right--;
        }
        return {0, 0};
    }
};

int main() {
    Solution a;
    for (int x: a.twoSum({3, 3}, 6)) {
        cout << x << " ";
    }
    cout << endl;
}