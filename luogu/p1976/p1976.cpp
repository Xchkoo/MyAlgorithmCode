nclude<iostream>
using namespace std;
typedef unsigned long long ull;
int i,j,k,n;
ull l[10000];
#define largeN 100000007
int main(){
	cin >> n;
	l[0] = 1;
	l[1] = 1;
	for(i=2;i<=n;i++)
		for(j=0;j<i;j++)
			l[i] = (l[j]*l[i-j-1]%largeN+l[i])%largeN;
		cout<<l[n];										return 0;										}
											//ctl[i] += ctl[j] * ctl[i - j - 1];
											//h(n)=C(2n,n)/(n+1)

