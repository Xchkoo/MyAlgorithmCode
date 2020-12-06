#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 10000

int n,m,cnt,edgenum;
typedef long long ll;
int head[MAXN];
bool visit[MAXN];
bool check_out[MAXN];
struct Edge {
    int next;
    int to;
    Edge(){
        next = -1;
        to = -1;
    }
}edge[MAXN<<1];

class Fraction{
public:
    int denominator;
    int numerator;
    void simplify() {
        int ngcd = __gcd(this->denominator,this->numerator);
        this->denominator = this->denominator/ngcd;
        this->numerator = this ->numerator/ngcd;
    }
    Fraction operator+(const  Fraction& b){
        Fraction fra;
        fra.denominator = this->denominator * b.denominator;
        fra.numerator = \
        this->numerator * b.denominator + \
        b.numerator * this->denominator;
        return fra;
    }
    
    Fraction operator=(const Fraction& b)   {
        this->denominator = b.denominator;
        this->numerator = b.numerator;
    } 
    void AddFra(int x,int y)
    {
        this->numerator = x;
        this->denominator = y;
    }
}
headw[MAXN];

void Addnode(int __in,int __out){
    cnt++;
    edge[cnt].to = __out;
    edge[cnt].next = head[__in];
    head[__in] = cnt;
    edgenum++;
}

int Countson(int node){
    int sonNum = 0;
    int i;
    i = head[node];
    while(1){
        if(i == -1)
            break;
        i = edge[i].next;
        sonNum++;
    }
    return sonNum;
}//this func is ok

void dfs(int fa){
    visit[fa] = 1;
    for(int i = head[fa];i != -1;i = edge[i].next)
    {
        int v = edge[i].to;
        Fraction a,b;
        b = headw[v];
        a.AddFra(1,Countson(fa));
        headw[v] = a + b;
        if(visit[v] != 1)
            dfs(v);
    }
}
void Check_out()
{
    for(int i = 1;i<=edgenum;i++)
    {
        if(edge[i].to == -1)
            for(int j = 1;j<=n;j++)
                if(head[j] = i)
            check_out[j] = 1;
    }
}
int main()  {
    memset(head,-1,sizeof(head));
    memset(visit,-1,sizeof(visit));
    std::ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   {
        int a,b;
        cin >> a;
        if(a == 0)
            continue;
        for(int j = 1;j <= a;j++)   {
            cin >> b;
            Addnode(1,b);
        }
    }//add
    dfs(1);
    Check_out();
    for(int i = 0;i<=n;i++)
    {
        if(check_out[i] == 1)
        headw[i].simplify();
        cout << headw[i].numerator << " " << headw[i].denominator<<endl;
    }
    return 0;
}

