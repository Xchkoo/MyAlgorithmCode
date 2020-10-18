#include<cstdio>
#include<iostream>
using namespace std;
int _generalEdgeLength;
bool b[5001];
int ans=0,dis[5001],w[5001][5001],x,y,z,n,m;
void Prim(){
        for(int i=0;i<=n;i++) dis[i]=w[1][i];
        dis[1]=0;
        b[1]=true;
        for(int i=1;i<n;i++){
                int k=0;
                for(int j=1;j<=n;j++)
                        if(!b[j]&&dis[j]<dis[k]) k=j;
                b[k]=true;
                ans+=dis[k];
                for(int j=1;j<=n;j++){
                        if(dis[j]>w[k][j])
                                dis[j]=w[k][j];
                }
        }
        printf("%d\n",_generalEdgeLength-ans);
}
int main(){
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++){
                for(int j=i+1;j<=n;j++)
                        w[i][j]=w[j][i]=0x7fffffff;
                w[i][i]=0;
        }
        while(m--){
                scanf("%d %d %d",&x,&y,&z);
                _generalEdgeLength+=z;
                w[x][y]=w[y][x]=min(w[x][y],z);
        }
        Prim();
        return 0;
}
