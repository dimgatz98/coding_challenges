#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    vector<int> prefix_ar;
    int sum = 0, sz = (int) a.size();
    for (auto i: a) {
        sum += i;
        prefix_ar.push_back(sum);
    }

    int tmp, res = prefix_ar[sz - 1] - sz * a[0], index = 0;
    for (int i = 1 ; i < sz ; i++) {
        tmp = a[i] * (i + 1) - prefix_ar[i];
        tmp += prefix_ar[sz - 1] - prefix_ar[i] - (sz - 1 - i) * a[i];
        if (res > tmp) {
            res = tmp;
            index = i;
        }
    }

    return a[index];
}

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
    }

    cout << solution (a) << endl;

    return 0;
}
