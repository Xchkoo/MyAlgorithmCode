#include<iostream>
#include<set>
using namespace std;
const int N = 10e5 + 5;
const int MAXN = 10e8+5;
int n,m,cnt,len,f[N],g[N];
int head[N];
struct edge{
    int next,to,w;
}e[N<<1];
void addedge(int u,int v,int w){
    e[++cnt] =(edge){u,v,w}; 
    e[++cnt] =(edge){v,u,w};
}
int dfs(int u,int fa){
    multiset<int> s;
    f[u] = 0;
    for(int i = head[u];i!=0;i = e[u].next){
        int v = e[i].to,w=e[i].w;
    dfs(v,u);
    f[u] += f[v];
    if(g[v] + w >= len) f[u]++;
    else s.insert(g[v] + w);
    }
    g[u] = 0;
    while(!s.empty()){
        int x = *s.begin();
        s.erase(s.begin());
        multiset<int>::iterator it = s.lower_bound(len - x);
        if(it == s.end())  g[u] = x;
        else f[u]++;
    }
}
bool check(int k){
    len = k;
    dfs(1,0);
    return f[1] > m;
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        addedge(u,v,w);
    }
    int l = 1,r = MAXN,res = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid))  {res = mid;l = mid + 1;}
        else r = mid - 1;
    }
    cout << res;
    return 0;
}
