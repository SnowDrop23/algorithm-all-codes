
#include <bits/stdc++.h>
using namespace std;

struct activity
{
    string name;
    double start_time, end_time;
};

bool comp(activity a1, activity a2)
{
    return (a1.end_time < a2.end_time);
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    activity arr[n];
    
    cout << "Enter activity name, start time and end time:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].name >> arr[i].start_time >> arr[i].end_time;
    }
    sort(arr, arr+n, comp);
    

    int count = 1;
    double last_end = arr[0].end_time;

    vector<string> selected;
    selected.push_back(arr[0].name);

    for(int i = 1; i < n; i++)
    {
        if(arr[i].start_time >= last_end)
        {
            count++;
            last_end = arr[i].end_time;
            selected.push_back(arr[i].name);
        }
    }

    cout << "Total selected activity: " << count << endl;
 
    cout << "Selected Activities: ";
    for(int i = 0; i < selected.size()-1; i++) cout << selected[i] << ", ";
    cout << selected[selected.size() - 1] << ".";
}
