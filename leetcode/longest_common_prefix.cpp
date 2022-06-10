#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void printv(vector<T> v) { 
    for (T x: v) {
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char save;
        for (int j = 0 ; j < strs[0].size() ; j++) {
            save = strs[0][j];
            for (int i = 1 ; i < strs.size() ; i++) {
                if (strs[i][j] != save || j >= strs[i].size()) { 
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    vector<string> a({"flower","flow","flight"});
    cout << Solution().longestCommonPrefix(a) << endl;
}