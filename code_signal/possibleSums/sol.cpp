#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void print_vect(vector<pair<vector<int>, int>> v) {
    for (auto x: v) {
        for (auto y: x.first)
            cout << y << " ";
        cout << " / " << x.second << endl;
    }
    return;
}

string string_from_vector(vector<int> v) {
    string s;
    for (auto x : v) {
        s += (to_string(x));
    }
    return s;
}

int solution(vector<int> coins, vector<int> quantity) {
    unordered_set<int> seen;
    unordered_set<string> seen_state;
    vector<pair<vector<int>, int> > m, m_cp;
    vector<int> tmp = quantity;
    m.push_back({tmp, 0});

    int res = 0, counter = 0, prev_size;
    bool empty;
    while (m.empty() == false) {
        counter++;
        m_cp = m;
        prev_size = (int) m.size() - 1;
        for (int j = 0 ; j <  (int) m_cp.size() ; j++) {
            // cout << "counter = " << counter << endl;
            // print_vect(m);

            for (int i = 0 ; i < (int) m_cp[j].first.size() ; i++) {
                if (m_cp[j].first[i] == 0) continue;
                tmp = m_cp[j].first;
                tmp[i]--;
                if (seen_state.find(string_from_vector(tmp)) != seen_state.end()) {
                    continue;
                } else {
                    seen_state.insert(string_from_vector(tmp));
                }
                m.push_back({tmp, m_cp[j].second + coins[i]});

                if (seen.find(m_cp[j].second + coins[i]) == seen.end()) {
                    seen.insert(m_cp[j].second + coins[i]);
                    res++;
                    // cout << "res = " << res << endl;
                }
            }
        }

        for (int i = prev_size ; i >= 0 ; i--) {
            m.erase(m.begin() + i);
        }
    }

    return res;
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
