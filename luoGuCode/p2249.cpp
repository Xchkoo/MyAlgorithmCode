#include<iostream>
using namespace std;
#define MAXN 1000000+5

int a[MAXN],que[MAXN],n,m;

bool check(int x,int y)//check
{
	if(x <= y)	return 1;
	else return 0;
}

int main(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i =1;i <= m;i++){
		cin >> que[i];
	} 

//-------------------------one divides into two cut-------------------------------------------------------

	for(int i = 1;i <= m;i++){
		int minx = 1,maxx = n,mid;
		while( a[minx] < a[maxx]){
			mid = (minx +maxx)/2;
			if(check(a[mid],que[i]))	minx = mid;
			else	maxx = mid;
		cout<<"maxx="<<maxx<<"minx"<<minx<<"mid"<<mid<<endl;
		}
		if(a[minx] == que[i])
			cout<<a[minx]<<' ';
		else if(a[maxx] == que[i])
			cout<<a[maxx]<<' ';
		else 	
			cout<<"-1"<<endl;
	}
	return 0;
}

//amen god no bug :wq
