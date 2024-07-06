#include <bits/stdc++.h>
using namespace std;
#define MAX 212345
typedef pair<int, int> ii;
 
int v[MAX];
int p[MAX];
pair<int, int>  seg[4*MAX];
 
pair<int, int> build(int p, int l, int r)
{
    if(l == r)
        return seg[p] = {v[l], l +1};
    int m = (l+r)/2;
 
    return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
}
 
 
 
int query1(int p, int l, int r, int num)
{
    if(seg[p].first < num)
        return 0;
    if(l == r)
    {
        seg[p].first = seg[p].first - num;
        return seg[p].second;
    }
    int m = (l+r)/2;
 
    if(seg[2* p].first >= num)//esq
    {
        int y = query1(2*p,l,m,num );
        if(seg[2* p].first >= seg[2* p + 1].first)
            seg[p] = seg[2*p];
        else
            seg[p] = seg[2*p + 1];
        return y;
    }
    else
    {
         int y = query1(2*p + 1,m + 1,r,num );
        if(seg[2* p].first >= seg[2* p + 1].first)
            seg[p] = seg[2*p];
        else
            seg[p] = seg[2*p + 1];
        return y;   
 
    }
 
 
    return max(query1(2*p, l ,m,num), query1( 2*p +1, m+ 1,r, num));
}
 
 
 
 
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a;cin >> a;
        v[i] = a;
    }
    for(int i = 0; i < m; i++)
    {
        int a;cin >> a;
        p[i] = a;
    }
    build(1,0,n-1);
 
    for(int i = 0; i < m; i++)
    {
        cout << query1(1,0, n-1, p[i]) << " ";
    }
 
 
    return 0;
 
}