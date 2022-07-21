#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int solution(vector<int> ar) {
    vector<int> steps;
    vector<int> to_erase;
    unordered_set<int> s;
    int max = ar[0];

    for (auto x: ar) {
        if (max < x) {
            max = x;
        }
    }

    for (int i = 0 ; i <= max ; i++) {
        steps.push_back(i + 1);
    }

    for (auto x: ar) {
        s.insert(x);
    }

    for (int i = 0 ; i <= max ; i++) {
        if (s.find(i) != s.end()) {
            for (int j = 0 ; j < (int) steps.size() ; j++) {
                if (i % steps[j] == 0) {
                    to_erase.push_back(j);
                }
            }
            for (int j = (int) to_erase.size() - 1 ; j >= 0 ; j--) {
                steps.erase(steps.begin() + to_erase[j]);
            }
            to_erase.clear();
        }
    }

    return steps[0];
}


int main () {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> v[i];
    }

    cout << solution (v) << endl;
}