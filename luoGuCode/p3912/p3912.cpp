#include<iostream>
#include<string.h>
using namespace std;
#define MAXN 100000005

bool isPrime[MAXN];
int n,ans = 0;

int main()
{
	cin >> n;
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0] = 0;
	isPrime[1] = 0;
	for(int i = 2;i*i<=n;i++)
	{
		if(isPrime[i] == 1)
		{
			for(int j = i*i;j<=n;j+=i)
			{
				isPrime[j] = 0;		
			}
		}
	}
	for(int i =1;i<=n;i++)
	{
		if(isPrime[i] == 1)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
