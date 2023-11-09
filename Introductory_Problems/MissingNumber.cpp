#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, a;
    cin >> n;
    
    ll soma = (n * (1 + n))/ 2;

    for(int i = 1; i < n; i++)
    {
        cin >> a;
        soma = soma - a;
    }

    cout << soma;

    return 0;
}