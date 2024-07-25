#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007
 
#define MAX 2000000
 
ll fac[MAX + 1];
ll inv[MAX + 1];
 
 
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    init();
	ll n;
    cin >> n;
 
    if( n & 1)
    {
        cout << 0;
        return 0;
    }
        
    n = n / 2;
    ll inverse = expbin(n + 1, MOD - 2);
 
   
 
    cout << ( (inverse) * (  fac[2*n] * inv[n] % MOD* inv [n] % MOD) ) % MOD;    
}