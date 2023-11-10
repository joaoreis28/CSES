#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



ll resolve(ll n, ll k)
{
    if(n == 1)
        return 1;

    if(k <= (n+ 1)/2)
    {
        if(2*k > n)
            return (2*k) % n;
        else
            return 2*k;
    }

    ll temp=resolve(n/2,k-(n+1)/2);
    if(n & 1)
        return 2*temp+1;
    return 2*temp-1;
        
}





int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int q;
    ll n , k;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cout << resolve(n, k) << endl;
    }
   


    


    return 0;
}