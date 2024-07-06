#include <bits/stdc++.h>
 
using namespace std;
 
 
 
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
   int n;
   cin >> n;
 
   vector<string> gray;
 
   gray.push_back("0");
   gray.push_back("1");
 
 int i, j;
    for (i = 2; i < (1<<n); i = i<<1)
    {
        
        for (j = i-1 ; j >= 0 ; j--)
            gray.push_back(gray[j]);
 
        
        for (j = 0 ; j < i ; j++)
            gray[j] = "0" + gray[j];
 
        for (j = i ; j < 2*i ; j++)
            gray[j] = "1" + gray[j];
    }
 
    
    for (i = 0 ; i < gray.size() ; i++ )
        cout << gray[i] << endl;
 
    
    
 
    return 0;
}
 
 