#include<bits/stdc++.h>
using namespace std;
template<typename Type>inline void read(Type &xx)
{
    Type f=1;char ch;xx=0;
    for(ch=getchar();ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar())xx=xx*10+ch-'0';
    xx*=f;
}//这是一个快读的模板 
struct edge
{
    int to,next;
}e[1000001];//边的储存
struct questions
{
    int to,next,same,num;
    bool flag;
    questions(){flag=false;}
}q[1000001];//询问的储存，flag=false表示还没回答，num表示是第几个询问，same储存与这个询问相同的询问序号。
bool b[500001];
int head[500001],que[500001],father[500001];
int n,m,s,nume=0,numq=0,ans[500001];
void add_edge(int x,int y)
{
    e[++nume].to=y;
    e[nume].next=head[x];
    head[x]=nume;
    e[++nume].to=x;
    e[nume].next=head[y];
    head[y]=nume;
}
void add_que(int x,int y,int k)
{
    q[++numq].to=y;
    q[numq].same=numq+1;
    q[numq].next=que[x];
    q[numq].num=k;
    que[x]=numq;
    q[++numq].to=x;//询问要储存到两个点的链表序列里，删的时候也要一起删
    q[numq].same=numq-1;
    q[numq].next=que[y];
    q[numq].num=k;
    que[y]=numq;
}
int find(int x)//并查集
{
    if(father[x]!=x)father[x]=find(father[x]);
    return father[x];
}
void unionn(int x,int y)//并查集
{
    father[find(y)]=find(x);
}
void LCA(int point,int f)//point是当前搜索节点，f是它的父亲
{
    for(int i=head[point];i!=0;i=e[i].next)//遍历与point相连的所有边
        if(e[i].to!=f&&!b[e[i].to])
        {
            LCA(e[i].to,point);
            unionn(point,e[i].to);//合并
            b[e[i].to]=1;
        }
    for(int i=que[point];i!=0;i=q[i].next)//遍历与point相关的询问
        if(!q[i].flag&&b[q[i].to])//如果另一个点遍历过了并且该询问没有回答过
        {
            ans[q[i].num]=find(q[i].to);//记录下答案
            q[i].flag=1;
            q[q[i].same].flag=1;//把两个点上的询问都去掉
        }
}
int main()
{
    read(n);read(m);read(s);
    for(int i=1,x,y;i<=n-1;i++)
    {
        father[i]=i;
        read(x);read(y);
        add_edge(x,y);
    }
    father[n]=n;
    for(int i=1,x,y;i<=m;i++)
    {
        read(x);read(y);
        add_que(x,y,i);
    }
    LCA(s,0);
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
