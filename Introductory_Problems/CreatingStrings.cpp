#include <bits/stdc++.h>
using namespace std;


set<string> possi;  



int main()
{
    cin.tie();
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    do
    {
        possi.insert(s);
    }while(next_permutation(s.begin(), s.end()));


    cout << possi.size() << endl;
    for(auto i : possi)
        cout << i << endl;

    return 0;
}