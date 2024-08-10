#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1123456
const int INF = 1e9;
 
 
 
ll n;
 
 
 
 
 
 
int lis(vector<ll> const& a) {
    int n = a.size();
    
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;
 
    for (int i = 0; i < n; i++) {
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l])
            d[l] = a[i];
    }
 
    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
 
 
 
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
 
    int a = lis(arr);
    cout << a << endl;
    
    return 0;
}