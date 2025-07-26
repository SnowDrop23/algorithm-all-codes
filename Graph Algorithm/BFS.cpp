#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, s_node;
    cout << "Enter the number of nodes & edges: ";
    cin >> node >> edge;

    vector<bool> visited(node+1, false);
    vector<vector<int>> adj(node+1);

    cout << "Enter the edges: \n";
    for(int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter the start node: ";
    cin >> s_node;

    queue<int> q;
    q.push(s_node);
    visited[s_node] = true;



    cout << "BFS : ";
    while(!q.empty())
    {
        int front = q.front();
        cout << front << " ";
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
