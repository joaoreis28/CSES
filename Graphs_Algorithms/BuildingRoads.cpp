#include <bits/stdc++.h>
using namespace std;



#define MAX 112345
#define p pair<int, int>
#define mp make_pair

vector<vector<int>> adj(MAX);
vector<bool> visitado(MAX, false);
vector<int> pontes;

void dfs(int g)
{
    visitado[g] = true;
    for(auto a : adj[g])
    {
        if(visitado[a] == false)
            dfs(a);
    }
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a,  b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        if(visitado[i] == false)
        {
            pontes.push_back(i);
            dfs(i);
        }
    }
    cout << pontes.size() - 1 << endl;
    for(int i = 0; i < pontes.size() - 1 ; i++)
    {
        cout << pontes[i] << " " << pontes[i + 1] << endl;
    }
    
    
    return 0;
}
