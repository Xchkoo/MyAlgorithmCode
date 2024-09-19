#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;
#define MAXN 100
struct item{
    int w,v;
} Item[MAXN];
int dp[MAXN];

int n,m;

int main(){
    memset(dp,0,sizeof(dp)); // format array
    cin >> n >> m;
    
    for(int i=1;i<=n;i++){
        cin >> Item[i].w >> Item[i].v;
    } // input
    
    for(int i=1;i<=n;i++){
        for(int j=m;j>=Item[i].w;j--){
            dp[j] = max(dp[j],dp[j-Item[i].w]+Item[i].v);
        }
    } // dp

    cout << dp[m] << endl;
    return 0;
}