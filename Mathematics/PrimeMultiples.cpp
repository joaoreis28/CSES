#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n;
    int k;
    cin >> n >> k;
    vector<ll> primos(k);
    for (int i = 0; i < k; i++)
        cin >> primos[i];

    vector<ll> contribuicoes(k + 1);
    for (int mask = 1; mask < (1 << k); mask++)
    {
        int nDivisors = 0;
        ll tmp = n;
        for (int i = 0; i < k; i++)
        {
            if ((1 << i) & mask)
            {
                nDivisors++;
                tmp /= primos[i];
            }
        }
        contribuicoes[nDivisors] += tmp;
    }

    ll resp = 0;
    for (int i = 1; i <= k; i++)
    {
        if (i % 2 == 0)
            resp -= contribuicoes[i];
        else
            resp += contribuicoes[i];
    }
    cout << resp << endl;

    return 0;
}