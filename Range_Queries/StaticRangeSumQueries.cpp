#include <bits/stdc++.h>
using namespace std;
#define MAX 212345
typedef long long ll;


ll v[MAX];
 ll pre[MAX];
 ll n, m, a, b;

void build()
{
    pre[0] = 0;
    for(ll i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + v[i- 1];
    }
}

void query(ll a, ll b)
{
    cout << pre[b] - pre[a - 1] << endl;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m;
   
    for(ll i = 0; i < n; i++)
        cin >> v[i];

    
    build();
    for(ll i = 0; i < m; i++)
    {
        cin >> a >> b;
        query(a, b);
    }
    

    return 0;
}

//3 2 4 5 1 1 5 3