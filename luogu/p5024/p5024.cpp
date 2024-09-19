/*
 * © Copyright 2021 Xchkoo All rights reserved.
 *
 * AUTHOR: Xchkoo
 * DATE: 2021-02-20
 * LISENSE: CC v4.0 BY-SA https://creativecommons.org/licenses/by-sa/4.0/deed.zh
 * Remark: Thanks for viewing XD
 * Welcome to my blog -> Xchkoo.top
 */
#include <iostream>
#include <cstdio>
#include <cstring> //memset
#define ll long long
using namespace std;
const int MAXN = 10e5 + 5;
int n, m;
char type[100];
int head[MAXN];
struct Edge{
	int to,nxt;
	Edge(int a=0, int b=0){
		to = a;
		nxt = head[b];	
	}
}e[MAXN<<1];

int val[MAXN], cnt;

struct Rest{
	int node1;
	int val1;
	int node2;
	int val2;	
}rest[MAXN];//初始化为2,0表示不取；1表示取。 

int vis[MAXN];

ll f[MAXN][2];

ll dfs(int v, int u)
{
	if ((vis[u]==0) && (vis[v]==0)) return -1;
	f[v][0] = 0; 
	f[v][1] = val[v];
	for (int i=head[v];i;i=e[i].nxt){
		int y = e[i].to;
	    if (y == u) continue;
		if (dfs(y,v) < 0)   return -1;
	    f[v][0] += f[y][1];	
		if (vis[y] == 0) {
			f[v][1] = f[v][1] + f[y][0];
			vis[v] = 1; //碰到一个儿子节点如此，则父节点必须为1；
        }
		else if (vis[y] == 1) 
			f[v][1] = f[v][1] + f[y][1];
		
		else
			f[v][1] = min(f[v][1] + f[y][0],f[v][1] + f[y][1]);
	     
	}
	if (vis[v]==1) 
		return f[v][1];
	else if(vis[v] == 0) 
		return f[v][0];	
	else return min(f[v][0],f[v][1]);    
}
	    

void trans(int id){
	memset(vis,2,sizeof(vis));
	int a = rest[id].node1;
	int b = rest[id].node2;
	int x = rest[id].val1;
	int y = rest[id].val2;
	vis[a] = x;
	vis[b] = y;
}
int main(){
		int a,b;
	//cin >> n >> m >> type;
	scanf("%d%d%s", &n,&m,type);	
	for(int i=1;i<=n; ++i)

	{	
		scanf("%d", &(val[i]));	
	} 

  	for(int i=1;i<=(n-1); ++i)
  	{
  		scanf("%d%d", &a,&b);
		e[++cnt] = Edge(a,b); 
		head[b] = cnt;

		e[++cnt] = Edge(b,a); 
		head[a] = cnt;
	}

	int x,y;
	for(ll i=1; i<=m; ++i)
	{
		scanf("%d%d%d%d", &a,&x,&b,&y);
		rest[i].node1 = a;
		rest[i].val1 = x;
		rest[i].node2 = b;		
		rest[i].val2 = y;
	}
	for(int i=1;i<=m;++i)
	{	
		trans(i);
		ll res = dfs(1,0);
		cout << res << endl;
	}

	return 0;

	

}
