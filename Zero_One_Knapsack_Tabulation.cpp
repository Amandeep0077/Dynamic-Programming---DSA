#include<bits/stdc++.h>
using namespace std;

double ZeroOne_Knapsack_TabulationDP(vector<vector<int>> &items, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            int val = items[i-1][0];
            int wt = items[i-1][1];

            if(wt <= j) {
                dp[i][j] = max(val + dp[i-1][j-wt], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}

int main() {

    vector<vector<int>> items = {
        {20, 2},
        {30, 3},
        {50, 4},
        {60, 5},
        {100, 9},
    }; //val, wt

    int W = 10;

    
    cout<< ZeroOne_Knapsack_TabulationDP(items, W, items.size()); 

    return 0;
}