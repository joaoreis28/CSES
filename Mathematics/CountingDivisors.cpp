#include <bits/stdc++.h>
using namespace std;


int solve(int n)
{
    vector<int> pots;
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            int t = 0;
            while(n % i == 0)
            {
                t++;
                n /= i;
            }
            pots.push_back(t);
        }       
        
    }
   if( n != 1)
        pots.push_back(1);
    int ans = 1;
    for(int z : pots)
    {
        ans = ans * (z + 1);
    }

    return ans;
}




int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, x;
    cin >> n;
    while(n--)
    {
        cin >> x;
        cout << solve(x) << endl;
    }
    
    
    
    return 0;
}