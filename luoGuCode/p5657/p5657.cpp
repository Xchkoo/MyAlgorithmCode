#include<iostream>
#include<math.h>
#include<vector>
#define ull unsigned long long
using namespace std;
ull n,k,_cnt,number_digit,s;
vector<ull>ans;
void unearth()
{
	for(register ull i = 2;i<=number_digit;i*=2)
	{
	if((int)k > s+(_cnt/i))
	{
		s = _cnt/i;
		ans.push_back(1);
	}
	else
		ans.push_back(0);
	}
}
void _give()
{
	for(register ull i = n;i>0;i--)
		cout<<ans.back();
}
int main()
{
	cin >> n >> k;
	for(register ull i = 0;i<n;i++)
	{
		_cnt += (int)pow(double(2),i);//2^i
	}
	//a^0 = 1
	_cnt++;
	number_digit = n;
	unearth();
	_give();
	return 0;
}
