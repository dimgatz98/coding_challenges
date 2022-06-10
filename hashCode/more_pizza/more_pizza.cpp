#include <stdio.h>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// alternative of knapsack where item weights and values are equal to find the subset with closest sum to W
int knapSack(int W, vector<int> wt, int n, vector<int> &parent)
{
    // making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0 ; i < n ; i++) {
        for (int w = W; w >= 0; w--) {
 
            if (wt[i] <= w)
                // finding the maximum value
                if(dp[w] < dp[w - wt[i] ] + wt[i]) 
                {
                    dp[w] = dp[w - wt[i] ] + wt[i];
                    parent[w] = i; //holding this parent array to later get the actual sequence
                }
        }
    }
    return dp[W]; // returning the maximum value of knapsack
}

int main(int argc, char const *argv[])
{
    int W, n;
    scanf("%d%d", &W, &n);
    vector<int> a(n);
    vector<int> parent(W + 1, -1);

    for(int &x :a){
        scanf("%d", &x);
    }

    int sum = knapSack(W, a, n, parent);
    cout << sum << endl;
    
    vector<int> answer;
    while(parent[sum] != -1){
        answer.push_back(parent[sum] );
        sum -= a[parent[sum] ];
    }    
    sort(answer.begin(), answer.end() );
    
    for(auto i: answer){
        cout << i << " ";
    }
    cout << endl;
}