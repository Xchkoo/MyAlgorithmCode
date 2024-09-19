#include<iostream>
#include<math.h>
#include<vector>
#define ull unsigned long long
using namespace std;
ull n,k,_cnt,number_digit,s = 0;
vector<ull>ans;
bool r = 0;

void unearth(int x,int y)
{
	if(s >= n)	return;
	int mid = (x + y)/2;
//	cout<<"mid= "<<mid<<endl;
	if(k >= mid)
	{
		if(r)
			ans.push_back(0);
		else
			ans.push_back(1);
		s++;
		r = 1;
		unearth(mid,y);
		
	}
	if(k < mid)
	{
		if(!r)
			ans.push_back(0);
		else
			ans.push_back(1);
		s++;
		r = 0;
		unearth(x,mid);
	}
}

ull _up(int n)
{
	for(register ull i = 0;i<n;i++)
	{
		_cnt += (int)pow(double(2),i);//2^i
	}
	return _cnt;
}

void _give()
{
	for(register ull i = 0;i<n;i++)
		cout<<ans[i];
}
int main()
{
	std::ios::sync_with_stdio(0);
	cin >> n >> k;
	_cnt = _up(n);
	//a^0 = 1
	_cnt++;
	unearth(0,_cnt);
	_give();
	return 0;
}


