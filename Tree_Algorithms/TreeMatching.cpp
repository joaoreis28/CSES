#include <bits/stdc++.h>
using namespace std;
#define MAX 212345
int n;

vector<vector<int>> adj(MAX);
/*😈🦛😈🦛
hopcroft_karp */
void biparte(int u, int p, int l)
{
    if(l % 2 && p != -1)
    {
        adj[u].push_back(p + n);
        adj[p + n].push_back(u);
    }
    for(int v : adj[u])
    {
        if(v != p)
        {
            if(l % 2)
            {
                adj[u].push_back(v + n);
                adj[v + n].push_back(u);
            }
            biparte(v,u, l+1);
        }
    }
}



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n - 1;i++)
    {
        int a, b;
        cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    biparte(1, -1, 1);


    return 0;
}