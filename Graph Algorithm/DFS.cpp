#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, s_node;
    cout << "Enter no. of nodes: ";
    cin >> node;

    cout << "Enter no. of edge: ";
    cin >> edge;

    vector<bool> visited(node + 1, false);
    vector<vector<int>> adj(node + 1);

    cout << "Enter edges: \n";
    for (int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << "Enter start node: ";
    cin >> s_node;

    stack<int> stack;
    stack.push(s_node);

    cout << "DFS: ";
    while (!stack.empty())
    {
        int top = stack.top();
        stack.pop();

        if (!visited[top])
        {
            visited[top] = true;
            cout << top << " ";

            // Go through its neighbors
            for (int i = 0; i < adj[top].size(); i++)
            {
                if (!visited[adj[top][i]])
                {
                    stack.push(adj[top][i]); // Add unvisited neighbor to the stack
                }
            }
        }
    }
}
