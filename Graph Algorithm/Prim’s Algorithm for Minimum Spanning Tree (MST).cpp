#include <bits/stdc++.h>
using namespace std;

#define sz 200005
vector<vector<int>> adj(sz), cost(sz);
vector<int> visited(sz);

priority_queue <pair<int, pair<int, int>>,  
                vector<pair<int, pair<int, int>>>, 
                greater<pair<int, pair<int, int> > > > pq;

int prims(int s_node)
{
    for(int i = 0; i < adj[s_node].size(); i++) 
        pq.push({cost[s_node][i], {s_node, adj[s_node][i]}});

    vector<pair<int, pair<int, int>>> ans;
    visited[s_node] = 1;
    int c, u, v, total = 0;

    while(!pq.empty())
    {
        c = pq.top().first;
        u = pq.top().second.first;
        v = pq.top().second.second;

        pq.pop();

        if(!visited[v] || !visited[u])
        {
            ans.push_back({c, {u, v}});
            total += c;

            if(visited[u] == 1) u = v;
            else u = u;

            visited[u] = 1;
            for(int i = 0; i < adj[u].size(); i++)
            {
                if(!visited[adj[u][i]]) pq.push({cost[u][i], {u, adj[u][i]}});
            }
        }
    }

    cout << "\nMinimum Spanning Tree Edges:\n";
    for(int i = 0; i < ans.size(); i++) 
        cout << i << ": " << ans[i].first <<"-> (" << ans[i].second.first << "," << ans[i].second.second << ")" << endl;
    
    return total;
}


int main ()
{
    int node, edge, s_node;
    cout << "Enter the number of nodes & edges: ";
    cin >> node >> edge;

    for(int i = 0; i < edge; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(b);
        adj[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }

    cout << "Enter start node: ";
    cin >> s_node;

    int result = prims(s_node);
    cout << "\nTotal cost of Minimum Spanning Tree: " << result << "\n";
}
