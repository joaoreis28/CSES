#include <bits/stdc++.h>
using namespace std;
/*🐙🐙🐙🐙🐙🐙🐙🐙*/

typedef long long ll;
#define MOD 1000000007

ll A[6][6] = {{1,1,1,1,1,1}, {1,0,0,0,0,0}, {0,1,0,0,0,0}, {0,0,1,0,0,0}, {0,0,0,1,0,0}, {0,0,0,0,1,0}};
ll p[6] = {32,16,8,4,2,1};
ll B[6][6];
ll D[6];



void multmat(ll x[][6], ll y[][6], ll xy[][6])
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            xy[i][j] = 0;
            for(int k = 0; k < 6; k++)
            {
                xy[i][j] += x[i][k] * y[k][j];
                xy[i][j] %= MOD;
            }
        }
    }
}



void multmato(ll x[][6], ll y[6], ll xy[6])
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            xy[i] = 0;
            for(int k = 0; k < 6; k++)
            {
                xy[i] += x[i][k] * y[k];
                xy[i] %= MOD;
            }
        }
    }
}



void expbin(ll x[][6], ll n, ll ans[][6])
{
 
    ll aux[6][6];
    if(n == 0)
    {
        for(int i = 0; i < 6; i++)
            for(int j = 0; j < 6; j++)
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







void Dice(ll n)
{
    expbin(A,n, B);
    multmato(B,p,D);
    cout << D[5] << endl;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;

    cin >> n;
    Dice(n - 1);


    /*A ^ n-1 * P   Matrix Exponentiation */

   



    return 0;
}