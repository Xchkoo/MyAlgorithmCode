#include<iostream>
using namespace std;
#define MAX 100000
int dis[MAX];head[MAX];
struct edge{
	int next,to,value;
};
edge e[MAX<<1];
int n,m,s;
int main()
{
	cin >> n >> m >> s;
	for(int i = 1;i<=m;i++)
	{
		int n,t,v,k;
		cin>>k;
		cin >> e[i].next >> e[i].to >> e[i].value;
		head[k] = edge[i];
	}
	// ‰»Î 
	return 0;
}
