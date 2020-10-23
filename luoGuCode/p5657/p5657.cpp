#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int n,k,_cnt,number_digit;
vector<int>ans;
void unearth()
{
	for(int i = 2;i<=number_digit;i*=2)
	{
	if((int)k / (_cnt/i) >= 1)
		ans.push_back(1);
	else
		ans.push_back(0);
	}
}
void _give()
{
	for(int i = n;i>0;i--)
		cout<<ans.back();
}
int main()
{
	cin >> n >> k;
	for(int i = 0;i<n;i++)
	{
		_cnt += (int)pow(double(2),i);//2^i
	}
	//a^0 = 1
	number_digit = n;

	_cnt++;
	unearth();
	_give();
	return 0;
}
