#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
int head[N],tot,n,m,f[N],g[N],len;
struct edge
{
	int nxt,to,w;
}e[N<<1];
void add(int u,int v,int w)
{
	e[++tot]=(edge){head[u],v,w},head[u]=tot;
	e[++tot]=(edge){head[v],u,w},head[v]=tot;
}

void dfs(int u,int fa)
{
	f[u]=0;
	multiset<int>s;
	for(int i=head[u];i!=0;i=e[i].nxt)
	{
		int v=e[i].to,w=e[i].w;
		if(v==fa) continue;
		dfs(v,u);
		f[u]+=f[v];
		if(g[v]+w>=len) f[u]++;
		else s.insert(g[v]+w);
	}
	g[u]=0;
    while(!s.empty())
	{
        const int x=*s.begin();
        s.erase(s.begin());
        multiset<int>::iterator p=s.lower_bound(len-x);
        if(p==s.end()) g[u]=x;
		else s.erase(p),f[u]++;
    }
}
bool check(int k)
{
	len=k;
	dfs(1,0);
	return f[1]>=m;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	int l=1,r=5e8+5,res=-1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) res=mid,l=mid+1; 
		else r=mid-1;
	}
	cout<<res<<endl;
	return 0;
}