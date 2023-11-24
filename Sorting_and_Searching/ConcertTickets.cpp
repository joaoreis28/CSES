#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <int> tickts(n);
    vector <int> customers(m);
    set<pair<int,int>> sortedTickets;

    for(int i = 0; i < n; i++)
    {
        cin >> tickts[i];
        sortedTickets.insert({tickts[i], i});
    }
    for(int i = 0; i < m; i++)
        cin >> customers[i];


    for(int i = 0; i < m; i++)
    {
        auto match = sortedTickets.lower_bound({customers[i] + 1, 0});
        if(match == sortedTickets.begin())
            cout << -1 << endl;
        else
        {
            match--;
            cout << (*match).first << endl;
            sortedTickets.erase(match);

        }
    }








    return 0;
}