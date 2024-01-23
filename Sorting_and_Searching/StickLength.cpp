#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;

    vector <ll> sticks(n);

    for(int i= 0; i <n; i++)
        cin >> sticks[i];

    sort(sticks.rbegin(), sticks.rend());
    
    int ss;
    if(n & 1)
        ss = sticks[(n-1)/2];
    else
        ss = sticks[n/2];
    ll ans = 0;
 
    for(int i = 0; i < n; i++)
    {
        ans += abs(sticks[i] - ss);
    }
    cout << ans;
    return 0;
}