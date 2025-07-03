/*
1. Minimum number of coins
2. Selected coins
3. DP Table
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, amount;

    // Input number of coin denominations
    cout << "Enter the number of coins: ";
    cin >> n;

    // Input the values of the coins
    vector<int> coin(n);
    cout << "Enter the coin denominations: ";
    for(int i = 0; i < n; i++) cin >> coin[i];
    
    // Input the target amount
    cout << "Enter the target amount: ";
    cin >> amount;

    // DP table: table[i][j] represents minimum number of coins to make amount j using first i coins
    int table[n+1][amount+1];

    // Base case: amount 0 can be formed with 0 coins
    for(int i = 0; i <= n; i++) table[i][0] = 0;

    // Initialize first row: impossible to form positive amounts without coins
    for(int j = 1; j <= amount; j++) table[0][j] = amount + 1; // amount+1 is used as "infinity"

    // Fill DP table
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= amount; j++)
        {
            if(j >= coin[i-1])
            {
                // Minimum of: not taking this coin vs taking it (since unlimited supply)
                table[i][j] = min(table[i-1][j], 1 + table[i][j - coin[i-1]]);
            }
            else
            {
                // Cannot take this coin (too big)
                table[i][j] = table[i-1][j];
            }
        }
    }

    // Output result
    if(table[n][amount] > amount) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum number of coins required: " << table[n][amount] << endl;
    }

    // Backtracking to find selected coins
    vector<int> selected_coins;
    int i = n, j = amount;

    while(i > 0 && j > 0)
    {
        if(table[i][j] != table[i-1][j])
        {
            // This coin was included
            selected_coins.push_back(coin[i-1]);
            j -= coin[i-1];
        }
        else
        {
            // Move to previous row (skip current coin)
            i--;
        }
    }

    // Output selected coins in order
    cout << "Selected coins to make the amount: ";
    reverse(selected_coins.begin(), selected_coins.end());
    for(int c : selected_coins) cout << c << " ";
    cout << endl;

    // Print full DP table
    cout << "\nDP Table (Minimum coins for each amount):\n";
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= amount; j++)
            cout << setw(4) << table[i][j];
        cout << endl;
    }

    return 0;
}
