#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> inputArray, int k) {
    int counter = 0;
    for (int i = k - 1 ; i - counter < (int) inputArray.size() ; i += k) {
        inputArray.erase(inputArray.begin() + i - counter);
        counter++;
    }

    return inputArray;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> ar(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> ar[i];
    }

    for (auto x: solution (ar, k))
        cout << x << " ";
    cout << endl;
}
