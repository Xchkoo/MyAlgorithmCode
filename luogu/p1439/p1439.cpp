#include<iostream>
#include<string>
#define MAXNUM 100005
using namespace std;
int n;
int p1[MAXNUM],p2[MAXNUM];
int f[MAXNUM];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
    while ('0'<=ch && ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
int main()
{
	n = read();
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	for(int i = 1;i <= n;i++)
		p1[i] = read();
	for(int i = 1;i <= n;i++)
		p2[i] = read();
		for(int i = 0;i <= n;i++)
		{
			for(int j = 0;j <= n;j++)
			{
				if(i == 0 || j == 0)	f[j] = 0;
				else if(p1[i] == p2[j])	f[j] = f[j - 1] + 1;
				else if(p1[i] != p2[j])f[j] = max(f[j - 1],f[j]);
			}
		}
		
		cout << f[n] << endl;
		return 0;
}
