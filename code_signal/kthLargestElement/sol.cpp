#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums, int k) {
    stack<int> s1, s2;

    for (auto n: nums) {
        if (s1.empty()) {
            s1.push(n);
            continue;
        }

        while (n < s1.top()) {
            s2.push(s1.top());
            s1.pop();
            if (s1.empty()) {
                break;
            }
        }

        s1.push(n);

        while (! s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    for (int i = 0 ; i < k - 1 ; i++) {
        s1.pop();
    }

    return s1.top();
}


int main() {
    int n, k, tmp;
    vector<int> v;
    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> k;

    // nums = [7, 6, 5, 4, 3, 2, 1]
    // k = 2
    cout << solution(v, k) << endl;

    return 0;
}