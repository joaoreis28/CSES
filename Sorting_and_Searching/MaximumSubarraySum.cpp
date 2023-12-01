#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    ll best = -1e18;
    ll past = 0;

    for(int i = 0; i < n; i++)
    {
        if(past + arr[i] >= arr[i] )
            past += arr[i];
        else
            past = arr[i];
        best = max(best, past);
    }

    cout << best;


    return 0;
}