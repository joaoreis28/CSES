#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;

    while(n != 1)
    {
        cout << n << " ";
        if(n & 1)
            n = n * 3 + 1;
        else
            n = n / 2;
    }
    cout << 1;
    return 0;
}