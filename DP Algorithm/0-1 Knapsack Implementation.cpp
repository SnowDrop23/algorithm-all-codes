/*
1. Max Profit
2. Selected Items
3. Total Weight of selected items
4. DP Table
*/

#include <bits/stdc++.h>
using namespace std;

// Structure to store each item's name, weight, and price
struct item {
    string name;
    int weight, price;
};

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    // Input all items into a vector
    vector<item> items(n);
    cout << "Enter name, weight, and price of each item:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].name >> items[i].weight >> items[i].price;
    }

    int capacity;
    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Create a 2D array for DP table: arr[i][j] stores max profit using first i items with capacity j
    int arr[n+1][capacity+1];

    // Initialize first row and column to 0 (base cases)
    for(int i = 0; i <= n; i++) arr[i][0] = 0;
    for(int j = 0; j <= capacity; j++) arr[0][j] = 0;

    // Build the DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= capacity; j++) {
            // If current item's weight is less than or equal to current capacity
            if(items[i-1].weight <= j)
                // Take max of: not taking item vs taking item (include price + remaining capacity)
                arr[i][j] = max(arr[i-1][j], items[i-1].price + arr[i-1][j - items[i-1].weight]);
            else
                // If item can't be included, take value from above row
                arr[i][j] = arr[i-1][j];
        }
    }

    // Output the maximum profit possible
    cout << "Max profit is " << arr[n][capacity] << endl;

    // Backtracking to find which items were selected
    int i = n, j = capacity;
    vector<string> selected;  
    int w = 0;                

    while(i > 0 && j > 0) {
        // If value changes from the row above, item was included
        if(arr[i][j] != arr[i-1][j]) {
            selected.push_back(items[i-1].name);       // Save item name
            w += items[i-1].weight;                    // Add its weight to total
            j -= items[i-1].weight;                    // Reduce capacity
        }
        i--;  // Move to previous item
    }

    
    cout << "Total weight of selected items: " << w << endl;

    // Print names of selected items in original order
    cout << "Selected items are: ";
    reverse(selected.begin(), selected.end());  // Reverse for original input order
    for(string i : selected) cout << i << " ";
    cout << endl;

    cout << "\nDP Table:\n";
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= capacity; j++)
            cout << setw(4) << arr[i][j];  // setw(4) formats spacing for alignment, means reserve at least 4 spaces for this value, pad left if needed.
        cout << endl;
    }

    return 0;
}
