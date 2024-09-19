#include<iostream>
#define MAXN 1000
using namespace std;
int n;
int arr1[MAXN],arr2[MAXN],dp[MAXN][MAXN];
    
int main(){
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> arr1[i];
    for(int i=1;i<=n;i++)
        cin >> arr2[i];
    //input
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr1[i] == arr2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout << dp[n][n] << endl;
    
    return 0;
}

/* 
由于空间复杂度过高需要离散化的方法
    for(int i=1;i<=n;i++)
    {
        if(belong[a2[i]]>b[len])
        {
            b[++len]=belong[a2[i]];
            f[i]=len;
            continue;
        }
        int k=lower_bound(b+1,b+len+1,belong[a2[i]])-b;
        b[k]=belong[a2[i]];
        f[i]=k;
    }
 */