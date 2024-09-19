#include<iostream>
using namespace std;
int n;
long long dp[5005][5005];
int main()
{
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<=n+n;i++)
	{
		for(int j=0;j<=n&&j<=i;j++)
		{
			if(j-1>=0)
				dp[i][j]+=dp[i-1][j-1];
			if(j+1<=i+1)
			dp[i][j]+=dp[i-1][j+1]; 
		}
	}
	cout<<dp[n+n][0];
	return 0;
}	
