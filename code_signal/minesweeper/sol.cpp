#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<bool>> matrix) {
    vector<vector<int>> res;
    for (int i = 0 ; i < (int) matrix.size() ; i++) {
        res.push_back({});
        for (int j = 0 ; j < (int) matrix[0].size() ; j++) {
            res[i].push_back(0);
        }
    }

    for (int i = 0 ; i < (int) matrix.size() ; i++) {
        for (int j = 0 ; j < (int) matrix[0].size() ; j++) {
            if (matrix[i][j]) {
                for (int k = -1 ; k < 2 ; k++) {
                    for (int l = -1 ; l < 2 ; l++) {
                        if (i + k < 0 || i + k > (int) res.size() - 1 || j + l < 0 || j + l > (int) res[0].size() - 1 || (k == 0 && l == 0)) {
                            continue;
                        }

                        res[i + k][j + l]++;
                    }
                }
            }
        }
    }

    return res;
}

void print_vect_vect (vector<vector<int>> ar) {
    for (auto v: ar) {
        for (auto x: v) {
            cout << x << " ";
        }
        cout << endl;
    }
}

int main () {
    int n, m, tmp;
    cin >> n >> m;
    vector<vector<bool>> ar;

    for (int i = 0 ; i < n ; i++) {
        ar.push_back({});
        for (int j = 0 ; j < m ; j++) {
            cin >> tmp;
            ar[i].push_back(tmp);
        }
    }

    print_vect_vect (solution (ar));
}
