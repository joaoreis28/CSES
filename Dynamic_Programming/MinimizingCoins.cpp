#include <bits/stdc++.h>
using namespace std;
#define MAX 1e7

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int x, n;
    cin >> n >> x;
    vector<int> coins(n);
    vector<int> ans(x + 1, MAX);

    for(int i = 0; i < n; i++)
        cin >> coins[i];

    ans[0] = 0;
    for(int i = 1; i <= x; i++)
        for(int j = 0; j < n; j++)
            if(i - coins[j] >= 0)
                ans[i] = min(ans[i], ans[i - coins[j]] + 1);
    
    cout << (ans[x] == MAX ? -1 : ans[x]);

    return 0;
}