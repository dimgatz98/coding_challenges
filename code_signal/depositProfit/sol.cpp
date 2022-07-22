#include <iostream>

using namespace std;

int solution(int deposit, int rate, int threshold) {
    int counter = 0;
    float res = deposit;
    while (res < threshold) {
        counter++;
        res *= (float) (100 + rate) / 100;
    }

    return counter;
}

int main() {
    int deposit, rate, threshold;
    cin >> deposit >> rate >> threshold;

    cout << solution (deposit, rate, threshold) << endl;

    return 0;
}