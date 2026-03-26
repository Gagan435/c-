#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    
    cout << "===== 0/1 Knapsack Problem =====\n";
    cout << "Enter number of items: ";
    cin >> n;
    
    vector<int> weight(n), value(n);
    
    cout << "Enter weights of " << n << " items: ";
    for(int i = 0; i < n; i++) cin >> weight[i];
    
    cout << "Enter values of " << n << " items: ";
    for(int i = 0; i < n; i++) cin >> value[i];
    
    cout << "Enter Knapsack Capacity (W): ";
    cin >> W;

    // DP Table: dp[i][w] = max value using first i items with capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            // Don't take item i
            dp[i][w] = dp[i-1][w];

            // Take item i (if possible)
            if(weight[i-1] <= w) {
                dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i-1]] + value[i-1]);
            }
        }
    }

    cout << "\nMaximum Value in Knapsack = " << dp[n][W] << endl;

    // Optional: Print the DP Table
    cout << "\nDP Table:\n";
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    return 0;
}