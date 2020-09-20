#include<iostream>
using namespace std;
typedef long long ll;
#define MAX 100000
int num[MAX],_color[MAX];
int n,m;
ll value;
int main()
{
	cin >> n >> m;
	ll i,j;
	for(i = 1;i <= n;i++)
		cin >> num[i];
	for(i = 1;i <= n;i++)
		cin >>_color[i];

	for(i = 1; i <= n;i++)
		for(j = i + 1;j <= n;j++) 
			{
				if(i % 2 == j % 2)
				//it means they own qio
				{	
					if(_color[i] == _color[j])
					{
						value += (i + j)*(num[i] + num[j]);
						value = value % 10007;
					}
				}
			}
	cout << value <<endl;
	return 0;



}

