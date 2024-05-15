#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
/*🦛🦛🦛   🐙🐙🐙*/
vector <ll> ranke(112345);
vector <ll> pai(112345);
 
 
void make_set(ll n)
{
    for(ll i = 1; i <=n; i++)
    {
        ranke[i] = 1;
        pai[i] = i;
    }
 
}
 
 
ll finD(ll x) // Estrutura Union-Find, 
{
    if(pai[x] == x)
        return x;
    pai[x] = finD(pai[x]); // Path compression
    return pai[x];
}
 
 
void unioN(ll x, ll y)
{
    ll q = finD(x);
    ll w = finD(y);
 
    if(q == w)
        return;
    if(ranke[q] > ranke[w])
    {
        pai[w] = q;
        ranke[q] += ranke[w];
    }
    else
    {
        pai[q] = w;
        ranke[w] += ranke[q];
 
    }
 
}
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, m;
    cin >> n>> m;
    make_set(n);
    vector<pair<ll, pair<ll, ll>>> vetor;
    while(m--)
    {
        ll a,b , c;
        cin >> a >> b >> c;
        vetor.push_back({c, {a, b}});
    }
    sort(vetor.begin(), vetor.end());// Ordena com base no peso das arestas
    ll s = vetor.size();
 
    ll  custo = 0;
    for(ll i = 0; i < s; i++)
    {
        ll x = vetor[i].second.first;
        ll y = vetor[i].second.second;
        ll peso = vetor[i].first;
        if(finD(x) != finD(y))
        {
            custo += peso;
            unioN(x, y);
        }
    }
 
 
     if (ranke[finD(1)] == n)        
        cout << custo << "\n";
    else    
        cout << "IMPOSSIBLE\n";
        
 
 
 
 
 
    return 0;
}