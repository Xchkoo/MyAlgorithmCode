#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;
/*最小生成树Prim未优化版*/

int book[100];//用于记录这个点有没有被访问过
int dis[100];//用于记录距离树的距离最短路程
const int MAX = 0x3ffff;//边界值
int maps[100][100];//用于记录所有边的关系

int main()
{
    std::ios::sync_with_stdio(false);
    int i,j,k;//循环变量
    int n,m;//输入的N个点，和M条边
    int x,y,z;//输入变量
    int min,minIndex;
    int sum=0;//记录最后的答案
    
    cin>>n>>m;

    //初始化maps，除了自己到自己是0其他都是边界值
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(i!=j)
                maps[i][j] = MAX;
            else
                maps[i][j] = 0;
        }
    }
            
    for (i = 1; i <= m; i++)
    {
        cin>>x>>y>>z;//输入的为无向图
        maps[x][y] = z;
        maps[y][x] = z;
    }

    //初始化距离数组，默认先把离1点最近的找出来放好
    for (i = 1; i <= n; i++)
        dis[i] = maps[1][i];

    book[1]=1;//记录1已经被访问过了

    for (i = 1; i <= n-1; i++)//1已经访问过了，所以循环n-1次
    {
        min = MAX;//对于最小值赋值，其实这里也应该对minIndex进行赋值，但是我们承认这个图一定有最小生成树而且不存在两条相同的边
        //寻找离树最近的点
        for (j = 1; j <= n; j++)
        {
            if(book[j] ==0 && dis[j] < min)
            {
                min = dis[j];
                minIndex = j;
            }
        }

        //记录这个点已经被访问过了
        book[minIndex] = 1;
        sum += dis[minIndex];

        for (j = 1; j <= n; j++)
        {
            //如果这点没有被访问过，而且这个点到任意一点的距离比现在到树的距离近那么更新
            if(book[j] == 0 && maps[minIndex][j] < dis[j])
                dis[j] = maps[minIndex][j];
        }
    }

    cout<<sum<<endl;
}
