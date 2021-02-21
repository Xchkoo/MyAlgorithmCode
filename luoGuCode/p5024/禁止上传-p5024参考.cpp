#include <iostream>

#include <cstdio>

#include <vector>

#include <cstring>



#define ll long long

using namespace std;



const int MAXN = 100005;

int n, m;

char type[100];



int head[MAXN];//值为边表的下标



struct Edge

{

	int to,next;

	Edge(int a=0, int b=0)

	{

		to = a;

		next = head[b];	

	}

}e[MAXN<<1];



int val[MAXN]; 

int cnt;



struct Rest{

	int node1;

	int val1;

	int node2;

	int val2;	

}rest[MAXN];//初始化为2,0表示不取；1表示取。 



int vis[MAXN];



void Read()

{

	int a,b;

	//cin >> n >> m >> type;

	scanf("%d%d%s", &n,&m,type);	

	for(int i=1;i<=n; ++i)

	{

		//cin >> val[i];

		scanf("%d", &(val[i]));	

	} 

	

  	for(int i=1;i<=(n-1); ++i)

  	{

  		//cin >> a >> b;

  		scanf("%d%d", &a,&b);

		e[++cnt] = Edge(a,b); 

		head[b] = cnt;

		

		e[++cnt] = Edge(b,a); 

		head[a] = cnt;

	

	}

	int x,y;



	for(ll i=1; i<=m; ++i)

	{

		//cin >> a >> x >> b >> y;

		scanf("%d%d%d%d", &a,&x,&b,&y);

		rest[i].node1 = a;

		rest[i].val1 = x;		

		rest[i].node2 = b;		

		rest[i].val2 = y;

	}

	 

}



ll f[MAXN][2];



//f[i][0] 标识选择i节点； f[j][1]标识为选择j节点。 



ll dfs(int v, int u, int loop)

{

	

	if ((vis[u]==0) && (vis[v]==0)) 

	{

		return -1;

	}

	

	f[v][0] = 0; //标识当前V节点不选择的情况。

	f[v][1] = val[v]; 



	for (int i=head[v]; i; i=e[i].next)

	{

	
		int y = e[i].to;

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





int main()

{

	Read();

	

	for(int i=1;i<=m;++i)

	{	

		trans(i);

		ll res = dfs(1,0,i);

	   

		//cout << res << endl;

		printf("%lld\n",res);

	}

	return 0;

	

}