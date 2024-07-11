#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll expbin( ll a, ll exp)
{
    if(exp == 0 )
        return 1;
    if( exp & 1)
        return (a * expbin(a, exp - 1)) ;
    ll b = expbin(a, exp / 2);
    return (b*b) ;
}



void query(ll a)
{
    ll d = 1, b = 9;

    while( a -  d * b > 0)
    {
        a -=d *b;
        b *=10;
        d++;
    }
    ll index = a % d;

    ll asw = expbin(10, (d - 1)) + (a - 1) / d;

    
    if (index != 0)
        asw = asw / expbin(10, d - index);

    cout << asw % 10 << endl;
}


int main()
{
    cin.tie();
    ios_base::sync_with_stdio(0);

    ll q, x;
    cin >> q;
    while(q--)
    {
        cin >> x;
        query(x);

    }

    return 0;
}



