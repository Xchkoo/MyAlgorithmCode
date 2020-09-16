#include<iostream>
#include<string>
using namespace std;
#define MAXNUM 100000
int p1[MAXNUM],p2[MAXNUM];
int n;
int f[MAXNUM][MAXNUM];
int main()
{
	cin >> n;
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	for(int i = 1;i <= n;i++)
		cin >> p1[i];
	for(int i = 1;i <= n;i++)
		cin >> p2[i];
//input
	for(int i = 0;i <= n;i++)
	{
		for(int j = 0;j <= n;j++)
		{
			if(i == 0 || j == 0)	f[i][j] = 0;
			else if(p1[i] == p2[i])	f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j],f[i][j - 1]);
		}
	}
	
	cout << f[n][n] <<endl;
	return 0;
}

