//单点修改，区间求和
#include<iostream>
#define N 1e5 + 5
long long n,m;
long long a[N<<2];
class SegementTree {
public:
//都递归，故用内联函数
    inline void build(int i,int l,int r){//递归建树 
    //i 是结点序数，l是左值，r是右值
        if(l == r){
            sum[i] = a[l];//k是序数
            return ;
        }
        auto mid = (l+r)>>1;
        build(i<<1,l,mid);
        build(i<<1|1,mid,r);
    }

    inline long long search(int i,int l,int r){
        if((i<<1) >= l && sum[])
    }
    inline void revise(){

    }
private:
    long long sum[N<<2];
    long long add[N<<2];//根据二叉树的性质，所需节点不超过2n+1
}t;


int main()  {
    std::ios::sync_with_stdio(false);

    std::cin >> n >> m; //数列数和操作数
    for(size_t i = 1;i != n + 1;i++)   
        std::cin >> a[i];
    t.build(1,1,n);
    for(size_t i = 1;i != m + 1;i++)  {
        int _operate;
        long long x,y;
        std::cin >> _operate >> x >> y; 
        if(_operate == 1)
            t.revise();
        if(_operate == 0)   {
            std::cout << t.search(1,x,y);
        }
    }
    return 0;
}
