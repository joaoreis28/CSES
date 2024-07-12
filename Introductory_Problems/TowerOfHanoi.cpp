#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
/*🦛🦛🦛🦛🦛🦛🦛*/
 
 
void solve(int n, int p1, int p2, int p3)
{
    
    if( n == 0)
        return ;
    solve(n -1, p1,p3, p2);
 
    cout << p1 << " " << p3 << endl;
    solve(n -1, p2,p1, p3);
}
 
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
 
    solve(n , 1, 2,3);
 
    return 0;
}