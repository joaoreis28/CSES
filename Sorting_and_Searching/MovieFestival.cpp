#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(pair<int, int> &a, pair<int, int> &b )
{
    return (a.second < b.second);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<pair<int,int>> filmes(n);
    for(int i = 0; i < n; i++)
        cin >> filmes[i].first >> filmes[i].second;
        
    
    sort(filmes.begin(), filmes.end(), cmp);

    int i = 0;
    int fim = -1;
    int resp = 0;

    while( i < n)
    {
        if(filmes[i].first >= fim)
        {
            resp++;
            fim = filmes[i].second;
            i++;
        }
        else
            i++;
    }

    cout << resp << endl;

    return 0;
}


