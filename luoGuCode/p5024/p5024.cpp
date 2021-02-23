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
#include <cstring>//for memset
using namespace std;
int n,m;
string __type_info;
int cnt;
typedef long long ll;
typedef size_t s_t;
const int MAXN = 10e5;
int head[MAXN];
ll f[MAXN][2];
int val[MAXN];
struct node {
    int nxt,to;
} edge[MAXN<<1];
void addEdge(int u,int v) {
    edge[cnt].nxt = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
    cnt++; 
}
int vis[MAXN];
struct Rest{
	int node1;
	int val1;
	int node2;
	int val2;	
}rest[MAXN];//初始化为2,0表示不取；1表示取。 


int min(int a,int b){
    if(a < b)   return a;
    else    return b;
}
void trans(int id)
{
	memset(vis,2,sizeof(vis));
	int a = rest[id].node1;
	int b = rest[id].node2;
	int x = rest[id].val1;
	int y = rest[id].val2;
	vis[a] = x;
	vis[b] = y;

}


ll dfs(int v, int u, int loop)

{

	

	if ((vis[u]==0) && (vis[v]==0)) 

	{

		return -1;

	}

	

	f[v][0] = 0; //标识当前V节点不选择的情况。

	f[v][1] = val[v]; 



	for (int i=head[v]; i; i=edge[i].nxt)

	{
		int y = edge[i].to;
	    if (y == u) continue;
		if (dfs(y,v,loop) < 0)
		{
			return -1;
		} 
	    f[v][0] += f[y][1];
		if (vis[y] == 0) 
		{
			f[v][1] = f[v][1] + f[y][0];
			vis[v] = 1; //碰到一个儿子节点如此，则父节点必须为1； 
		}
		else if (vis[y] == 1) 
		{
			f[v][1] = f[v][1] + f[y][1];
		}
		else
		{
			f[v][1] = min(f[v][1] + f[y][0],f[v][1] + f[y][1]);
	    }
	}
	if (vis[v]==1) 
	{
		return f[v][1];
	}
	else if(vis[v] == 0) 
	{
		return f[v][0];	
	}
	else return min(f[v][0],f[v][1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin >>  n >> m;
    cin >>  __type_info; //num
    for(int i = 1;i <= n;i++) { //head
        cin >> head[i];
    }

    int a,b;
    for(int i = 1;i < n;i++) { //edge
        
        cin >> a >> b;
        addEdge(a,b),addEdge(b,a);
    }

    int x,y;
    for(int j = 1;j <= m;j++) {
        cin >> a >> x >> b >> y;
        rest[j].node1 = a;
		rest[j].val1 = x;		
		rest[j].node2 = b;		
		rest[j].val2 = y;
    }
    for(int i=1;i<=m;++i) {	
		trans(i);
		ll res = dfs(1,0,i);
		cout << res << endl;

	}
    return 0;
}
