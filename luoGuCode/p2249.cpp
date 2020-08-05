#include<iostream>
using namespace std;
#define MAXN 1000000+5


int a[MAXN],que[MAXN],n,m;


bool check(int x,int y)//查找 
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
//	for(int i = 1;i <= n;i++){
//		cout<<a[i]; 
//	}
//	for(int i =1;i <= m;i++){
//		cout << que[i];
//	} 	

//-------------------------二分-------------------------------------------------------

	for(int i = 1;i <= m;i++){
		int minx = 1,maxx = n,mid;
		while( a[minx] < a[maxx - 1]){
			mid = a[(minx +maxx)/2 - 1];
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

//佛祖保佑，永无bug 
