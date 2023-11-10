#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
typedef long long ll;

ll v[MAX];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n, a, pri, resp = 0;
    ll ant, atual;

    cin >> n;
    cin >> pri;
    ant = pri;
    for(int i = 1; i < n;i++)
    {
        cin >> a;
        atual = a;
        if(atual < ant)
        {
            resp =  resp +(ant - atual);
        }
        else  
            ant = atual;
    }

    cout << resp;

    return 0;
}