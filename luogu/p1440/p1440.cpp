#include<iostream>
using namespace std;
#define NUMMAX 30000000
int n,m,a[NUMMAX];

void minx(int x);

int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	a[0] = 0;
	for(int i = 1;i <= n;i++)
		minx(i);
	return 0;
}

void minx(int x)
{
	if(x == 1)
		cout<<"0"<<endl;
	else
	{
	int minNum = a[x];
	for(int i = 1;i <= m||x - i > 0;i++)
	{
		minNum = min(a[x - i],minNum);
	}
	cout<<a[minNum]<<endl; 
	}
}
