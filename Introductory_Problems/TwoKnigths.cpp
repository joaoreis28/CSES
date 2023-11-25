#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for(ll i  = 1; i <= n; i++)
    {
        ll a = ((i*i) * (i*i - 1)) / 2;
        ll b = 2 * ( (i - 1) * (i - 2) + (i - 1) * (i - 2)  );
        cout << a -b << endl;
    }



    return 0;
}