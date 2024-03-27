#include <bits/stdc++.h>
using namespace std;



#define MAX 112345
#define p pair<int, int>
#define mp make_pair
int resp = 0;
int n, m, glob = 0;
vector<vector<int>> adj(MAX);
vector<bool> visitado(MAX, false);
queue<int> q;
int dist[MAX];
int anterior[MAX];






int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    q.push(1);
    visitado[1]  = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto a : adj[u])
        {
            if(!visitado[a])
            {
                dist[a] = dist[u] + 1;
                visitado[a] = true;
                q.push(a);
                anterior[a] = u;
            }
        }
    }

    if(!visitado[n])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int u = n;
    int k = dist[n];
    int ans[k + 1];
    for(int i = k; i >= 0; i--)
    {
        ans[i] = u;
       u= anterior[u];

    }

    cout << dist[n] + 1 << endl;
    for(int i = 0 ; i <= dist[n]; i++)
        cout << ans[i] << " " ;
}
