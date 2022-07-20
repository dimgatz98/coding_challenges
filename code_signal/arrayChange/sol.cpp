#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> inputArray) {
    int res = 0, save = inputArray[0];

    for (int i = 1 ; i < (int) inputArray.size() ; i++) {
        if (inputArray[i] > save) {
            save = inputArray[i];
            continue;
        }
        res +=  save + 1 - inputArray[i];
        save++;
    }

    return res;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);


    for (int i = 0 ; i < n ; i ++) {
        cin >> arr[i];
    }

    cout << solution (arr) << endl;

    return 0;
}
