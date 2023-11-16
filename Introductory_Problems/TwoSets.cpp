#include <bits/stdc++.h>
using namespace std;


void solve_par(int n)
{
    set <int> p1;
    set <int> p2;
    int com = 1, fim = n, turno = 0;
    while( com < fim)
    {
        if( turno & 1)
        {
            p1.insert(com);
            p1.insert(fim);
        }
        else
        {
            p2.insert(com);
            p2.insert(fim);
        }
        
        turno++;
        com++;
        fim--;
    }
    cout << "YES" << endl;
    cout << p2.size() << endl;
    for (const auto& elemento : p2) {
        std::cout << elemento << " ";
    }
    cout << endl;
    cout << p1.size() << endl;
    for (const auto& elemento : p1) {
        std::cout << elemento << " ";
    }


}


void solve_impar(int n)
{
    set <int> p1;
    set <int> p2;
    int com = 1, fim = n - 1, turno = 0;
    while( com < fim)
    {
        if( turno & 1)
        {
            p1.insert(com);
            p1.insert(fim);
        }
        else
        {
            p2.insert(com);
            p2.insert(fim);
        }
        
        turno++;
        com++;
        fim--;
    }
    if(p2.size() < p1.size())
        p2.insert(n);
    if(p1.size() < p2.size())
        p1.insert(n);
    cout << "YES" << endl;
    cout << p2.size() << endl;
    for (const auto& elemento : p2) {
        std::cout << elemento << " ";
    }
    cout << endl;
    cout << p1.size() << endl;
    for (const auto& elemento : p1) {
        std::cout << elemento << " ";
    }


}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if( n % 4 == 0)
    {
        solve_par(n);
        return 0;
    }
    if(n & 1 && !( n % 4 == 1))
    {
        solve_impar(n);
        return 0;
    }    
    
    cout << "NO";  


    return 0;
}