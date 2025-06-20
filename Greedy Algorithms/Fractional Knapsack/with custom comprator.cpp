#include <bits/stdc++.h>
using namespace std;

struct item
{
    string name;
    double weight, price, unit_price;
};

bool comp(item i1, item i2)
{
    return (i1.unit_price > i2.unit_price);
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

    sort(arr, arr+n, comp);
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
