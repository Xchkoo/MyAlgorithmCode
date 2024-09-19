#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int maxm = 99999997;
struct MyStruct
{
    int data;
    int loc;
}a[maxn],b[maxn];
int e[maxn], n, c[maxn];
int inline readint()
{
    int x = 0;
    char c = getchar();
    while (c<'0' || c>'9') c = getchar();
    while (c >= '0'&&c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int lowbit(int x)
{
    return x&-x;//树状数组实现 
}
void add(int x,int t)
{
    while (x <= n)
    {
        e[x] += t;
        e[x] %= maxm;
        x += lowbit(x);//每次往后加，可以改变后面对应的和 
    }
}
int sum(int x)
{
    int s = 0;
    while(x)
    {
        s += e[x];
        s %= maxm;
        x -= lowbit(x);//得到所求的和 
    }
    return s;
}
bool cmp(MyStruct x, MyStruct y)
{
    return x.data < y.data;
}
int main()
{
    n = readint();
    for (int i = 1; i <= n; i++)
    {
        a[i].data = readint();
        a[i].loc = i;//记录位置 
    }
    for (int i = 1; i <= n; i++)
    {
        b[i].data = readint();
        b[i].loc = i;
    }
    sort(a + 1, a + n + 1, cmp);
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        c[a[i].loc] = b[i].loc;//离散优化 
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(c[i], 1);//离散优化后大小就是正确顺序的位置 
        ans += i - sum(c[i]);//当前位置，减去之前比他大的数的个数  
        ans %= maxm;
    }
    printf("%d", ans);
    return 0;
}