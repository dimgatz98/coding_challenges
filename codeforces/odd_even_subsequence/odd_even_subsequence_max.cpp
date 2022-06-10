#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// alternative of knapsack where item weights and values are equal to find the subset with closest sum to W
int knapSack(int W, vector<int> wt, int n)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 999999, sizeof(dp));
    
    for (int i = 0 ; i < n ; i++) {
        for (int w = W; w > 0; w--) {
            if (wt[i] <= w) {
                // finding the maximum value
                if(w % 2 == 0) {
                    if(dp[w] > max(dp[w - 2], wt[i]) ) {    
                        dp[w] = max(dp[w - 2], wt[i]);
                    }
                }
                else if(dp[w] < max(dp[w - 1], wt[i]) ) {
                    dp[w] = max(dp[w - 1], wt[i]);
                }
            }
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}


int main(int argc, char *argv[]) {
    int n, k, res;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    res = knapSack(k, a, n);
    cout << res << endl;
    return 0;
}