#include <bits/stdc++.h>
using namespace std;

struct item
{
    string name;
    double weight, price, unit_price;
};

void insertionSort(item arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        item curr = arr[i];
        int prev = i-1;

        while(prev >= 0 && arr[prev].unit_price < curr.unit_price) //descending
        {
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
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
    insertionSort(arr, n);
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
