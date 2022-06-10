#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void addMin(vector<int> &arr){
    int min = arr[0];
    for(int i = 1 ; i < arr.size() ; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    for(int i = 0 ; i < arr.size(); i++){
        arr[i] += -min;
    }
    return;
}

void print_vect(vector<vector<int> > arr){
    for(int i = 0 ; i < arr.size() ; i++){
        for (int j = 0 ; j < arr[i].size() ; j++){
            cout << arr[i][j] << "      ";
        }
        cout << endl;
    }
}

// alternative of knapsack where item weights and values are equal to find the subset with closest sum to W
int knapSack(int W, vector<int> wt, int n)
{
    // making and initializing dp array
    for(auto w: wt){
        cout << w << " ";
    }
    cout << endl;
    vector<vector<int> > dp;
    vector<int> temp;
    for (int i = 0; i < W + 1; ++i)
    {
        dp.push_back(temp);
        for (int j = 0 ; j < n  + 1 ; ++j) {    
            dp[i].push_back(-1);
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1 ; i < n + 1; i++) {
        cout << "step: " << i << endl;
        cout << wt[i] << endl;
        for (int w = 1; w < W + 1; w++) {
            if (w <= i) {
                // finding the maximum value
                
                // // base case
                if(i == w){
                    if(i == 1)dp[w][i] = wt[i - 1];
                    else if(w % 2 == 0)
                        dp[w][i] = dp[w - 1][i - 1];
                    else
                        dp[w][i] = dp[w - 1][i - 1] + wt[i - 1];
                    continue;
                }
                if(w % 2 == 0) {
                    dp[w][i] = dp[w - 1][i - 1];
                    if(dp[w - 1][i] > dp[w - 2][i - 1] + wt[i - 1]) {    
                        dp[w - 1][i] = dp[w - 2][i - 1] + wt[i - 1];
                    }
                }
                else if(dp[w - 1][i - 1] == -1) {
                    if(dp[w][i - 1] > wt[i - 1]) dp[w][i] = wt[i - 1];
                    else dp[w][i] = dp[w][i - 1];
                }
                else if(dp[w][i - 1] > dp[w - 1][i - 1] + wt[i - 1]) {
                    dp[w][i] = dp[w - 1][i - 1] + wt[i - 1];
                }
                else{
                    dp[w][i] = dp[w][i - 1];   
                }
            }
            else{
                break;
            }
        }
        print_vect(dp);
    }
    return dp[W][n]; // returning the maximum value of knapsack
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