#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000000007


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
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, ans = 0;
    cin >> n;
    for(ll i = 1, j; i <= n; i = j)
    {
        ll q = n/i;
        j = n/q + 1;
        ll rangeGaussJminus1 = ((((j % MOD)*((j - 1)%MOD))%MOD)*expbin(2, MOD -2))%MOD;
        ll rangeGaussIminus1 = ((((i % MOD)*((i - 1)%MOD))%MOD)*expbin(2, MOD -2))%MOD;
        ll rangeQuotient = (rangeGaussJminus1 - rangeGaussIminus1 + MOD) % MOD;
        ans = (ans +(q % MOD) * rangeQuotient) % MOD;
    }

    cout << ans << endl;

    return 0;
}