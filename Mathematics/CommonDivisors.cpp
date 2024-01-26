#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> v(1e6+1, 0);

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >>x;
        v[x]++;
    }

    for(int gcd = 1e6; gcd >= 1; gcd--)
    {
        int counter = 0;
        for(int j = gcd; j <= 1e6; j += gcd)
            counter += v[j];
        if(counter > 1)
        {
            cout <<gcd;
            return 0;
        }
    }


    return 0;
}