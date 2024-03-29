#include <bits/stdc++.h>
using namespace std;

#define p pair<int, int>
#define MAX 112345
#define mp make_pair
/*😈😈😈🦛🦛🦛coloring the bipartite graphs 

Iremos tentar Colorir os vertices de forma gulosa, se o vertice V nao foi visitado, iremos o 
colorir de branco e aplicar uma DFS. Em seguida, iremos colorir todos os vizinhos de V de branco
com a cor preta e aplicar a DFS.
No final, testamos se cada aresta tem vertices com cores diferentes em suas extremidades


*/

vector<vector<int>> adj(MAX);
vector<bool> visitado(MAX, false);
vector<int> cor(MAX); // branco 1, preto 2
int cont = 0;
bool ok = true;

void dfs(int node, int color)
{
    
    visitado[node] = true;
    cor[node] = color;
    for (int filho : adj[node])
    {
        if (visitado[filho] == false)
        {
            dfs(filho, 1- color);
        }
        else if(cor[filho] == cor[node])
        {
            ok = false;
            return;
        }
        if(!ok)
            return;
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (int i = 1; i <= n; i++)
    {

        if (visitado[i] == false)
        {            
            dfs(i, 0);
        }
    }

   

    if (!ok)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            cout << cor[i] + 1 << " ";
    }
        

    return 0;
}