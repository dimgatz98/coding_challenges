#include <iostream>
#include <string>
#include <vector>
using namespace std;

string abbreviation(string a, string b) {
    vector<vector<bool>> dp(b.size() + 1, vector<bool>(a.size() + 1, false));

    dp[0][0] = true;

    for (int i = 1; i < b.size() + 1; i++) {
        dp[i][0] = false;
    }

    for (int i = 1; i < a.size() + 1; i++) {
        dp[0][i] = (islower(a[i - 1])) && (dp[0][i - 1] == true);
    }

    for (int i = 1; i < b.size() + 1; i++) {
        for (int j = 1; j < a.size() + 1; j++) {
            if (islower(a[j - 1])) {
                dp[i][j] = (dp[i - 1][j - 1] && b[i - 1] == toupper(a[j - 1])) ||
                            dp[i][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] && b[i - 1] == a[j - 1];
            }
        }
    }

    return (dp[b.size()][a.size()] ? "YES" : "NO");
}

int main()
{
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        cout << result << "\n";
    }

    return 0;
}
