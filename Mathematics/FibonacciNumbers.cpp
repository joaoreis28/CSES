#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/*🐙🐙🐙🐙🐙🐙🐙🐙*/
#define MOD 1000000007
 
ll A[2][2] = {{0,1} , {1,1}};
ll B[2][2];
ll C[2] = {0,1};
ll D[2];
 
 
void multmat(ll x[][2], ll y[][2], ll xy[][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            xy[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                xy[i][j] += x[i][k] * y[k][j];
                xy[i][j] %= MOD;
            }
        }
    }
}
 
 
void multmato(ll x[][2], ll y[2], ll xy[2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            xy[i] = 0;
            for(int k = 0; k < 2; k++)
            {
                xy[i] += x[i][k] * y[k];
                xy[i] %= MOD;
            }
        }
    }
}
 
void expbin(ll x[][2], ll n, ll ans[][2])
{
 
    ll aux[2][2];
    if(n == 0)
    {
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
            ans[i][j] = i == j;
    }
 
    else if(n & 1)
    {
        expbin(x, n- 1, aux);
        multmat(x, aux, ans);
    }
    else
    {
        expbin(x, n/2, aux);
        multmat(aux, aux, ans);
    }
}
 
ll Fib(ll n)
{
    if( n <= 1)
        return n;
 
    expbin(A, n - 1, B);
    multmato(B, C, D);
 
    return D[1];
}
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll f;
    cin >> f;
    cout << Fib(f) << endl;
 
    return 0;
}