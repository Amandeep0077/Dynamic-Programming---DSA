#include<bits/stdc++.h>
using namespace std;

double ZeroOne_Knapsack_Recursion(vector<vector<int>> &items, int W, int n) {
    if(n == 0 || W == 0) return 0;

    int val =items[n-1][0];
    int wt =items[n-1][1];

    if(wt <= W) {
        int include = val + ZeroOne_Knapsack_Recursion(items, W-wt, n-1);
        int exclude = ZeroOne_Knapsack_Recursion(items, W, n-1);
        return max(include, exclude);
    }
    else {
        return ZeroOne_Knapsack_Recursion(items, W, n-1);
    }
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

    cout<< ZeroOne_Knapsack_Recursion(items, W, items.size()); 

    return 0;
}