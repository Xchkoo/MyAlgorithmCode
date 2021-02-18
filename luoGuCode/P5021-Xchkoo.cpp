/*
 * Copyright © 2021 Xchkoo. All rights reserved.
 *
 * AUTHOR: Xchkoo
 * DATE: 2021-01-17
 */
#include <iostream>
#include <set>
typedef long long ll;
typedef size_t s_t;
using namespace std;
const int N = 5e4+5;
const int THEMAXN = 5e8+5;
const int MINN = 1;
int n,m,f[N],g[N],len;
int head[N],tot;
struct edge{
    int next,to,w;
}e[N<<1];


void addedge(int u,int v,int w){
    e[++tot]=(edge){head[u],v,w},head[u]=tot;
	e[++tot]=(edge){head[v],u,w},head[v]=tot;
    //无向边存两条
}

void dfs(int u,int fa){
    f[u] = 0;
    multiset<int> s;
    for(int i = head[u];i != 0;i = e[i].next){
        int v = e[i].to,w = e[i].w;
        if(v == fa) continue;
        dfs(v,u);
        f[u] += f[v];
        if(g[v] + w >= len) f[u]++;
        else s.insert(g[v] + w);
    }
    g[u] = 0;
    while(!s.empty()){
        const int x = *s.begin();
        s.erase(s.begin());
        multiset<int>::iterator p = s.lower_bound(len - x);
        if(p == s.end())    g[u] = x;
        else s.erase(p),f[u]++;
    }
  }

bool check(int k){
    len = k;
    dfs(1,0);
    return f[1] >= m;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i<n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        addedge(u,v,w);
    }
    int l = MINN, r = THEMAXN,res = -1;
    while(l <= r){
        int mid = (l+r)>>1;
        if(check(mid))  res = mid,l = mid+1;
        else r = mid - 1;
    }
    cout << res << endl;
   return 0;
}
