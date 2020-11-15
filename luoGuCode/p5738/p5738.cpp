#include<iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int n,m;
double ans[102];
struct grade{
public:
	int grade[102];
	int findminx(int number){
		int minx,minindex;
		for(int i = 1;i <=number;i++)
		{
			if(minx > grade[i])
			{	
				minx = grade[i];
				minindex = i;
			}
		}
		return minindex;
	}
	int findmaxx(int number){
		int maxx,maxindex;
		for(int i = 1;i <=number;i++)
		{
			if(maxx < grade[i])
			{	
				maxx = grade[i];
				maxindex = i;
			}
		}
		return maxindex;
	}
} students[102];
int main()
{
	std::ios::sync_with_stdio(0);
	cin >> n >> m;
	
	for(int j = 1;j<=n;j++)
		for(int i = 1;i<=m;i++)
		{
			cin >> students[j].grade[i];
		}
	for(int j = 1; j <= n;j++)
	{
		for(int i = 1;i <= m;i++)
		{
			if(i == students[j].findmaxx(m)||i == students[i].findminx(m))
				continue;
			ans[j] += students[j].grade[i];
		}
		ans[j]= (double)ans[j]/(j-2);
	}
	int _max = 0;
	for(int i = 1;i<=n;i++)
	{
		if(_max < ans[i])
			_max = ans[i];
	}
	
	cout<<fixed<<showpoint;
	cout<<setprecision(1)<<_max;
	return 0;
}
