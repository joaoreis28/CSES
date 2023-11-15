#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



set<ll> conjunto;
int main()
{
    cin.tie();
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        conjunto.insert(x);
    }

    cout << conjunto.size() <<endl;
        
    return 0;
}

