#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> image) {
    vector<vector<int>> res;

    for (int i = 0 ; i < image.size() - 2 ; i++) {
        res.push_back({});
        for (int j = 0 ; j < image[0].size() - 2 ; j++) {
            res[i].push_back(0);
            for (int k = 0 ; k  < 3 ; k++) {
                for (int l = 0  ; l < 3 ; l++) {
                    res[i][j] += image[i + k ][j + l];
                }
            }
            res[i][j] /= 9;
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
    int n, tmp;
    cin >> n;
    vector<vector<int>> ar;

    for (int i = 0 ; i < n ; i++) {
        ar.push_back({});
        for (int j = 0 ; j < n ; j++) {
            cin >> tmp;
            ar[i].push_back(tmp);
        }
    }

    print_vect_vect (solution (ar));

    return 0;
}