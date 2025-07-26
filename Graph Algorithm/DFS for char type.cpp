#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node, edge, s_node;
    cout << "Enter the number of edges: ";
    cin >> edge;

    vector<bool> visited(26, false);
    vector<vector<int>> adj(26);

    cout << "Enter the edges: ";
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
    cout << "Enter start node: ";
    cin >> s_char;
    s_node = s_char - 'A';

    stack<int> st;
    st.push(s_node);

    cout << "DFS: ";
    while(!st.empty())
    {
        int t = st.top();
        st.pop();
        

        if(!visited[t])
        {
            visited[t] = true;
            cout << (char)(t + 'A') << " ";

            for(int i = 0; i < adj[t].size(); i++)
            {
                if(!visited[adj[t][i]])
                {
                    st.push(adj[t][i]);
                }
            }
        }
    }
}
