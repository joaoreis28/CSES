#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007
 
#define MAX 100
 
double dp[MAX + 1][ 6 * MAX + 1];
 
double resp;
 
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll a, b, n;
 
    cin >> n >> a >> b;
 
    dp[0][0] = 1;
 
 
    for(int i = 1 ; i<= n; i++)
    {
        for(int j = 1 ; j<= 6 * MAX; j++)
        {
            for(int k = 1 ; k<= 6; k++)
                if(j - k >= 0)
                    dp[i][j] += dp[i-1][j -k ]/6;
        }
    }
 
    for(int i = a; i <= b; i++)
        resp += dp[n][i];
 
 
    
    cout << fixed << setprecision(6) << resp << endl;
 
    return 0 ;  
}