#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,x;
    cin >> n >> x;
    map<int, int> arr;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(arr.count(x - a))
        {
            cout << arr[x -a]  << " " << i + 1 << endl;
            return 0;
        }
        arr[a] = i + 1;
        
    }

    cout << "IMPOSSIBLE" << endl;
        




    return 0;
}