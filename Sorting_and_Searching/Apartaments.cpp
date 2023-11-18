#include <bits/stdc++.h>
using namespace std;


typedef long long ll;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> pessoas(n);
    vector <ll> apart(m);

    for(int i = 0; i < n; i++)
        cin >> pessoas[i];
    for(int i = 0; i < m; i++)
        cin >> apart[i];

    sort(pessoas.begin(), pessoas.end());
    sort(apart.begin(), apart.end());

    ll i = 0, j = 0;
    ll asn = 0;
    while(i < n)
    {
        while(j < m && apart[j] < pessoas[i] - k)
            j++;
        if(abs(apart[j] - pessoas[i]) <= k)
        {
            asn++;
            i++;
            j++;
        }
        else
            i++;
    }

    cout << asn;

    return 0;
}