#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, atual = 0, maior = 0;
    cin >> n;
    vector<pair<ll, ll>> clientes;
    for(ll i = 0; i < n; i++)
    {
        ll inicio, fim;
        cin >> inicio >> fim;
        clientes.push_back({inicio, 1});
        clientes.push_back({fim, -1});
    }

   

    sort(clientes.begin(), clientes.end());
    

    for(ll i = 0; i < clientes.size(); i++)
    {
        atual = atual + clientes[i].second;
        maior = max(maior, atual);
        
    }


    cout << maior << endl;


    return 0;
}