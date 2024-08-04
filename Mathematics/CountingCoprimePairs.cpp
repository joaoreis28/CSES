#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MOD 1000000007
 
int n;
int num[1000001];
ll lpf[1000001],mobius[1000001];
 
 
void least_prime_factor()
{
    for(int i=2;i<1000001;i++)
    {
        if(!lpf[i])
        {
            for(int j=i;j<1000001;j+=i)
            {
                if(!lpf[j]) lpf[j]=i;
            }
        }
    }
}
 
void Mobius()
{
    for(int i=1;i<1000001;i++) 
    {
        if(i==1) mobius[i]=1;
        else 
        {
            if(lpf[i/lpf[i]]==lpf[i]) mobius[i]=0;
            else mobius[i]=-1*mobius[i/lpf[i]];
        }
    }
}
 
 
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n;
    int vec[n];
    for(int i = 0; i < n;i++)
    {
        cin >> vec[i];
        num[vec[i]]++;
 
    }
 
 
    least_prime_factor();
    Mobius();
    ll ans=0;
    for(int i=1;i<1000001;i++)
    {
        if(mobius[i]==0) continue;
        ll d=0;
        for(int j=i;j<1000001;j+=i)
        {
            d+=num[j];
        }
        ans+=(d*(d-1))/2*mobius[i];
    }
    cout<<ans;
        
 
 
    
   return 0;
}