#include<iostream>
using namespace std;
int N, C;
struct item
{
    int c, w;
}Item[1005];
/*
* 1.设计状态：dp[i][j],表示从第1个到第i个物品进行选取物品并装入容积为j的背包中的最大价值、
* 2.设计状态转移方程：
* { 
*   情况1：背包连一个物品i都放不下
*   {
*     dp[i][j]=dp[i-1][j]
    }
    情况2：背包可以放下物品i
    {
      1.可以选择不放：dp[i][j]=dp[i-1][j]
      2.选择放
      {
        进行比较dp[i][j]=max(dp[i-1][j],dp[i-n][j-n*c]+n*w)
      }
    }
* }
*/
int dp[1005][1005];
int main()
{
    cin >> N >> C;
    for (int i = 1; i <= N; i++)cin >> Item[i].c >> Item[i].w;
    for(int i=1;i<=N;i++)
        for (int j = 0; j <= C; j++)
        {
            if (i == 1)dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j];//表示不放入第i个物品
            //表示要放入第i个物品，但不确定放入的数量
            for (int k = 0; k * Item[i].c <= j; k++)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * Item[i].c] + k * Item[i].w);
            }
        }
    cout << dp[N][C];
    return 0;
}