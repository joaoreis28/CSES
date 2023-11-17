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

    ll n, a, b;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        cout << expbin(a, b) << endl;
    }
    
    return 0;
}