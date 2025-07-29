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

    stack<int> st;
    st.push(s_node);
    visited[s_node] = true;

  
    cout << "DFS : ";
    while(!st.empty())
    {
        int top = st.top();
        cout << top << " ";
        st.pop();

        for(int i = 0; i < adj[top].size(); i++)
        {
            if(!visited[adj[top][i]])
            {
                visited[adj[top][i]] = true;
                st.push(adj[top][i]);
            }
        }
    }
}
