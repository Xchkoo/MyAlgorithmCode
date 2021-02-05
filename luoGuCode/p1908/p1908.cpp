#include<iostream>
#define N 500010
using namespace std;
int n;
int o[N];//Main
int tem[N];//Temporary
long long ans;

void msort(int b,int e)// b = begin e = end
{
    if(b == e)
		return;
    int mid=(b+e)/2,i=b,j=mid+1,k=b;
    msort(b,mid),msort(mid+1,e);
    while(i <= mid&&j <= e)
    	if(o[i]<=o[j])
    		tem[k++]=o[i++];
    	else
    		tem[k++]=o[j++],ans+=mid-i+1;//count answer
    while(i<=mid)
    	tem[k++]=o[i++];
    while(j<=e)
    	tem[k++]=o[j++];
    for(int l=b;l<=e;l++)
    	o[l]=tem[l];
}           

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> o[i];
    }
    msort(1,n);
    cout << ans;
    return 0;
}
