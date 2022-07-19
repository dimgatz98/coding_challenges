#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void print_vector (vector<int> v) {
    for (auto x: v) {
        cout << x << " ";
    }
    cout << endl;
}

vector<int> solution(vector<int> a) {
    stack<int> s;
    vector<int> res = {-1};

    s.push(a[(int) a.size() - 1]);

    for (int i = (int) a.size() - 2 ; i >= 0 ; i--) {
        while (s.top() < a[i]) {
            s.pop();
            if (s.empty()) {
                break;
            }
        }

        if (s.empty()) {
            res.insert(res.begin(), -1);
        } else {
            res.insert(res.begin(), s.top());
        }

        s.push(a[i]);
    }

    return res;
}

int main () {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    // a = [6, 7, 3, 8]
    print_vector(solution (a));
}
