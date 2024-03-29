#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
vector<vector<int>> adj(MAX);
vector<bool> visitado(MAX,false);
vector<int> cor(MAX);
vector<int> parente(MAX);
/*😈🦛😈🦛
ACHAR CICLO
CICLO  vertices com a mesma cor
*/

bool dfs(int node, int anterior)
{
    visitado[node] = true;
    cor[node] = 1;
    parente[node] = anterior;
    for(int filho : adj[node])
    {
        if(filho != anterior && cor[filho] == 1)
        {
            vector<int> resp;
            int a = node;
            while(a != filho)
            {
                resp.push_back(a);
                a = parente[a];
            }
            resp.push_back(a);
            resp.push_back(resp[0]);


            cout << resp.size() << endl;
            for(auto x : resp)
                cout << x << " " ;
            exit(0);
            return true;
        }
        else if(filho != anterior && cor[filho] == 0)
        {
            bool temp = dfs(filho, node);
            if (temp == true)
            {
                vector<int> res;
                int x = parente[filho];
                while (parente[x] != filho)
                {
                    res.push_back(x);
                    x = parente[x];
                }
                cout << res.size() << "\n";
                for (auto x : res)
                    cout << x << " ";
                exit(0);
                return true;

        }
    }
    
}
return false;
}




int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <=m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i =1; i <= n; i++)
    {
        if(visitado[i] == false)
        {
            dfs(i, 0);
        }
    }


    cout << "IMPOSSIBLE" << endl;


    return 0;
}