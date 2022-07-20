#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int solution (vector<int> coins, vector<int> quantity) {
    unordered_set<int> s;
    s.insert(0);
    
    for(int i = 0; i < (int) quantity.size(); i++){
        vector<int> sums (s.begin(), s.end());
        for(auto k : sums){
            for(int l = 1; l <= quantity[i]; l++){
                s.insert(k + l * coins[i]);
            }
        }
    }
    return s.size() - 1;
}

int main() {
    int n, tmp;
    vector<int> coins, quantity;

    cin >> n;
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        coins.push_back(tmp);
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        quantity.push_back(tmp);
    }

    // coins: [3, 1, 1]
    // quantity: [111, 84, 104]

    int res = solution(coins, quantity);
    cout << res << endl;

    return 0;
}
