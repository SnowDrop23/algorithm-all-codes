#include <bits/stdc++.h>
using namespace std;

int main()
{
    int edge, s_node;
    cout << "Enter the number of edges: ";
    
    cin >> edge;

    vector<bool> visited(26, false);
    vector<vector<int>> adj(26);

    cout << "Enter the edges: \n";
    for(int i = 0; i < edge; i++)
    {
        char a, b;
        cin >> a >> b;
        int u = a - 'A';
        int v = b - 'A';

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    char s_char;
    cout << "Enter the start node: ";
    cin >> s_char;
    s_node = s_char - 'A';

    queue<int> q;
    q.push(s_node);
    visited[s_node] = true;



    cout << "BFS : ";
    while(!q.empty())
    {
        int front = q.front();
        cout << (char)(front+'A') << " ";
        q.pop();

        for(int i = 0; i < adj[front].size(); i++)
        {
            if(!visited[adj[front][i]])
            {
                visited[adj[front][i]] = true;
                q.push(adj[front][i]);
            }
        }
    }
}
