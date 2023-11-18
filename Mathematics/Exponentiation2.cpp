#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 1e9 + 7



ll expbin( ll a, ll exp, ll mod)
{
    if(exp == 0 )
        return 1;
    if( exp & 1)
        return (a * expbin(a, exp - 1, mod)) % mod;
    ll b = expbin(a, exp / 2, mod);
    return (b*b) % mod;
}





int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, a, b, c, r;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        ll r = expbin(b, c, MOD -1);
        cout << expbin(a, r, MOD) << endl;
    }
    
    return 0;
}