#include <bits/stdc++.h>
 
using namespace std;
#define MAX 212345
#define MAXI 1123456789

typedef long long ll;



ll v[MAX];
ll seg[4*MAX];
ll n, m, a, b;


ll build(ll p, ll l, ll r)
{
    if (l ==  r)
        return seg[p] = v [l];
    ll m = (l + r)/2;

    return seg[p] =  min(build(2*p, l, m), build(2*p +1, m+ 1, r));
}


ll query(ll a, ll b ,ll p, ll l, ll r)
{
    if( b < l || a > r)
        return MAXI;
    if( a <= l && b >= r)
        return seg[p] ;
    ll m = (l + r)/2;

    return min(query(a, b, 2*p, l, m), query(a, b, 2*p +1, m+ 1, r));
}


 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> v[i];

    build(1, 0, n-1);


    for(int i = 0; i< m; i++)
    {
        cin >> a >>b;
        cout << query(a - 1, b - 1, 1, 0, n -1) << endl;

    }
        
    
   
 
    
 
    return 0;
}
 /*
 8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3*/