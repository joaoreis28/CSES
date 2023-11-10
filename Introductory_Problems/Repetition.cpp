#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int m = 0, curr = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] != s[i - 1])
        {
            m = max(m, curr);
            curr = 0;
        }
        curr++;
    }
    m = max(m, curr);

    cout << m << endl;

    return 0;
}