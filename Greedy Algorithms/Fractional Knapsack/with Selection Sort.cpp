#include <bits/stdc++.h>
using namespace std;

struct item
{
    string name;
    double weight, price, unit_price;
};

void selection_sort(item arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        int smallest_idx = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[j].unit_price > arr[smallest_idx].unit_price) //descending order
                smallest_idx = j;
        }
        swap(arr[i], arr[smallest_idx]);
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

    //sort(arr, arr+n, comp); 
    selection_sort(arr, n);
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
    cout << profit << endl;

}
