#include <bits/stdc++.h>
using namespace std;
#define sz 100005
vector<vector<int>> adj(sz);


vector<int> dfs(int node, int s_node)
{
    vector<int> ans;
    vector<bool> visited(node+1, 0);


    stack<int> st;
    visited[s_node] = true;
    st.push(s_node);

    while(!st.empty())
    {
        int top = st.top();
        ans.push_back(top);
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
    return ans;
}


vector<int> bfs(int node, int s_node)
{
    vector<int> ans;

    vector<bool> visited(node+1, 0);
    queue<int> q;
    visited[s_node] = true;
    q.push(s_node);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(int i = 0; i < adj[front].size(); i++)
        {
            if(!visited[adj[front][i]])
            {
                visited[adj[front][i]] = true;
                q.push(adj[front][i]);
            }
        }
        
    }
    return ans;
}



int main()
{
    int node, edge, s_node;
    cout << "Enter nodes & edges: ";
    cin >> node >> edge;

    cout << "Enter edges: \n";
    for(int i = 0; i < edge; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "Enter start node: ";
    cin >> s_node;

    cout << "BFS Traversal: ";
    vector<int> ans = bfs(node, s_node);
    for(int i : ans) cout << i << " ";
    cout << endl;

    cout << "DFS Traversal: ";
    vector<int> abss = dfs(node, s_node);
    for(int i : abss) cout << i << " ";
    cout << endl;
    
}
