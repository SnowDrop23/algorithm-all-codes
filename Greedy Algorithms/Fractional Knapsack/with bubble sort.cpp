#include <bits/stdc++.h>
using namespace std;

struct item
{
    string name;
    double weight, price, unit_price;
};

void bubble_sort(item arr[], int n)
{
    int counter = 1;
    while(counter < n)
    {
        for(int i = 0; i < n-counter; i++)
        {
            if(arr[i].unit_price < arr[i+1].unit_price) swap(arr[i], arr[i+1]);
        }
        counter++;
    }
}


int main()
{
    int n;
    double capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    item arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].weight >> arr[i].price;
        arr[i].unit_price = arr[i].price/arr[i].weight;
    }

    
    bubble_sort(arr, n);
    cout << "Enter the capacity of Knapsack: ";
    cin >> capacity;

    double profit = 0;

    for(int i = 0; i < n; i++)
    {
        if(arr[i].weight <= capacity)
        {
            profit += arr[i].price;
            capacity -= arr[i].weight;
        }
        else
        {
            profit += arr[i].unit_price * capacity;
            break;
        }
    }
    cout << "Profit: " << profit << endl;


}
