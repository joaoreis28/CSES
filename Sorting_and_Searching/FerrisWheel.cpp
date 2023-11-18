#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll x, n, ans = 0;
    cin >> n >> x;
    vector<ll> kids(n);
    for(int i = 0; i < n; i++)
        cin >> kids[i];
    sort(kids.begin(), kids.end());

    ll l =0, d = n -1;
    while( l <= d)
    {
        if(kids[l] + kids[d] <= x )
        {
            l++;
            d--;
            ans++;
        }
        else
        {
            ans++;
            d--;
        }

    }

    cout << ans<< endl;
    return 0;
}

