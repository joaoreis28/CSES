#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
string m;
 
string solve()
{
    int n = m.length();
    string resp(n, ' ');
 
    int freq[26] = {};
    for(int i = 0; i < n; i++)
        freq[m[i] - 'A'] += 1;
 
 
    int impar = 0;
    for(int i = 0; i < 26; i++)
        if(freq[i] & 1)
            impar++;
 
 
    if(impar > 1)
        return "NO SOLUTION";
 
    int esq = 0, dir = n -1;
 
    for(int i = 0 ; i < n; i++)
    {
        if(freq[m[i] - 'A'] % 2 == 1)
        {
            resp[n/2] = m[i];
            freq[m[i] - 'A'] -= 1;
        }
        while(freq[m[i] - 'A'] > 0)
        {
            resp[esq++] = resp[dir--] = m[i];
            freq[m[i] - 'A'] -= 2;
        }
            
        
    }
 
    return resp;
    
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> m;
 
    cout << solve() << endl;
 
    
    
 
    return 0;
}
 