#include <bits/stdc++.h>
using namespace std;

int vizinhoX[4] = {0, 0, 1, -1};
int vizinhoY[4] = {1, -1, 0, 0};
int visitado[1001][1001];
char grid[1001][1001];
int n,m, resp = 0;

bool valido(int y, int x)
{
    if(y < 0) return false;
    if( x< 0) return false;
    if (y >= n) return false;
    if (x >= m) return false;
    if(grid[y][x] == '#') return false;
    return true;
}




void dfs(int y, int x)
{
    visitado[y][x] = 1;
    for(int i = 0; i <4 ;i++)
    {
        int novoX = x + vizinhoX[i];
        int novoY = y + vizinhoY[i];
        if(valido(novoY, novoX))
        {
            if(!visitado[novoY][novoX])
            {
                dfs(novoY, novoX);
            }
        }
    }

}




int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;

    for(int i =0; i <n ; i++ )
    {
        for(int j =0; j <m; j++)
        {
            cin >> grid[i][j];
            visitado[i][j] = 0;
        }
    }

     for(int i =0; i <n ; i++ )
    {
        for(int j =0; j <m; j++)
        {
            if(grid[i][j] == '.' && !visitado[i][j])
            {
                dfs(i,j);
                resp++;
            }
        }
    }


    cout << resp <<endl;
    return 0;

}