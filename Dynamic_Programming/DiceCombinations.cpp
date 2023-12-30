#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector <ll> combinations(n+1, 0);
    combinations[0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 6; j++)
            if(i -j >= 0)
                combinations[i] = (combinations[i] + combinations[i - j]) % MOD;

    cout<< combinations[n];
    return 0;
}