#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
#define MAX 2000000
ll fac[MAX + 1];
ll inv[MAX + 1];
vector <int> ocorrencia(26,0);
 
 
/* Teorema Multinomial*/
 
ll expbin( ll a, ll exp)
{
    if(exp == 0 )
        return 1;
    if( exp & 1)
        return (a * expbin(a, exp - 1)) % MOD;
    ll b = expbin(a, exp / 2);
    return (b*b) % MOD;
}
 
 
void init()
{
    fac[0]= inv[0] = 1;
    for(int i =  1; i <= MAX; i++)
    {
        fac[i] = i * fac[i-1] % MOD;
        inv[i] = expbin(fac[i], MOD - 2);
    }
}
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    ll soma = 0, resp = 0;
    string s;
    cin >> s;
    for(auto l : s)
        ocorrencia[l - 'a']++;
 
    for(auto i : ocorrencia)
        soma += i;
 
    resp = fac[soma];
 
    for(auto i : ocorrencia)
        resp  = (resp * inv[i]) % MOD;
 
    cout << resp << endl;
    
 
 
    return 0;
}