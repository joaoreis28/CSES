#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, total=0, ans=INT_MAX;
	cin >> n;

	ll v[n];
	for(ll i = 0; i < n; i++) {
		cin >> v[i];
		total += v[i];
	}
	for(ll i = 0; i < 1<<n; i++) {
		ll s = 0;
		for(ll j = 0; j < n; j++) {
			if(i & 1<<j) s += v[j];
		}
		ll curr = abs((total-s)-s);
		ans = min(ans, curr);
	}
	cout << ans;
	return 0;
}