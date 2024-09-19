#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[35];
int n,v,value[35];
int main()
{
	cin >> v >> n;
	for(int i = 1;i <= n;i++)
		cin >> value[i];
	for(int i =  1;i <= n;i++)
		for(int j = v;j >= value[i];j--)
		{
			f[j] = max(f[j] , f[j - value[i]] + value[i]);
		}
	cout<<v - f[v];
	return 0;
}
