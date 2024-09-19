#include<iostream>
const int N = 1e5 + 5;
int a[N];
class SegementTree
{
private:
    #define ls (k<<1)
    #define rs (k<<1|1)
    long long sum[N<<2];//值
    long long add[N<<2];//懒标记
    void pushup(int k){sum[k]=sum[ls]+sum[rs];}
    void pushdown(int k,int l,int r)
    {
        if(add[k]==0) return ;
        int mid=l+r>>1;
        sum[ls]+=(mid-l+1)*add[k],add[ls]+=add[k];
        sum[rs]+=(r-mid)*add[k],add[rs]+=add[k];
        add[k]=0;
    }
public:
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            sum[k]=a[l];
            return ;
        }
        int mid=(l+r)>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int x,int y,long long w)
    {
        if(r<x||l>y) return ;
        if(x<=l&&r<=y)
        {
            sum[k]+=(r-l+1)*w;
            add[k]+=w;
            return ;
        }
        pushdown(k,l,r);
        int mid=l+r>>1;
        update(ls,l,mid,x,y,w);
        update(rs,mid+1,r,x,y,w);
        pushup(k);
    }
    long long query(int k,int l,int r,int x,int y)
    {   
        if(r<x||l>y) return 0;
        if(x<=l&&r<=y) return sum[k];
        pushdown(k,l,r);
        int mid=l+r>>1;
        return query(ls,l,mid,x,y)+query(rs,mid+1,r,x,y);
    }
    #undef ls
    #undef rs
}t;
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    // scanf("%d%d",&n,&m);
    std::cin >> n >> m;
    for(int i=1;i<=n;i++)
        // scanf("%d",&a[i]);
        std::cin >> a[i];
    t.build(1,1,n);
    for(int i=1;i<=m;i++)
    {
        int op,x,y;
        // scanf("%d%d%d",&op,&x,&y);
        std::cin >> op >> x >> y;
        if(op==1)
        {
            long long z;
            std::cin >> z;
            // scanf("%lld",&z);
            t.update(1,1,n,x,y,z);
        }
        else 
            std::cout<<t.query(1,1,n,x,y);
    }
    return 0;
}
