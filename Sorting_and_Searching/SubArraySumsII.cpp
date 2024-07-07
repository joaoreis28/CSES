#include <bits/stdc++.h>
using namespace std;
 
#define MAX 512345
typedef long long ll;
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
 
vector<int> a(n);
 
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    ll prefix_sum = 0;
    ll resp = 0;
 
    map<ll, int> sums;
    sums[0] = 1;
 
    for(int b : a)
    {
        
 
        prefix_sum += b;
 
 
        resp += sums[prefix_sum - k];
        sums[prefix_sum]++;
 
 
 
 
 
    }
 
 
    cout << resp << endl;
 
    
    
 
    return 0;
}