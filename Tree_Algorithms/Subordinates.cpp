#include <bits/stdc++.h>
using namespace std;


#define MAX 212345

vector<vector<int>> Ladj(MAX);
vector <int> subar (MAX);

int calc( int node)
{
    if(Ladj[node].size() == 0)
        return 1;
    else
    {
        for(int i = 0; i < Ladj[node].size(); i++)
        {
            subar[node] += calc(Ladj[node][i]);
        }

    }
    return subar[node] + 1;
}




int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);


    int n;
    cin >>  n;
    for(int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        Ladj[a].push_back(i);

    }
    calc(1);
    for(int i = 1; i <= n; i++)
        cout << subar[i] << " ";


    return 0;
}