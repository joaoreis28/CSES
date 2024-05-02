#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int resp = 0;
    string nn, p, real;
    cin >> nn;
    cin >> p;
    int tam_p = p.size();
    
 
    real = p + "$" + nn;
    int tam_real = real.size();
 
    vector<int> z(tam_real);
    int x = 0, y = 0;
    
    for (int i = 1; i < tam_real; i++)
    {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < tam_real && real[z[i]] == real[i + z[i]])
        {
            x = i;
            y = i + z[i];
            z[i]++;
        }
    }
    for (int i = 0; i < tam_real; i++)
        if(z[i] == tam_p)
            resp++;
 
    cout << resp;
 
    return 0;
}