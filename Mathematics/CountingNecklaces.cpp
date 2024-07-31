#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007
 
ll n, m, resp = 0;
 // Burnside’s Lemma
 
 
ll expbin( ll a, ll exp)
{
    if(exp == 0 )
        return 1;
    if( exp & 1)
        return (a * expbin(a, exp - 1)) % MOD;
    ll b = expbin(a, exp / 2);
    return (b*b) % MOD;
}
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> m;
 
    for (ll i = 0; i < n; i++)
    {
        ll t = expbin(m, __gcd(i, n));
        t = t * expbin(n, MOD -2);
        resp += t;
        resp %= MOD;
    }
   cout << resp;
}