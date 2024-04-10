#include <bits/stdc++.h>
using namespace std;
int n,m;
#define p pair<int, int>
#define mp make_pair

string letra = "RLDU";
int vizinhoX[4] = {0, 0, 1, -1};
int vizinhoY[4] = {1, -1, 0, 0};

char grid[1001][1001];
int visitado[1001][1001];
int anterior[1000][1000];


bool valido(p node)
{
    if(node.second < 0) return false;
    if( node.first< 0) return false;
    if (node.second >= m) return false;
    if (node.first >= n) return false;
    if(grid[node.first][node.second] == '#') return false;
    return true;
}




int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    queue<p> q;
    p comeco, fim;
    memset(visitado, 0, sizeof(visitado));
    memset(anterior, 0, sizeof(anterior));

    for(int i = 0; i <n; i ++)
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
                comeco = mp(i,j);
            else if(grid[i][j] == 'B')
                fim = mp(i,j);                

        }


    
    q.push(comeco);
    visitado[comeco.first][comeco.second] = 1;
    while(!q.empty())
    {
        
        p tmp = q.front();
        q.pop();
        for(int i = 0; i < 4 ;i++)
        {
            p u = mp(tmp.first + vizinhoX[i], tmp.second  +  vizinhoY[i]);
            if(valido(u))
            {
                if(!visitado[u.first][u.second])
                {
                    visitado[u.first][u.second] = 1;
                    anterior[u.first][u.second] = i;
                    q.push(u);
                }
            }
        }    
    }

    
    if(visitado[fim.first][fim.second])
    {
        cout << "YES" <<endl;
        vector<int> bomba;
        while(fim != comeco)
        {
            int a = anterior[fim.first][fim.second];
            bomba.push_back(a);
            fim = mp(fim.first - vizinhoX[a], fim.second - vizinhoY[a]);
        }
    
        reverse(bomba.begin(), bomba.end());


        cout << bomba.size() << endl;
         for (char c : bomba) { cout << letra[c]; }
		    cout << endl;
	} else {
		cout << "NO" << endl;
	}
    



    return 0;

}