#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, resp = 0, loop  =5;
    cin >>  n;
    

    while (n >= loop)
    {
        resp += n /loop;
        loop *= 5;
    }

    cout << resp << endl;


    return 0;
}