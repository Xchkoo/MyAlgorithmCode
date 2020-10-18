#include<iostream>
using namespace std;

const int INF = 0x3ffff;

int n,m,x,y,z;//m=edgenumber n=pointnumber
bool book[5001];
int _map[5001][5001],dis[5001];
int _min,_minIndex;
int sum;
void prim()
{
	//先从第一个点开始
	for(int i = 1;i<=n;i++)
	{
		dis[i] = _map[1][i];
	}
	book[1] = 1;
	for(int i = 1;i<=n-1;i++)//开始循环 
	{
		_min = INF;
		for(int j = 1;j<=n;j++)
		{
			if(_min>dis[j]&&book[j] == 0)
			{
				_min = dis[j];
				_minIndex = j;
			}
		}
		book[_minIndex] = 1;
		sum += dis[_minIndex];//目的是求最小生成树的长度
		
		for(int j = 1;j<=n;j++)//求没被选上的
		{
			if(book[j] == 0 && _map[_minIndex][j] < dis[j])
				dis[j] = _map[_minIndex][j];	
		} 
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
		{
		if(i != j)
			_map[i][j] = INF;
		else
			_map[i][j]=_map[j][i] = 0;
		}
	for(int i = 1;i <= m;i++)
	{
		cin >> x >> y >> z;
		_map[x][y]=_map[y][x]=z;
	}
	prim();
	cout<<sum;
	return 0;
}

