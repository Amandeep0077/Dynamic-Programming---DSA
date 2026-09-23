#include <bits/stdc++.h>
using namespace std;

// static bool compare(vector<int> &a, vector<int> &b)
// {
//     double a1 = (1.0 * a[0]) / a[1];
//     double b1 = (1.0 * b[0]) / b[1];
//     return a1 > b1;
// }

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    int n = val.size();

    vector<vector<int>> items(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        items[i][0] = val[i];
        items[i][1] = wt[i];
    }

    sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b) {
        double a1 = (1.0*a[0]) / a[1];
        double b1 = (1.0*b[0]) / b[1];
        return a1 > b1;
    });

    double result = 0.0;
    int currentCapacity = capacity;

    for (auto &item : items)
    {
        int val = item[0];
        int wt = item[1];

        if (wt <= currentCapacity)
        {
            result += val;
            currentCapacity -= wt;
        }
        else
        {
            result += ((1.0) * val / wt) * currentCapacity;

            break;
        }
    }

    return result;
}

int main()
{
    vector<int> value = {60, 100, 120, 80, 150};
    vector<int> weight = {10, 20, 30, 40, 15};

    cout<<"Total Profit:  "<<fractionalKnapsack(value, weight, 60)<<endl;

    return 0;
}