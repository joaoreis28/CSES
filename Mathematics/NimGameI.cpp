#include <bits/stdc++.h>
 
using namespace std;
#define MAX 212345
int arr[MAX];
 
/* Dado  as pilhas  A, vence se  a1 XOR a2 ... XOR an != 0 , Jogando perfeitamente*/
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t, resp = 0;
	cin >> t;
	while(t--)
	{
 
		cin >> n;
		resp = 0;
		for(int i = 0; i <  n; i++)
			cin >> arr[i];
		for(int i = 0; i < n; i++)
		{
			resp = arr[i] ^ resp;
		}
		if(resp == 0)
			cout << "second"<< endl;
		else
			cout << "first"<< endl;
	
	}
	return 0;
}