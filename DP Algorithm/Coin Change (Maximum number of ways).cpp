/*
1. Max number of ways
2. DP Table
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amount;

    // Input: number of coin denominations
    cout << "Enter the number of coins: ";
    cin >> n;

    vector<int> coin(n);

    // Input: coin denominations
    cout << "Enter the coin denominations: ";
    for(int i = 0; i < n; i++) cin >> coin[i];
    
    // Input: target amount
    cout << "Enter the target amount: ";
    cin >> amount;

    // DP table: table[i][j] = number of ways to make amount j using first (i+1) coins
    int table[n][amount+1];

    // Base case: amount 0 can always be made with 1 way (pick nothing)
    for(int i = 0; i < n; i++) table[i][0] = 1;

    // Initialize first row: using only coin[0]
    for(int j = 1; j <= amount; j++) {
        if(j % coin[0] == 0) table[0][j] = 1;
        else table[0][j] = 0;
    }

    // Fill DP table
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= amount; j++) {
            if(j >= coin[i]) {
                // Include current coin + exclude current coin
                table[i][j] = table[i-1][j] + table[i][j - coin[i]];
            }
            else {
                // Cannot include current coin
                table[i][j] = table[i-1][j];
            }
        }
    }

    // Output: total number of ways
    cout << "\nMaximum number of ways to make change: " << table[n-1][amount] << endl;

    // Output: DP table
    cout << "\nDP Table (number of ways to make each amount):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= amount; j++)
            cout << setw(4) << table[i][j];
        cout << endl;
    }

    return 0;
}
